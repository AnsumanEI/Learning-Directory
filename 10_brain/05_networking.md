# 05 — Networking
> Topics: TCP/IP · DNS · HTTP · Sockets · tcpdump · Ports

---

## 🧠 The Big Idea

When your C++ program talks to another program over a network, data travels through **layers**. Each layer has one job and hands off to the next.

**Analogy:** Sending a letter internationally.
- You write the letter → **Application layer (HTTP)**
- Put it in an envelope with address → **Transport layer (TCP)**
- Post office decides the route → **Network layer (IP)**
- Physical delivery truck → **Physical layer**

---

## The 4 Layers (simplified)

```
┌─────────────────────────┐
│  Application (HTTP/MQTT)│  ← what your app speaks
├─────────────────────────┤
│  Transport (TCP/UDP)    │  ← reliable delivery, ports
├─────────────────────────┤
│  Network (IP)           │  ← addressing, routing
├─────────────────────────┤
│  Physical (Ethernet)    │  ← actual bits on wire/wifi
└─────────────────────────┘
```

---

# TCP

## What is TCP?

**Transmission Control Protocol** — a reliable, ordered, connection-based protocol.

- **Reliable:** if a packet is lost, it's resent automatically
- **Ordered:** data arrives in the same order it was sent
- **Connection-based:** both sides must agree to talk first (handshake)

**Analogy:** A phone call. You dial, they pick up, you confirm you can hear each other, then you talk. If they miss a sentence, you repeat it.

**vs UDP:** UDP is like shouting into a room. Fast, no confirmation, no guarantee anyone heard. Used for video streaming, games — where speed > reliability.

---

## TCP 3-Way Handshake

Before any data flows, TCP does this:

```
Client                    Server
  │                          │
  │──── SYN ────────────────►│   "I want to connect"
  │                          │
  │◄─── SYN-ACK ─────────────│   "OK, I'm ready"
  │                          │
  │──── ACK ────────────────►│   "Great, let's go"
  │                          │
  │    [data flows now]      │
```

- **SYN** = Synchronise
- **ACK** = Acknowledgement
- **SYN-ACK** = both at once

This is why your TCP server calls `listen()` before `accept()` — it's waiting for that SYN.

---

# DNS

## What is DNS?

**Domain Name System** — translates human-readable names to IP addresses.

**Analogy:** A phone book. You know the name (google.com), DNS tells you the number (142.250.77.46).

## What happens when you type google.com?

```
1. Browser checks its own cache → not there
2. Asks OS resolver → not there
3. Asks your router (ISP DNS) → not there
4. Asks Root DNS server → "try .com nameserver"
5. Asks .com nameserver → "try google's nameserver"
6. Asks Google's nameserver → "IP is 142.250.77.46"
7. Browser connects to that IP
8. Result cached so steps 2-6 skipped next time
```

---

# HTTP

## Methods

| Method | Meaning | Has body? |
|---|---|---|
| GET | Fetch a resource | No |
| POST | Create a resource | Yes |
| PUT | Replace a resource | Yes |
| PATCH | Partially update | Yes |
| DELETE | Remove a resource | No |

## Status Codes

| Code | Meaning |
|---|---|
| 200 | OK |
| 201 | Created |
| 400 | Bad Request (your fault) |
| 401 | Unauthorised |
| 403 | Forbidden |
| 404 | Not Found |
| 422 | Unprocessable Entity (FastAPI validation fail) |
| 500 | Internal Server Error (server's fault) |

---

# Ports

| Port | Service |
|---|---|
| 22 | SSH |
| 53 | DNS |
| 80 | HTTP |
| 443 | HTTPS |
| 1883 | MQTT |
| 5432 | PostgreSQL |
| 6379 | Redis |
| 8000 | FastAPI (dev) |
| 8080 | Common alt HTTP |

**Rule:** Ports 0–1023 are reserved (need sudo). Use 8000+ for dev servers.

---

# Sockets

## What is a socket?

A socket is the endpoint of a network connection. Think of it as a phone jack — one end in your program, the other end in the remote program.

## Socket lifecycle (server side)

```
socket()   → create the socket (get a file descriptor)
bind()     → assign it an address + port
listen()   → start waiting for connections
accept()   → block until a client connects (returns new fd)
read()     → receive data
write()    → send data
close()    → hang up
```

## Key functions

```cpp
// Create socket
int fd = socket(AF_INET, SOCK_STREAM, 0);
// AF_INET = IPv4, SOCK_STREAM = TCP

// Bind to address
sockaddr_in addr{};
addr.sin_family = AF_INET;
addr.sin_addr.s_addr = INADDR_ANY;  // any interface
addr.sin_port = htons(8080);        // convert port to network byte order
bind(fd, (sockaddr*)&addr, sizeof(addr));

// Listen + accept
listen(fd, 5);  // 5 = backlog queue
int client_fd = accept(fd, nullptr, nullptr);

// Read / write
read(client_fd, buf, sizeof(buf));
write(client_fd, response.c_str(), response.size());
```

---

# tcpdump

## What is it?

A tool that **captures network packets** live. Like putting a wiretap on your network interface.

```bash
# Watch all HTTP and HTTPS traffic
sudo tcpdump -i wlan0 port 80 or port 443 -n

# Watch traffic on any interface
sudo tcpdump -i any port 8000 -n

# -n = don't resolve hostnames (faster)
# -i = interface (wlan0 = wifi, lo = loopback/localhost)
```

## What you see

```
12:34:56 IP 192.168.1.5.54321 > 142.250.77.46.80: Flags [S]
```
- `Flags [S]` = SYN (connection starting)
- `Flags [S.]` = SYN-ACK
- `Flags [.]` = ACK
- `Flags [P.]` = data being pushed
- `Flags [F.]` = FIN (connection closing)

---

## 🔁 Quick Revision Cheatsheet

```
TCP   = reliable, ordered, connection-based (phone call)
UDP   = fast, unreliable, connectionless (shouting)
DNS   = name → IP address (phone book)
HTTP  = application protocol on top of TCP
Port  = which service on that IP (apartment number)
Socket= endpoint of a network connection (phone jack)

Handshake: SYN → SYN-ACK → ACK

htons() = host to network byte order (always use for ports)
INADDR_ANY = accept on any network interface
AF_INET = IPv4
SOCK_STREAM = TCP
```