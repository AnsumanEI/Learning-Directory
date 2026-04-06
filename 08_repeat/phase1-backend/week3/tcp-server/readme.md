# C++ Multithreaded TCP Server

A TCP echo server built in C++ using POSIX sockets. Handles multiple clients simultaneously using `std::thread`. Implements a mini key-value protocol over raw TCP — similar to a stripped-down Redis.

---

## Build & Run

```bash
g++ server.cpp -o server -lpthread
./server
```

## Test with netcat

```bash
nc localhost 8000
```

## Protocol

```
SET name Arun     → SET successful
GET name          → Arun
GET age           → Key not found
hello             → hello  (echo fallback)
```

## Architecture

```
main thread:
  socket() → bind() → listen()
  loop:
    accept() ← blocks until client connects
    spawn std::thread(handle_client)
    detach() ← back to accept() immediately

each client thread:
  read() → parse command → SET/GET/echo → write()
  close() on disconnect
```

## Key Concepts

| Concept | What it does |
|---|---|
| `socket()` | Creates TCP socket |
| `bind()` | Assigns address + port |
| `listen()` | Starts accepting connections |
| `accept()` | Blocks until client connects |
| `std::thread` | One thread per client |
| `std::mutex` | Protects shared map from concurrent writes |
| `lock_guard` | Scoped lock — auto-releases |
| `istringstream` | Parses command string into words |

## What I Learned

- POSIX socket programming in C++
- TCP connection lifecycle: socket → bind → listen → accept → read/write → close
- Multithreading with `std::thread` and `detach()`
- Thread safety with `std::mutex` and `lock_guard`
- Building a mini text protocol from scratch
- Why `htons()` is needed for port numbers