# Backend Engineering — Complete Flow Guide
> Phase 1 · Everything you've built, why it matters, and what you must remember

---

## The mental model — burn this in first

Before anything else, understand this one thing:

**A backend is just a program that waits for requests and responds.**

That's it. Everything else — databases, auth, Docker — is detail on top of this.

```
Client (curl / browser / C++ app / IoT device)
    ↓  sends HTTP request
Server (your FastAPI app)
    ↓  your function runs
    ↓  maybe talks to a database
    ↑  sends HTTP response back
Client receives it
```

Every single project you've built follows this flow. The TCP server did it raw. FastAPI does it with nice syntax on top.

---

## Section 1 — The network stack (what happens before your code even runs)

When a request arrives at your server, it has already traveled through layers:

```
Application layer   →  HTTP  (the message: GET /users, headers, body)
Transport layer     →  TCP   (reliable delivery, ordering, retransmit)
Internet layer      →  IP    (routing packets across networks)
Physical layer      →  Ethernet/WiFi (actual bits on wire)
```

**What you must remember:**
- HTTP runs ON TOP of TCP. TCP is the pipe. HTTP is the message format inside the pipe.
- TCP guarantees delivery. UDP does not (faster but lossy — used in video calls, games).
- A TCP connection starts with a 3-way handshake: SYN → SYN-ACK → ACK.
- Every HTTP request is a new message. TCP connection may be reused (keep-alive).
- Port 80 = HTTP. Port 443 = HTTPS. Port 22 = SSH. Port 8000 = your local FastAPI.

**IoT connection:** Your C++ device simulator will eventually publish over MQTT (port 8883 with TLS). MQTT also runs on TCP. Same stack — different application protocol.

---

## Section 2 — HTTP request anatomy

Every HTTP request has three parts:

```
METHOD /path HTTP/1.1          ← request line
Host: localhost:8000           ← headers
Content-Type: application/json ←
X-API-Key: secret123           ← custom header (your auth)
                               ← blank line separates headers from body
{"name": "Arun"}               ← body (POST/PUT only)
```

Every HTTP response has three parts:

```
HTTP/1.1 200 OK                ← status line
Content-Type: application/json ← response headers

{"id": 1, "name": "Arun"}      ← response body
```

**What you must remember:**
- GET has no body. POST/PUT have a body.
- Headers are key-value pairs. You can add custom ones (X-API-Key).
- Status codes are your contract with the caller — use them correctly.
- FastAPI reads `Header()`, `Query()`, and `Body()` differently — know which you're using.

### Status codes — the ones that matter

| Code | Name | When to use |
|------|------|-------------|
| 200 | OK | Request succeeded, here's your data |
| 201 | Created | POST succeeded, new resource created |
| 400 | Bad Request | Client sent malformed data |
| 401 | Unauthorized | Who are you? No valid credentials |
| 403 | Forbidden | I know who you are, but no |
| 404 | Not Found | Resource doesn't exist |
| 422 | Unprocessable | FastAPI validation failed (missing field, wrong type) |
| 500 | Internal Server Error | Your code crashed |

**Memory trick:** 4xx = client's fault. 5xx = server's fault.

---

## Section 3 — FastAPI patterns (everything you've used)

### 3.1 Basic structure

```python
from fastapi import FastAPI
app = FastAPI()

@app.get("/hello")        # decorator registers the route
def hello():              # function runs when route is hit
    return {"message": "hello"}   # dict → auto-converted to JSON
```

FastAPI handles: routing, JSON serialisation, auto /docs, validation errors.
You handle: your logic.

### 3.2 Reading input — three ways

```python
# 1. Path parameter — part of the URL
@app.get("/users/{user_id}")
def get_user(user_id: int):     # FastAPI converts "1" string → int for you
    pass

# 2. Query parameter — after the ?
@app.get("/users")
def list_users(limit: int = 10):  # /users?limit=5
    pass

# 3. Request body — JSON sent with POST
from pydantic import BaseModel

class UserCreate(BaseModel):
    name: str
    email: str

@app.post("/users")
def create_user(user: UserCreate):  # FastAPI parses JSON into this object
    pass
```

**What you must remember:**
- Path params: `/users/{id}` — variable is part of URL
- Query params: `?key=value` — optional filters, pagination
- Body: JSON payload — only on POST/PUT, use Pydantic model
- Pydantic validates automatically — wrong type = 422 response

### 3.3 Returning errors

```python
from fastapi import HTTPException

# Use this everywhere you want to return an error
raise HTTPException(status_code=404, detail="User not found")
raise HTTPException(status_code=401, detail="Invalid credentials")
```

Once you raise this, FastAPI stops execution and sends the error response. Code after it does not run.

### 3.4 Reading headers

```python
from fastapi import Header

def get_users(x_api_key: str = Header()):
    # FastAPI reads X-API-Key header, converts hyphens to underscores
    pass
```

---

## Section 4 — SQLite + SQLAlchemy (making data persist)

### Why a database?

Your in-memory KV store (Week 1) loses all data on restart. A database writes to disk — data survives restarts, crashes, deployments.

### The three things you need every time

```python
# 1. Engine — the connection to the database file
engine = create_engine("sqlite:///./myapp.db")

# 2. Base + Model — defines your table structure
class User(Base):
    __tablename__ = "users"
    id = Column(Integer, primary_key=True)
    name = Column(String)
    email = Column(String)

Base.metadata.create_all(bind=engine)  # creates the table if it doesn't exist

# 3. Session — one session per request, like a transaction
db = SessionLocal()
```

### The four database operations (CRUD)

```python
# Create
new_user = User(name="Arun", email="arun@email.com")
db.add(new_user)
db.commit()
db.refresh(new_user)  # get the auto-generated id back

# Read all
users = db.query(User).all()

# Read one
user = db.query(User).filter(User.id == 1).first()
if not user:
    raise HTTPException(status_code=404, detail="Not found")

# Delete
db.delete(user)
db.commit()
```

**What you must remember:**
- `add()` → stages the insert. `commit()` → actually writes to disk.
- Always `refresh()` after insert if you need the auto-generated id.
- `filter().first()` returns None if not found — always check for None.
- `db.close()` at the end — don't leave connections open.
- Common mistake: `VALUE` instead of `VALUES` in raw SQL. Use SQLAlchemy to avoid this.

---

## Section 5 — Auth (proving who you are)

### 5.1 API Key — simple gate

```
Client                          Server
  |                               |
  |-- GET /users ---------------→ |
  |   X-API-Key: secret123        |
  |                               | check: does key match?
  |                               | yes → proceed
  |← 200 OK + data -------------- |
  |                               |
  |-- GET /users ---------------→ |
  |   X-API-Key: wrongkey         |
  |                               | check: does key match?
  |                               | no → raise 401
  |← 401 Unauthorized ----------- |
```

Best for: devices, server-to-server, simple APIs.

### 5.2 JWT — signed token

```
Client                          Server
  |                               |
  |-- POST /login --------------→ |
  |   username + password         |
  |                               | verify credentials
  |                               | generate JWT (sign with SECRET_KEY)
  |← 200 OK + {token: "xxx.yyy.zzz"} --|
  |                               |
  |   (stores token)              |
  |                               |
  |-- GET /protected -----------→ |
  |   token=xxx.yyy.zzz           |
  |                               | jwt.decode() → verify signature
  |                               | extract username from payload
  |← 200 OK + protected data ---- |
```

Best for: users, sessions, mobile apps, dashboards.

### JWT structure — three parts separated by dots

```
eyJhbGciOiJIUzI1NiJ9   .   eyJzdWIiOiJhZG1pbiJ9   .   SflKxwRJSMeKKF2QT4
      HEADER                      PAYLOAD                   SIGNATURE

Header:    {"alg": "HS256"}
Payload:   {"sub": "admin", "exp": 1234567890}
Signature: HMAC(header + payload, SECRET_KEY)
```

**Why tampering fails:** Signature = hash of (header + payload + secret). Change anything in header or payload → signature no longer matches → `JWTError` → 401.

### What you must remember

| | API Key | JWT |
|---|---|---|
| Where sent | `X-API-Key` header | Query param or `Authorization` header |
| Server lookup | Yes (compare to stored key) | No (verify signature mathematically) |
| Expiry | Manual (you revoke it) | Built in (`exp` field) |
| Best for | Devices, services | Users, sessions |
| Stateless | No | Yes |

- 401 = not authenticated (I don't know who you are)
- 403 = not authorized (I know you, but you can't do this)
- `sub` field = subject = who the token belongs to (usually username)
- Never hardcode `SECRET_KEY` in production — use environment variables

---

## Section 6 — TCP server (what FastAPI hides from you)

Your C++ TCP server showed you what every server does underneath:

```cpp
// 1. Create a socket (like a phone that can receive calls)
int server_fd = socket(AF_INET, SOCK_STREAM, 0);

// 2. Bind to a port (say "I'm listening on port 8000")
bind(server_fd, (sockaddr*)&address, sizeof(address));

// 3. Listen for incoming connections
listen(server_fd, 3);

// 4. Accept a connection (pick up the phone when it rings)
int client_fd = accept(server_fd, nullptr, nullptr);

// 5. Read and write
read(client_fd, buffer, 1024);
write(client_fd, response, length);
```

FastAPI's `uvicorn` does steps 1-5 for you. Your `@app.get("/hello")` is just step 5.

**Why threads?** `accept()` blocks. While you're handling client A, client B is waiting. `std::thread` lets you handle both at the same time. FastAPI uses async (same idea, different mechanism).

**Why this matters for interviews:** When asked "what happens when a request hits your server", you can describe it at the TCP level — not just "FastAPI handles it". That's senior-level thinking at junior-level stage.

---

## Section 7 — libcurl (C++ talking HTTP)

Your C++ device simulator will eventually talk to a server. libcurl is how C++ speaks HTTP:

```cpp
CURL* curl = curl_easy_init();
curl_easy_setopt(curl, CURLOPT_URL, "http://localhost:8000/users");
curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
curl_easy_perform(curl);   // actually makes the request
curl_easy_cleanup(curl);
```

**What you must remember:**
- `curl_easy_init()` → create a handle
- `curl_easy_setopt()` → configure (URL, headers, POST body, callbacks)
- `curl_easy_perform()` → execute
- `curl_easy_cleanup()` → always clean up
- Response body comes through the `WriteCallback` — you define it

---

## Section 8 — The venv problem (never forget this)

Python packages installed system-wide conflict with each other. A virtual environment isolates your project's dependencies.

```bash
# Create
python3 -m venv venv

# Activate (do this every time before running your app)
source venv/bin/activate

# You'll see (venv) at the start of your terminal line

# Install packages (only affects this venv)
pip install fastapi uvicorn sqlalchemy python-jose passlib

# Run your app (always inside activated venv)
python3 -m uvicorn main:app --reload

# Deactivate when done
deactivate
```

**Rule:** If you see `ModuleNotFoundError`, the venv is not activated. Always check for `(venv)` in your terminal prompt first.

---

## Section 9 — Things you got wrong (learn from them)

These are the exact mistakes from your sessions. Read this before every backend session.

| Mistake | What went wrong | The fix |
|---------|----------------|---------|
| `VALUE` instead of `VALUES` in SQL | Typo kills the query | Use SQLAlchemy — no raw SQL |
| jose module not found | venv not activated | Always check for `(venv)` in prompt |
| Indentation error in function | Python uses indentation as syntax | 4 spaces inside every function, always |
| 401 vs 403 confused | 401 = unknown, 403 = known-but-blocked | 4**0**1 = identity unknown, 4**0**3 = access blocked |
| `iss >> value` twice in TCP server | Extracting from stream consumes it | Extract once, store in variable |
| `Content-Type` missing on POST | Server doesn't know how to parse body | Always add `-H "Content-Type: application/json"` in curl |

---

## Section 10 — curl commands you'll use forever

```bash
# GET request
curl http://localhost:8000/users

# GET with header
curl http://localhost:8000/users -H "X-API-Key: secret123"

# POST with JSON body
curl -X POST http://localhost:8000/users \
     -H "Content-Type: application/json" \
     -d '{"name": "Arun", "email": "arun@test.com"}'

# POST with query params
curl -X POST "http://localhost:8000/login?username=admin&password=password123"

# GET with JWT token
curl "http://localhost:8000/protected?token=YOUR_TOKEN_HERE"

# See full response headers
curl -v http://localhost:8000/users

# Pretty print JSON response
curl http://localhost:8000/users | python3 -m json.tool
```

---

## The big picture — where all of this leads

```
Phase 1 (now)
  HTTP + TCP + FastAPI + SQLite + Auth
         ↓
Phase 2
  Docker (package your app) → Kubernetes (run at scale) → AWS (run in cloud)
         ↓
Phase 3
  Kafka (handle device streams) → TimescaleDB (store time-series data)
         ↓
Phase 4
  Your IoT platform: C++ device → MQTT → AWS IoT Core → Kafka → DB → API → Dashboard
```

Every backend concept you're learning now is a brick in that final system. JWT auth will protect your device dashboard. SQLite patterns will become TimescaleDB queries. FastAPI will become your production query layer.

---

## Quick reference card

```
Start server:     source venv/bin/activate && python3 -m uvicorn main:app --reload
Test server:      curl http://localhost:8000/docs  (interactive API docs)
GET all:          curl http://localhost:8000/users -H "X-API-Key: secret123"
POST create:      curl -X POST http://localhost:8000/users -H "Content-Type: application/json" -H "X-API-Key: secret123" -d '{"name":"X","email":"x@x.com"}'
Get JWT:          curl -X POST "http://localhost:8000/login?username=admin&password=password123"
Use JWT:          curl "http://localhost:8000/protected?token=PASTE_TOKEN"
TCP server:       cd week3/tcp-server && g++ server.cpp -o server -lpthread && ./server
Connect to TCP:   nc localhost 8000
```