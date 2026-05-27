# nginx Load Balancing — Debug Log & Explanation

_W10 D2 — May 23, 2026_

---

## What We Built

```
Your Browser
     |
     | http://localhost:80
     |
  nginx container (port 80 exposed to host)
     |
     | internal Docker network
     |          |
  web         web2
(container)  (container)
 port 8000    port 8000
 host: 8001   host: 8002
```

Two FastAPI instances behind one nginx load balancer. nginx distributes incoming requests across both using round robin by default.

---

## Step 1 — Added `/which` endpoint to main.py

**Why:** We needed a way to tell which server handled each request. Docker sets each container's hostname to its container ID automatically. So returning `socket.gethostname()` tells us exactly which container responded.

```python
import socket

@app.get("/which")
def which_server():
    return {"server": socket.gethostname()}
```

If load balancing works, alternating requests should return different container IDs.

---

## Step 2 — First test: all requests hit the same server

```bash
curl http://localhost:80/which   # {"server":"0ccd9a7abd69"}
curl http://localhost:80/which   # {"server":"0ccd9a7abd69"}
curl http://localhost:80/which   # {"server":"0ccd9a7abd69"}
```

**Problem:** Same container ID every time. Expected alternating IDs.

---

## Step 3 — Suspected curl keepalive

**Why:** curl reuses TCP connections by default (HTTP keepalive). If the same connection is reused, all requests go through the same nginx worker → same upstream server.

**Fix attempt:** Force new connection each time with `--no-keepalive`

```bash
curl -s --no-keepalive http://localhost:80/which
curl -s --no-keepalive http://localhost:80/which
curl -s --no-keepalive http://localhost:80/which
```

**Result:** Still the same server. Keepalive wasn't the root cause.

---

## Step 4 — Checked nginx config inside the container

**Why:** The config file on disk and the config nginx actually loaded could differ if the volume wasn't mounted correctly, or if we forgot to rebuild.

```bash
docker exec -it fastapi-sqlite-nginx-1 cat /etc/nginx/conf.d/default.conf
```

**Result:** Config was correct. Both `web:8000` and `web2:8000` present in upstream block. Not the issue.

---

## Step 5 — Checked DNS resolution inside nginx container

**Why:** Even if the config is correct, nginx needs to resolve `web` and `web2` to actual container IPs via Docker's internal DNS. If DNS fails, nginx can't reach the second server.

```bash
docker exec -it fastapi-sqlite-nginx-1 nslookup web
docker exec -it fastapi-sqlite-nginx-1 nslookup web2
```

**Result:**

- `web` → `172.18.0.7` ✅
- `web2` → `172.18.0.8` ✅

Both containers reachable. Not a DNS issue.

---

## Step 6 — Checked nginx access logs

**Why:** We needed to confirm nginx was actually receiving our requests and forwarding them — not dropping them or erroring out silently.

```bash
docker logs fastapi-sqlite-nginx-1
```

**Result:** All 6 requests logged. nginx was receiving and forwarding correctly. But all going to the same upstream.

Also noticed a warning:

```
duplicate MIME type "text/html" in nginx.conf:25
```

This is because `gzip_types` already includes `text/html` by default in nginx. Not critical — just a config cleanup item.

---

## Step 7 — Checked web2 logs directly

**Why:** Instead of inferring from nginx, check if web2 was receiving _any_ traffic at all.

```bash
docker logs fastapi-sqlite-web2-1
```

**Result:** No requests. Only startup logs. web2 was running but receiving zero traffic.

---

## Step 8 — Sent 10 requests in a loop

**Why:** nginx round robin state is maintained **per worker process**, not globally. nginx spawned 12 worker processes (PIDs 30–41). When you send 3 rapid curl requests, the same worker process handles all 3 and keeps sending to the same upstream server. With more requests, different workers pick up different requests and the round robin distributes properly.

```bash
for i in {1..10}; do curl -s http://localhost:80/which; echo; done
```

**Result:** web2 logs showed 2 requests received. Load balancing confirmed working. ✅

---

## Root Cause Summary

| Suspected Cause                          | Actual Issue? | Why                                           |
| ---------------------------------------- | ------------- | --------------------------------------------- |
| curl keepalive                           | No            | `--no-keepalive` didn't fix it                |
| Wrong nginx config                       | No            | Config was correct inside container           |
| DNS resolution failure                   | No            | Both service names resolved correctly         |
| nginx not receiving requests             | No            | Access logs showed all requests arriving      |
| web2 not running                         | No            | `docker ps` showed both containers up         |
| **nginx worker-per-process round robin** | **Yes**       | 3 fast requests → same worker → same upstream |

---

## The Real Explanation — nginx Worker Processes

nginx spawns multiple worker processes to handle requests in parallel. Each worker maintains its own round robin counter independently.

When you send 3 rapid curl requests from the command line, they arrive so fast that the **same worker process** handles all 3. That worker's counter goes: web → web → web (it just keeps cycling through its own state).

With 10 requests sent in a loop, requests spread across **multiple workers**. Some workers send to `web`, others send to `web2`. Combined, you see both servers getting traffic.

**Key insight:** Round robin works correctly at scale. At very low request counts with rapid fire timing, you may see skewed distribution. This is normal and not a bug.

---

## What We Learned

1. **Always check the actual loaded config** — `docker exec nginx cat /etc/nginx/conf.d/default.conf`. The file on disk and what nginx loaded can differ.

2. **Always check DNS resolution** — `nslookup <service>` inside the nginx container. Docker's internal DNS resolves service names to container IPs automatically.

3. **Check the downstream server logs directly** — don't just trust the load balancer. If web2 logs are empty, traffic isn't reaching it regardless of what nginx says.

4. **nginx round robin is per-worker** — low volume testing may look like it's broken. Test with enough requests to span multiple workers.

5. **Stateless servers don't need sticky sessions** — JWT auth + shared database means any server can handle any request. Sticky sessions are only needed when session state lives in server memory.

---

## Sticky Sessions — When to Use

**Use sticky sessions when:** session data is stored in server memory (e.g. old PHP apps, in-memory session stores). Same client must always hit the same server or they lose their session.

**Don't use sticky sessions when:** your app is stateless — JWT tokens, shared database, Redis session store. Any server can handle any request. This is the correct modern approach.

**How to enable in nginx** (for reference only — not needed here):

```nginx
upstream fastapi_app {
    ip_hash;  # client IP always routes to same server
    server web:8000;
    server web2:8000;
}
```

---

_Load balancing verified working. Both instances receiving traffic. ✅_
