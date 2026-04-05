# 07 — FastAPI & Backend
> Topics: Endpoints · Query Params · Pydantic · SQLite · Auth (coming Tue Apr 7)  
> Language: Python (syntax errors expected — focus on system understanding)  
> Run: `python3 -m uvicorn main:app --reload`

---

## 🧠 The Big Idea

FastAPI is a Python web framework. You define functions, decorate them with HTTP methods and paths, and FastAPI handles the routing, validation, and documentation automatically.

**Analogy:** A restaurant. FastAPI is the front-of-house — it takes orders (HTTP requests), validates them ("sorry, we don't serve that"), and routes them to the right kitchen function. You just write the kitchen functions.

---

## Week 1 — Basic Endpoints

### Location
```bash
cd ~/Learning-Directory/08_repeat/phase1-backend/week1/fastapi-intro/
python3 -m uvicorn main:app --reload
```

### Endpoints built

```python
from fastapi import FastAPI, HTTPException
from pydantic import BaseModel

app = FastAPI()

# GET /hello
@app.get("/hello")
def hello():
    return {"message": "Hello World"}

# POST /echo — with request body
class EchoBody(BaseModel):
    text: str

@app.post("/echo")
def echo(body: EchoBody):
    return {"echo": body.text}

# GET /items/{item_id} — path parameter
@app.get("/items/{item_id}")
def get_item(item_id: int):
    return {"item_id": item_id}

# GET /items?limit=5 — query parameter
@app.get("/items")
def list_items(limit: int = 10):
    return {"limit": limit}
```

### Key concepts

| Concept | What it does |
|---|---|
| `@app.get("/path")` | Registers a GET endpoint at that path |
| `@app.post("/path")` | Registers a POST endpoint |
| `{item_id}` in path | Path parameter — extracted from URL |
| `limit: int = 10` in function | Query parameter with default value |
| `BaseModel` | Pydantic model — validates request body automatically |
| `HTTPException(404)` | Returns HTTP 404 with a message |

### Test with curl

```bash
curl http://localhost:8000/hello
curl -X POST http://localhost:8000/echo -H "Content-Type: application/json" -d '{"text":"hi"}'
curl http://localhost:8000/items/5
curl "http://localhost:8000/items?limit=3"
```

### Auto docs
FastAPI generates interactive docs automatically:
```
http://localhost:8000/docs    ← Swagger UI
http://localhost:8000/redoc   ← ReDoc
```

---

## Week 2 — FastAPI + SQLite

### Location
```bash
cd ~/Learning-Directory/08_repeat/phase1-backend/week2/fastapi-sqlite/
python3 -m uvicorn main:app --reload
```

### The flow — POST /users

```
Client sends: {"name": "Arun", "email": "arun@email.com"}
         ↓
FastAPI validates with Pydantic
         ↓
sqlite3.connect("users.db") → get connection
         ↓
cursor.execute("INSERT INTO users ...", (name, email))
         ↓
conn.commit() → save to disk
         ↓
return {"id": cursor.lastrowid, "name": name}
```

### Key SQLite concepts

```python
import sqlite3

conn = sqlite3.connect("users.db")
cursor = conn.cursor()

# Create table (only if it doesn't exist)
cursor.execute("""
    CREATE TABLE IF NOT EXISTS users (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        name TEXT NOT NULL,
        email TEXT NOT NULL
    )
""")

# Insert — use ? placeholders, NEVER string format (SQL injection risk)
cursor.execute("INSERT INTO users (name, email) VALUES (?, ?)", (name, email))
conn.commit()
last_id = cursor.lastrowid  # ID of the row just inserted

# Fetch all
cursor.execute("SELECT * FROM users")
rows = cursor.fetchall()  # list of tuples

conn.close()
```

### Why `?` placeholders?

Never do this:
```python
cursor.execute(f"INSERT INTO users VALUES ({name})")  # ❌ SQL injection
```

Always do this:
```python
cursor.execute("INSERT INTO users VALUES (?)", (name,))  # ✅ safe
```

### Key SQLite words

| Keyword | What it does |
|---|---|
| `CREATE TABLE IF NOT EXISTS` | Only creates if table doesn't exist yet |
| `AUTOINCREMENT` | ID assigned automatically, always increases |
| `NOT NULL` | Column can't be empty |
| `commit()` | Save changes to disk |
| `fetchall()` | Returns all rows as list of tuples |
| `lastrowid` | ID of the last inserted row |

⚠️ **Struggle:** Wrote `VALUE` instead of `VALUES` → SQL syntax error. It's always `VALUES`.

---

## Coming — Week 3 Backend (Tue Apr 7)

### REST Auth — API Keys + JWT

**API Key:** Simple. Client sends a secret key in the header. Server checks it.
```
Header: X-API-Key: mysecretkey123
```

**JWT (JSON Web Token):** More powerful. Server issues a token on login. Client sends it with every request. Server verifies it without hitting the database.

```
JWT structure: header.payload.signature
               ──────.───────.─────────
               base64.base64.hash
```

- **Header:** algorithm used
- **Payload:** user data (id, role, expiry)
- **Signature:** proves the token wasn't tampered with

**Analogy:** JWT is like a government ID. The government (server) issues it once. You carry it everywhere. Anyone who trusts the government can verify it without calling the government each time.

This file will be updated after Tue Apr 7 session.

---

## 🔁 Quick Revision Cheatsheet

### Run FastAPI
```bash
python3 -m uvicorn main:app --reload
# --reload = auto-restart on file changes
```

### Endpoint types
```python
@app.get("/path")           # read
@app.post("/path")          # create
@app.put("/path/{id}")      # replace
@app.delete("/path/{id}")   # delete
```

### Three ways to receive data
```python
# 1. Path parameter
@app.get("/users/{user_id}")
def get_user(user_id: int): ...

# 2. Query parameter
@app.get("/users")
def list_users(limit: int = 10, offset: int = 0): ...

# 3. Request body (POST/PUT)
class UserCreate(BaseModel):
    name: str
    email: str

@app.post("/users")
def create_user(user: UserCreate): ...
```

### SQLite quick reference
```python
conn   = sqlite3.connect("db.db")
cursor = conn.cursor()
cursor.execute("SQL", (params,))
conn.commit()
rows = cursor.fetchall()
conn.close()
```

### Status codes FastAPI uses
```python
raise HTTPException(status_code=404, detail="Not found")
raise HTTPException(status_code=401, detail="Unauthorised")
raise HTTPException(status_code=400, detail="Bad request")
```