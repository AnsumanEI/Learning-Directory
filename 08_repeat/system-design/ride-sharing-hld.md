# Ride-Sharing System — High Level Design

---

## 1. Requirements

### Functional Requirements

**Rider:**
- Request, modify, and cancel a ride
- Real-time tracking of driver location while driver is en route and during the trip
- View ride history
- Payment on trip completion

**Driver:**
- Go online/offline (availability status)
- Accept or reject ride requests
- Update trip status (started, completed)
- Continuous location broadcasting while active

**System:**
- Match rider to nearest available driver
- Send push notifications (ride accepted, driver arrived, trip completed)
- Process payment on trip completion

---

### Non-Functional Requirements

| Metric | Target |
|---|---|
| Riders | 10 million |
| Active drivers (peak) | 1 million |
| Concurrent rides (peak) | 500,000 |
| Location updates | ~250,000 writes/sec (500k drivers × 1 update/2s) |
| New ride requests | ~417/sec (500k rides / 20 min avg) |
| Availability | 99.99% |
| Location update latency | < 200ms end to end |
| Ride match latency | < 5s from request to driver notification |
| Storage | ~2 TB/year (trip records at 500 bytes × 10M trips/day) |

---

## 2. Data Models

### Rider
```
rider_id        UUID        Primary key
name            VARCHAR
surname         VARCHAR
email           VARCHAR     Unique
phone           VARCHAR
dob             DATE
rating          FLOAT       Avg rating from drivers
payment_method  VARCHAR     Type: cash / card / upi
payment_token   VARCHAR     Token from payment gateway (never raw card number)
created_at      TIMESTAMP
```

### Driver
```
driver_id       UUID        Primary key
name            VARCHAR
surname         VARCHAR
email           VARCHAR     Unique
phone           VARCHAR
dob             DATE
rating          FLOAT       Avg rating from riders
status          ENUM        available / on_trip / offline
geohash_cell    VARCHAR     Grid cell ID for matching (e.g. S2 cell token)
created_at      TIMESTAMP
```

### Vehicle (separate table, linked to driver)
```
vehicle_id      UUID        Primary key
driver_id       UUID        Foreign key → Driver
make            VARCHAR
model           VARCHAR
year            INT
license_plate   VARCHAR     Unique
color           VARCHAR
```

### Trip
```
trip_id         UUID        Primary key
rider_id        UUID        Foreign key → Rider
driver_id       UUID        Foreign key → Driver
status          ENUM        requested / accepted / in_progress / completed / cancelled
pickup_lat      FLOAT
pickup_lng      FLOAT
dropoff_lat     FLOAT
dropoff_lng     FLOAT
distance_km     FLOAT       Actual distance travelled
fare            DECIMAL
payment_method  VARCHAR
requested_at    TIMESTAMP
started_at      TIMESTAMP
completed_at    TIMESTAMP
```

### Driver Location (Redis — not a DB table)
```
Key:   driver:location:{driver_id}
Value: { lat, lng, speed, timestamp }
TTL:   30 seconds (auto-expires if driver goes offline)
```

Redis Geo Index (for matching):
```
GEOADD  drivers {lng} {lat} {driver_id}     → add/update driver position
GEORADIUS drivers {rider_lng} {rider_lat} 5 km  → find nearby drivers
```

---

## 3. Component Architecture

```
Rider App / Driver App
        |
   [ Load Balancer ]
        |
   [ API Gateway ]         ← Auth, rate limiting, routing
        |
  ┌─────┴──────────────────────────────────┐
  |             |              |            |
Ride         Location       Trip        Payment
Request      Service        Service     Service
Service          |              |
  |          [ Redis ]     [ PostgreSQL ]
  |          - driver locations (geo index)
  |          - session cache
  |
[ Kafka ]                        ← ride events, location events
  |
Matching
Service
  |
Notification
Service          ← RabbitMQ → FCM / APNs / SMS
  |
WebSocket
Service          ← pushes driver location to rider app
```

**Component responsibilities:**

| Component | Responsibility |
|---|---|
| API Gateway | Auth, rate limiting, routes requests to correct service |
| Ride Request Service | Accepts ride requests, publishes to Kafka |
| Matching Service | Consumes Kafka, queries Redis GEORADIUS, assigns nearest driver |
| Location Service | Receives driver GPS pings, writes to Redis, pushes via WebSocket |
| Trip Service | Manages trip lifecycle, writes to PostgreSQL |
| Notification Service | Sends push notifications via RabbitMQ → FCM/APNs |
| WebSocket Service | Maintains persistent connections, streams location to rider |
| Payment Service | Triggered via RabbitMQ on trip completion, processes fare |
| Redis | Driver locations (geo index), session cache, ephemeral data |
| PostgreSQL | Riders, drivers, vehicles, trips — persistent relational data |
| Kafka | High volume event streaming — ride requests, trip events |
| RabbitMQ | Task queues — payments, notifications, driver acceptance |

**Why Kafka and not RabbitMQ for ride requests?**
Kafka is append-only with replay capability. If the Matching Service crashes mid-request, it can replay from its last offset. For 417 ride requests/sec at peak, durability matters. RabbitMQ is used for confirmational tasks (payment, notifications) that need complex routing and DLQ support.

**Why PostgreSQL and not MySQL?**
PostgreSQL has native geospatial support via the PostGIS extension — pickup/dropoff coordinates can be stored and queried natively. Better concurrency under high write load. Uber used PostgreSQL in early architecture before moving to custom solutions.

**Why Redis and not Cassandra for location?**
Location updates only require the latest value — overwrite on every ping. Redis GET/SET is O(1) sub-millisecond. Cassandra is optimised for write-heavy time-series history. Overkill when you only ever need the current position.

---

## 4. API Design

### Rider Endpoints

```
POST   /rides
Body:  { rider_id, pickup_lat, pickup_lng, dropoff_lat, dropoff_lng, payment_method }
→ Creates ride request. Driver ID assigned by Matching Service, not by rider.

PATCH  /rides/{trip_id}
Body:  { status: "cancelled" } or { pickup_lat, pickup_lng, dropoff_lat, dropoff_lng }
→ Modify or cancel a ride.

POST   /payments/{trip_id}
Body:  { rider_id, payment_token }
→ Trigger payment on completion.

GET    /rides/history?rider_id={rider_id}
→ Fetch past trips for rider.

WebSocket   /ws/riders/{rider_id}/location
→ Receives real-time driver location pushes from WebSocket Service.
```

### Driver Endpoints

```
PATCH  /drivers/{driver_id}/status
Body:  { status: "available" | "offline" }
→ Driver goes online or offline.

PATCH  /rides/{trip_id}
Body:  { status: "accepted" | "started" | "completed" }
→ Driver updates trip lifecycle status.

WebSocket   /ws/drivers/{driver_id}/location
Body (continuous stream): { lat, lng, speed, timestamp }
→ Driver app streams GPS to Location Service every 2 seconds.
```

**Note:** Both rider and driver use `PATCH /rides/{trip_id}` — same resource, different permitted fields enforced by API Gateway auth. Driver cannot cancel. Rider cannot mark as completed.

---

## 5. End-to-End Flow — Ride Request

```
1.  Rider taps "Request Ride"
        → POST /rides hits API Gateway (auth + rate limit check)
        → Ride Request Service publishes ride_requested event to Kafka

2.  Matching Service consumes from Kafka
        → Calls GEORADIUS on Redis → gets list of nearby available drivers
        → Applies geohash cell filter to narrow candidates
        → Picks nearest available driver

3.  Notification Service (via RabbitMQ)
        → Push notification to driver app via FCM/APNs: "New ride request"

4.  Driver accepts
        → PATCH /rides/{trip_id} { status: "accepted" }
        → Trip Service creates trip record in PostgreSQL (status = accepted)
        → Notification Service → push to rider: "Driver is on the way"

5.  WebSocket Service starts pushing driver location to rider
        → Driver app → POST location every 2s → Location Service → writes to Redis
        → Location Service → pushes lat/lng to rider via WebSocket connection

6.  Driver arrives. Rider boards.
        → Driver → PATCH /rides/{trip_id} { status: "started" }
        → Trip Service updates PostgreSQL (status = in_progress, started_at = now)

7.  Trip completes.
        → Driver → PATCH /rides/{trip_id} { status: "completed" }
        → Trip Service updates PostgreSQL (status = completed, completed_at = now)
        → WebSocket connection closes

8.  Payment triggered
        → Trip Service publishes trip_completed event to RabbitMQ
        → Payment Service consumes → processes fare → updates trip record (fare, payment status)
        → Notification Service → receipt push to both rider and driver
```

---

## 6. Scaling

### Location Updates — 250,000 writes/sec

- **Redis Cluster** — 16,384 hash slots distributed across nodes. Each driver location key hashes to a slot handled by one node. Horizontally scalable. Add nodes as driver count grows.
- **Geohashing (S2 geometry)** — map divided into grid cells. Each driver assigned a cell ID (stored in driver DB). Matching Service queries only nearby cells instead of scanning all drivers. Same approach used by Uber (S2) and Google Maps.
- **Load Balancer** in front of Location Service — distributes incoming GPS pings across multiple Location Service instances.

### Matching Service

- Stateless — can run multiple instances behind load balancer
- All state is in Redis (geo index) and Kafka (event queue)
- Scale horizontally — add instances as ride request volume grows
- Kafka consumer group — multiple Matching Service instances share the partition load

### PostgreSQL — High Availability

- **Master-Replica setup** — all writes go to master, read replicas handle ride history and profile queries
- **Automatic failover** via Patroni — if master goes down, replica promotes to master automatically
- **Read replicas** reduce load on master during peak — history queries, driver/rider profile reads
- **Connection pooling** via PgBouncer — prevents connection exhaustion under high concurrency

### API Gateway

- Rate limiting — leaky bucket per rider/driver to prevent request floods
- Auth at gateway level — JWT verification, no network call to auth service per request during spikes
- Single entry point — routes to correct downstream service

### WebSocket Service

- Sticky sessions not needed — WebSocket connections are stateful per connection, not per user session
- Scale horizontally with a pub/sub layer (Redis pub/sub) — Location Service publishes update, WebSocket Service for that rider's connection consumes it

---

*Document written: June 11, 2026 — W12 D7*
*Push to: `08_repeat/system-design/ride-sharing-hld.md`*