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