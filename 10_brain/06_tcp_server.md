# 06 — TCP Server (Project)
> Built: Sat Apr 4  
> Location: `week3/tcp-server/server.cpp`  
> Compile: `g++ server.cpp -o server -lpthread`  
> Run: `./server` then `nc localhost 8000`

---

## What I Built

A C++ TCP server that:
1. Listens on port 8000
2. Accepts multiple clients simultaneously using `std::thread`
3. Understands a mini protocol: `SET key value` and `GET key`
4. Falls back to echo for unknown commands
5. Protects shared map with a `mutex`

---

## The Full Flow — `SET name Arun`

### Stage 1 — You type in netcat
```
SET name Arun
```
Netcat converts this to raw bytes and sends over TCP.

### Stage 2 — `read()` catches it
```cpp
int bytes = read(client_fd, buf, sizeof(buf));
// buf = "SET name Arun\n"
```
Raw bytes dumped into `buf`. No meaning yet.

### Stage 3 — Convert to string
```cpp
string line(buf);
```

### Stage 4 — `istringstream` splits into words
```cpp
istringstream iss(line);
string cmd, key, value;
iss >> cmd >> key >> value;
// cmd="SET"  key="name"  value="Arun"
```

### Stage 5 — if block runs
```cpp
if (cmd == "SET") {
    lock_guard<mutex> lock(mtx);  // acquire lock
    store[key] = value;            // store["name"] = "Arun"
    response = "SET successful";
}                                  // lock auto-released here
```

### Stage 6 — `write()` sends response
```cpp
write(client_fd, response.c_str(), response.size());
// client sees: SET successful
```

---

## `buf` vs `response` — The Key Difference

```
buf       → raw bytes that ARRIVED from client (input)
response  → string you DECIDED to send back (output)

cout << buf                  → appears on SERVER terminal only
write(client_fd, response)   → travels through socket → CLIENT sees it
```

---

## Thread Safety

All threads share the same `store` map. Without protection, two threads writing simultaneously = data corruption.

```cpp
map<string,string> store;  // shared — all threads read/write this
mutex mtx;                 // the lock

// Inside handle_client:
lock_guard<mutex> lock(mtx);  // one thread at a time
store[key] = value;
// lock auto-released when lock_guard goes out of scope
```

**`lock_guard`** = scoped lock. Acquires on construction, releases on destruction. You can't forget to unlock.

---

## Full Architecture

```
main thread:
  socket() → bind() → listen()
  loop:
    accept()  ← blocks until client connects
    spawn thread(handle_client, client_fd)
    t.detach() ← go back to accept() immediately

each client thread:
  loop:
    read() → parse → SET/GET/echo → write()
  close(client_fd)
```

---

## Key Concepts Learned

| Concept | What it does |
|---|---|
| `socket()` | Creates a socket, returns file descriptor |
| `bind()` | Attaches socket to address + port |
| `listen()` | Starts accepting incoming connections |
| `accept()` | Blocks until client connects, returns client fd |
| `htons()` | Converts port to network byte order |
| `INADDR_ANY` | Accept on any network interface |
| `SO_REUSEADDR` | Reuse address immediately after restart |
| `SO_REUSEPORT` | Multiple sockets on same port |
| `std::thread` | Spawn independent thread |
| `t.detach()` | Thread runs independently, no join needed |
| `lock_guard` | Scoped mutex — auto-releases |
| `istringstream` | Split string into words with `>>` |
| `-lpthread` | Link pthread library when compiling |

---

## Compile & Test

```bash
g++ server.cpp -o server -lpthread
./server

# Terminal 2:
nc localhost 8000
SET name Arun    # → SET successful
GET name         # → Arun
GET age          # → Key not found
hello            # → hello (echo fallback)
```

---

## Bugs Found During Code Review

| Bug | Cause | Fix |
|---|---|---|
| `iss >> value` twice for SET | Extracted on first line already, second read got empty string | Remove second `iss >> value` inside SET block |
| Unknown command sent empty response | `response` never set in else block | Set `response = string(buf)` for echo fallback |
| Duplicate `using namespace std` | Pasted twice | Delete the second one |

# TCP Server — Full Flow Explained

## The journey of `SET name Arun`

### Stage 1 — You type in netcat

```
SET name Arun
```

You press Enter. Netcat takes that string and sends it as raw bytes over TCP to port 8000.

The bytes look like this in memory:
```
S E T   n a m e   A r u n \n
```
Just characters. No structure. No meaning yet. Raw bytes travelling through a socket.

---

### Stage 2 — `read()` catches it

```cpp
int bytes = read(client_fd, buf, sizeof(buf));
```

`read()` is sitting and waiting. The moment bytes arrive through the socket, it wakes up and dumps them into `buf`.

```
buf   = "SET name Arun\n"
bytes = 14
```

`buf` is just a raw char array. It has no idea what SET means. Just characters sitting in memory.

---

### Stage 3 — Convert to string

```cpp
string line(buf);
```

You wrap `buf` in a proper C++ string. Same content, but now you can use C++ string tools on it.

---

### Stage 4 — `istringstream` splits it into words

```cpp
istringstream iss(line);
string cmd, key, value;
iss >> cmd >> key >> value;
```

`istringstream` treats the string like a stream of words separated by spaces. `>>` pulls one word at a time.

```
iss >> cmd    →  cmd   = "SET"
iss >> key    →  key   = "name"
iss >> value  →  value = "Arun"
```

Now you have three separate variables. The program can actually reason about them.

---

### Stage 5 — The if block runs

```cpp
if(cmd == "SET"){
    lock_guard<mutex> lock(mtx);
    store[key] = value;
    response = "SET successful";
}
```

- `lock_guard` acquires the mutex — no other thread can touch `store` right now
- `store["name"] = "Arun"` — stored in the map
- `lock_guard` goes out of scope at `}` — mutex automatically released
- `response` = `"SET successful"`

`response` is just a string variable in memory. Nothing has been sent yet.

---

### Stage 6 — `write()` sends the response

```cpp
write(client_fd, response.c_str(), response.size());
```

- `response.c_str()` → converts string to raw char pointer (`write()` only understands raw bytes)
- `response.size()` → tells `write()` how many bytes to send
- `write()` pushes those bytes back through the socket to the client

Netcat receives and prints:
```
SET successful
```

---

## The journey of `GET name`

Same Stages 1–4. After splitting:
```
cmd   = "GET"
key   = "name"
value = ""      ← no third word
```

### Stage 5 — GET block runs

```cpp
} else if(cmd == "GET"){
    lock_guard<mutex> lock(mtx);
    if(store.find(key) != store.end()){
        response = store[key] + "\n";
    } else {
        response = "Key not found";
    }
}
```

- `store.find("name")` → searches the map, finds it
- `store["name"]` → returns `"Arun"`
- `response = "Arun\n"`

### Stage 6 — `write()` sends it

Netcat prints:
```
Arun
```

---

## `response` vs `buf` — the key difference

```
buf       → what ARRIVED from the client (raw bytes, no meaning)
response  → what you DECIDED to send back (constructed by your logic)
```

`buf` is input. `response` is output.

| | Where it appears |
|---|---|
| `cout << buf` | Server terminal only. Client never sees this. |
| `write(client_fd, response...)` | Travels through socket. Client sees this. |

`cout << buf` is your server peeking at what arrived before processing it.  
`write()` is your server replying to the client.

---

## Full flow diagram

```
You type in netcat
        ↓
   bytes travel through TCP socket
        ↓
   read() dumps bytes into buf        ← raw, no meaning
        ↓
   istringstream splits into cmd/key/value
        ↓
   if/else decides what to do
        ↓
   store[] reads or writes the map
        ↓
   response string is constructed     ← your decision
        ↓
   write() pushes response through socket
        ↓
   netcat receives and prints it      ← client sees this
```

---

## Quick reference

| Variable | Type | What it holds |
|---|---|---|
| `buf` | `char[]` | Raw bytes from client |
| `line` | `string` | Same content, C++ string |
| `iss` | `istringstream` | Word splitter |
| `cmd` | `string` | First word — SET / GET |
| `key` | `string` | Second word — the key |
| `value` | `string` | Third word — the value (SET only) |
| `response` | `string` | What you send back |
| `store` | `map<string,string>` | The in-memory database |
| `mtx` | `mutex` | Protects store from concurrent writes |