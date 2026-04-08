# What to memorise vs understand — Backend Phase 1

> Paste this below the cheat sheet. Read before every backend session.
> Rule: if the concept IS the answer → memorise it. If the syntax is just mechanics → understand it, look it up.

---

## Tier 1 — Write from scratch, no hints

These come up directly in interviews and coding tasks. If you blank on these, you're stuck.

### FastAPI endpoint — all three input patterns

```python
# Path parameter
@app.get("/users/{user_id}")
def get_user(user_id: int):
    pass

# Query parameter
@app.get("/users")
def list_users(limit: int = 10):
    pass

# Request body
from pydantic import BaseModel
class UserCreate(BaseModel):
    name: str
    email: str

@app.post("/users")
def create_user(user: UserCreate):
    pass
```

### HTTPException — two lines, muscle memory

```python
raise HTTPException(status_code=404, detail="User not found")
raise HTTPException(status_code=401, detail="Invalid credentials")
```

### SQLAlchemy — four CRUD operations

```python
# Create
db.add(User(name="Arun", email="a@b.com"))
db.commit()
db.refresh(new_user)

# Read all
users = db.query(User).all()

# Read one (always check for None)
user = db.query(User).filter(User.id == 1).first()
if not user:
    raise HTTPException(status_code=404, detail="Not found")

# Delete
db.delete(user)
db.commit()
```

### API key check — 5 lines

```python
def verify_api_key(x_api_key: str = Header()):
    if x_api_key != API_KEY:
        raise HTTPException(status_code=401, detail="Invalid API key")
```

### JWT — the three functions (logic, not library syntax)

```python
# 1. Create token — add expiry and sign it
def create_access_token(data: dict):
    to_encode = data.copy()
    expire = datetime.utcnow() + timedelta(minutes=30)
    to_encode.update({"exp": expire})
    return jwt.encode(to_encode, SECRET_KEY, algorithm=ALGORITHM)

# 2. Verify token — decode and extract username
def verify_token(token: str):
    try:
        payload = jwt.decode(token, SECRET_KEY, algorithms=[ALGORITHM])
        username = payload.get("sub")
        if username is None:
            raise HTTPException(status_code=401, detail="Invalid token")
        return username
    except JWTError:
        raise HTTPException(status_code=401, detail="Invalid token")

# 3. Login endpoint — verify credentials, return token
@app.post("/login")
def login(username: str, password: str):
    if username != "admin" or password != "password123":
        raise HTTPException(status_code=401, detail="Invalid credentials")
    token = create_access_token(data={"sub": username})
    return {"access_token": token, "token_type": "bearer"}
```

### Status codes — burn these in

| Code | Meaning | Memory hook |
|------|---------|-------------|
| 200 | OK | All good |
| 201 | Created | POST succeeded |
| 400 | Bad Request | Client sent garbage |
| 401 | Unauthorized | I don't know who you are |
| 403 | Forbidden | I know you, but no |
| 404 | Not Found | Doesn't exist |
| 422 | Unprocessable | FastAPI validation failed |
| 500 | Server Error | Your code crashed |

**Memory rule: 4xx = client's fault. 5xx = server's fault.**
**401 vs 403: 401 = identity unknown. 403 = identity known, access blocked.**

### curl commands — type these every session

```bash
# GET with API key
curl http://localhost:8000/users -H "X-API-Key: secret123"

# POST with JSON body
curl -X POST http://localhost:8000/users \
     -H "Content-Type: application/json" \
     -H "X-API-Key: secret123" \
     -d '{"name": "Arun", "email": "arun@test.com"}'

# Get JWT token
curl -X POST "http://localhost:8000/login?username=admin&password=password123"

# Use JWT token
curl "http://localhost:8000/protected?token=PASTE_TOKEN_HERE"
```

---

## Tier 2 — Understand deeply, look up syntax

You won't write these from memory but you must explain what every line does.

### Network stack — know the layers

```
Application  →  HTTP   (the message format)
Transport    →  TCP    (reliable delivery, 3-way handshake)
Internet     →  IP     (routing across networks)
Physical     →  Wire   (actual bits)
```

- HTTP runs ON TOP of TCP. TCP is the pipe. HTTP is the message inside.
- Every HTTP request starts with a TCP connection.
- Port 80 = HTTP. Port 443 = HTTPS. Port 8000 = your local FastAPI.

### HTTP request anatomy — know the structure

```
GET /users HTTP/1.1        ← method + path + version
Host: localhost:8000       ← headers
X-API-Key: secret123       ←
                           ← blank line separates headers from body
{"name": "Arun"}           ← body (POST/PUT only, GET has none)
```

### SQLAlchemy setup — understand each line, copy-paste in projects

```python
engine = create_engine("sqlite:///./myapp.db")   # connection to DB file
Base = declarative_base()                         # base class for all models
SessionLocal = sessionmaker(bind=engine)          # factory for DB sessions

class User(Base):
    __tablename__ = "users"
    id = Column(Integer, primary_key=True)
    name = Column(String)
    email = Column(String)

Base.metadata.create_all(bind=engine)             # creates tables if not exist
```

### JWT structure — understand the three parts

```
header.payload.signature

Header:    {"alg": "HS256"}               algorithm used to sign
Payload:   {"sub": "admin", "exp": 123}   data + expiry
Signature: HMAC(header + payload, SECRET) mathematical proof of integrity
```

- `sub` = subject = who the token belongs to
- `exp` = expiry = unix timestamp when token dies
- Change one byte in payload → signature breaks → JWTError → 401
- Server never stores tokens. Signature IS the verification.

### TCP socket sequence — know the order and why

```
socket()   →  create a socket (like buying a phone)
bind()     →  attach to a port (like getting a phone number)
listen()   →  start accepting calls
accept()   →  pick up when someone calls (blocks until connection arrives)
read()     →  receive data
write()    →  send data
close()    →  hang up
```

FastAPI + uvicorn does all of this for you. Your `@app.get()` is just the `read/write` step.

### libcurl sequence — understand the pattern

```cpp
curl_easy_init()          // create handle
curl_easy_setopt(...)     // configure (URL, headers, body, callbacks)
curl_easy_perform()       // execute the request
curl_easy_cleanup()       // always clean up
```

---

## Tier 3 — Don't memorise, muscle memory or look up

- FastAPI import statements — autocomplete handles this
- JWT library function names — look up once per project
- SQLAlchemy column types (Integer, String, Boolean) — look up
- venv commands — will be automatic within 2 weeks
- nginx config syntax — look up every time

---

## The one-hour interview prep order

If you had one hour before an interview, study in this exact order:

1. FastAPI endpoint patterns (path, query, body, HTTPException)
2. CRUD four operations
3. JWT flow — not code, the mental model
4. API key check — 5 lines
5. Status codes table
6. TCP socket sequence — concepts only

---

## Honest self-check before next session

Before any backend session, open this file and answer these cold:

- [ ] Can I write a FastAPI endpoint with a path param from scratch?
- [ ] Can I write a FastAPI endpoint with a Pydantic body from scratch?
- [ ] Can I write the four CRUD operations without looking?
- [ ] Can I explain the JWT flow without looking at code?
- [ ] Can I name the TCP socket steps in order?
- [ ] Do I know 401 vs 403 without hesitating?

If any box is unchecked — spend 10 minutes on it before starting new material.