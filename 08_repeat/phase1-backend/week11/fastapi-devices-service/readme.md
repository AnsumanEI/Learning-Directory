# fastapi-devices-service

## What is this?

Phase 1 capstone project — a production-style IoT device management API built with FastAPI. Users register and login to get a JWT token, after which they can manage devices. Device creation triggers a background caching task via Celery and RabbitMQ, and all GET requests use Redis lazy-loading for fast responses.

---

## Architecture

| Component | Role |
|---|---|
| **FastAPI** | REST API layer, JWT auth, rate limiting |
| **PostgreSQL** | Persistent storage for users and devices |
| **Redis** | Caching layer — lazy loading on GET, Celery task results |
| **RabbitMQ** | Message broker between FastAPI and Celery worker |
| **Celery** | Background worker that caches new devices in Redis after creation |

---

## Flow

```
POST /devices → save to DB → cache_device.delay() → RabbitMQ → Celery worker → Redis

GET /devices/{id} → check Redis
                         ↓
                   hit: return cache
                   miss: fetch DB → write to Redis → return
```

---

## What's new vs the SQLite project?

- PostgreSQL instead of SQLite — production database
- Redis caching with TTL — lazy loading pattern
- Celery + RabbitMQ — async background tasks
- SlowAPI rate limiting backed by Redis
- Proper project structure with routers, schemas, auth split into separate files
- Docker Compose orchestrating 5 services together

---

## How files connect

```
main.py
  └── includes routers/users.py
  └── includes routers/devices.py

routers/
  └── imports from auth.py, models.py, schemas.py, database.py, redis_client.py, tasks.py

tasks.py
  └── imports celery_app.py + redis_client.py

celery_app.py
  └── broker: RabbitMQ (amqp://rabbitmq:5672)
  └── backend: Redis (redis://redis:6379)
```

---

## Running the project

```bash
# Copy env file and fill in values
cp .env.example .env

# Start all services
docker compose up --build
```

| URL | What |
|---|---|
| http://localhost:8000 | API |
| http://localhost:8000/docs | Swagger UI |
| http://localhost:15672 | RabbitMQ UI (guest/guest) |

---

## API Endpoints

### Auth

```bash
# Register
curl -X POST http://localhost:8000/users/register \
  -H "Content-Type: application/json" \
  -d '{"username": "john", "password": "secret", "role": "admin"}'

# Login — copy the access_token from response
curl -X POST http://localhost:8000/users/login \
  -H "Content-Type: application/json" \
  -d '{"username": "john", "password": "secret"}'
```

### Devices (requires Bearer token)

```bash
# Create device
curl -X POST http://localhost:8000/devices \
  -H "Content-Type: application/json" \
  -H "Authorization: Bearer <token>" \
  -d '{"model_name": "TempSensor", "model_no": "TS001", "dev_status": "active"}'

# Get all devices (paginated)
curl "http://localhost:8000/devices?page=1&limit=10" \
  -H "Authorization: Bearer <token>"

# Get device by ID (Redis cached)
curl http://localhost:8000/devices/1 \
  -H "Authorization: Bearer <token>"

# Update device
curl -X PUT http://localhost:8000/devices/1 \
  -H "Content-Type: application/json" \
  -H "Authorization: Bearer <token>" \
  -d '{"model_name": "TempSensor", "model_no": "TS001", "dev_status": "inactive"}'

# Delete device
curl -X DELETE http://localhost:8000/devices/1 \
  -H "Authorization: Bearer <token>"
```

---

## Useful Docker commands

```bash
# Check Redis cache
docker exec -it fastapi-devices-service-redis-1 redis-cli
> keys *
> get device:1
> ttl device:1

# View logs
docker logs fastapi-devices-service-web-1
docker logs fastapi-devices-service-celery_worker-1

# Stop all services
docker compose down

# Stop and remove volumes (clears DB)
docker compose down -v
```