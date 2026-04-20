# FastAPI curl Cheat Sheet

## What is curl?
`curl` is a command-line tool to make HTTP requests — how you test APIs without a browser or Postman.

---

## Anatomy of a curl Command

```bash
curl -X POST "http://localhost:8000/register" \
  -H "Content-Type: application/json" \
  -H "x-api-key: realapi" \
  -H "Authorization: Bearer <token>" \
  -d '{"username": "testuser", "password": "testpass"}'
```

| Part | What it means | Where it shows up in your code |
|------|--------------|-------------------------------|
| `-X POST` | HTTP method | `@app.post(...)` |
| `"http://..."` | URL + route | `@app.post("/register")` |
| `-H "Content-Type: application/json"` | Tells server you're sending JSON | FastAPI reads this automatically |
| `-H "x-api-key: realapi"` | Custom header | `x_api_key: str = Header()` in your function |
| `-H "Authorization: Bearer <token>"` | JWT token | `token: str = Depends(oauth2_scheme)` |
| `-d '{...}'` | Request body (JSON) | `user: Userlogin` / `device: DeviceSchema` in your function |

### The Rule
- `-H` → anything in function signature with `Header()` or `Depends(oauth2_scheme)`
- `-d` → anything that comes from a Pydantic schema (request body)
- **No `-d` on GET/DELETE** — they don't have a body

---

## All Routes & Their curl Commands

### `POST /register` — No auth needed
```bash
curl -X POST "http://localhost:8000/register" \
  -H "Content-Type: application/json" \
  -d '{"username": "testuser", "password": "testpass"}'
```

---

### `POST /login` — No auth needed, returns token
```bash
curl -X POST "http://localhost:8000/login" \
  -H "Content-Type: application/json" \
  -d '{"username": "testuser", "password": "testpass"}'
```

---

### `POST /users` — Needs API key
```bash
curl -X POST "http://localhost:8000/users" \
  -H "Content-Type: application/json" \
  -H "x-api-key: realapi" \
  -d '{"username": "john", "role": "admin"}'
```

---

### `GET /users` — Needs API key
```bash
curl -X GET "http://localhost:8000/users" \
  -H "x-api-key: realapi"
```

---

### `POST /devices` — Needs Bearer token
```bash
curl -X POST "http://localhost:8000/devices" \
  -H "Content-Type: application/json" \
  -H "Authorization: Bearer <token>" \
  -d '{"model_no": "ESP32-001", "model_name": "ESP32", "dev_status": "active"}'
```

---

### `GET /devices` — Needs Bearer token
```bash
curl -X GET "http://localhost:8000/devices" \
  -H "Authorization: Bearer <token>"
```

---

### `GET /devices/{id}` — Needs Bearer token
```bash
curl -X GET "http://localhost:8000/devices/1" \
  -H "Authorization: Bearer <token>"
```

---

### `PUT /devices/{id}` — Needs Bearer token + body
```bash
curl -X PUT "http://localhost:8000/devices/1" \
  -H "Content-Type: application/json" \
  -H "Authorization: Bearer <token>" \
  -d '{"model_no": "ESP32-001", "model_name": "ESP32-UPDATED", "dev_status": "inactive"}'
```

---

### `DELETE /devices/{id}` — Needs Bearer token
```bash
curl -X DELETE "http://localhost:8000/devices/1" \
  -H "Authorization: Bearer <token>"
```

---

### `GET /protected` — Needs both API key AND Bearer token
```bash
curl -X GET "http://localhost:8000/protected" \
  -H "x-api-key: realapi" \
  -H "Authorization: Bearer <token>"
```

---

## Quick Auth Reference

| Route | API Key (`-H "x-api-key"`) | Bearer Token (`-H "Authorization"`) | Body (`-d`) |
|-------|---------------------------|-------------------------------------|-------------|
| `POST /register` | ❌ | ❌ | ✅ `{username, password}` |
| `POST /login` | ❌ | ❌ | ✅ `{username, password}` |
| `POST /users` | ✅ | ❌ | ✅ `{username, role}` |
| `GET /users` | ✅ | ❌ | ❌ |
| `POST /devices` | ❌ | ✅ | ✅ `{model_no, model_name, dev_status}` |
| `GET /devices` | ❌ | ✅ | ❌ |
| `GET /devices/{id}` | ❌ | ✅ | ❌ |
| `PUT /devices/{id}` | ❌ | ✅ | ✅ `{model_no, model_name, dev_status}` |
| `DELETE /devices/{id}` | ❌ | ✅ | ❌ |
| `GET /protected` | ✅ | ✅ | ❌ |

---

## Typical Workflow

```bash
# 1. Register
curl -X POST "http://localhost:8000/register" \
  -H "Content-Type: application/json" \
  -d '{"username": "ansuman", "password": "mypassword"}'

# 2. Login → copy the access_token from the response
curl -X POST "http://localhost:8000/login" \
  -H "Content-Type: application/json" \
  -d '{"username": "ansuman", "password": "mypassword"}'

# 3. Use the token in subsequent requests
TOKEN="paste_your_token_here"

curl -X GET "http://localhost:8000/devices" \
  -H "Authorization: Bearer $TOKEN"
```
