# C++ HTTP Client using libcurl

A C++ HTTP client that calls a FastAPI backend using libcurl. Demonstrates GET and POST requests with JSON payloads from C++.

---

## Stack

- C++ + libcurl — HTTP client
- Python + FastAPI + SQLite — backend server

---

## Build & Run

### Start the FastAPI server first

```bash
cd ../fastapi-sqlite/
python3 -m uvicorn main:app --reload
```

### Build and run the C++ client

```bash
g++ main.cpp -o client -lcurl
./client
```

## What it does

```
GET  /users        → fetches all users from SQLite via FastAPI
POST /users        → creates a new user with name + role
```

## What I Learned

- Making HTTP requests from C++ using libcurl
- Sending JSON payloads in POST requests
- Parsing JSON responses in C++
- Linking external libraries: `-lcurl`
- Why `http://` not `https://` for localhost