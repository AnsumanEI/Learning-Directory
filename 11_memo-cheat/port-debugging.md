## What I Learned Today — Docker Networking + Debugging

---

### The Core Mental Model — Three Worlds

Today you dealt with three separate worlds and the confusion came from mixing them up:

**World 1 — Your Windows machine (host)**
This is where your terminal runs, where `consumer.py` runs, where your browser runs.

**World 2 — Inside a Docker container**
Each container is like a tiny isolated Linux machine. It has its own network, its own `localhost`, its own filesystem.

**World 3 — Docker compose network**
When you define services in `docker-compose.yml`, Docker automatically creates a private network and connects all containers to it. Inside this network, containers talk to each other using service names as hostnames.

---

### Rule 1 — `localhost` means different things depending on where you are

| Where you are             | What `localhost` means |
| ------------------------- | ---------------------- |
| Your Windows terminal     | Your own machine       |
| Inside a Docker container | That container itself  |

This is why `pika.ConnectionParameters('localhost')` failed inside the web container — it was looking for RabbitMQ inside the web container, not in the rabbitmq container.

**Fix:** Inside Docker, always use the service name. `pika.ConnectionParameters('rabbitmq')` — because Docker's internal DNS resolves `rabbitmq` to the rabbitmq container's IP automatically.

**Fix for outside Docker:** `consumer.py` runs on your machine, so it uses `localhost`. But only works if the port is mapped to the host.

---

### Rule 2 — Port mapping controls what's visible to the outside world

In docker-compose, ports work like this:

```yaml
ports:
  - "5672:5672"
```

This means: **host port 5672 → container port 5672**

Left side = your machine. Right side = inside the container.

Without this line, the port only exists inside Docker's private network. Other containers can still reach it by service name, but your host machine (and consumer.py) cannot.

This is exactly what you saw:

```
5672/tcp           ← no host mapping, invisible from outside
0.0.0.0:5672->5672 ← host mapping exists, visible from outside
```

**Rule of thumb:**

- Container to container → service name, no port mapping needed
- Host machine to container → port mapping required

---

### Rule 3 — Timing issues are a separate class of problem

Even when ports are correct and names are correct, you can still get connection errors if the service isn't ready yet. RabbitMQ takes ~10 seconds to fully boot. If your web container tries to connect before that, it fails.

Two ways to handle this:

1. `depends_on` in docker-compose — delays container start but doesn't guarantee the service is ready
2. `try/except` in code — safer, lets the app start even if RabbitMQ is slow

You did both today. The `try/except` is the more robust solution in production.

---

### How to Debug Port Issues — Step by Step

**Step 1 — Run `docker ps`**
Look at the PORTS column.

- `0.0.0.0:5672->5672/tcp` = port is mapped to host, accessible from outside
- `5672/tcp` = port exists inside Docker only, not accessible from host

**Step 2 — Is it a name resolution issue or a port issue?**

- `Name or service not known` → wrong hostname. Check if you're using `localhost` inside a container (wrong) or the service name (correct)
- `Connection refused` or `AMQPConnectionError` → hostname resolved but nothing is listening. Either port not mapped, service not started, or service not ready yet

**Step 3 — Check if the container is actually running**

```bash
docker ps
```

If the container isn't there, it crashed. Check logs:

```bash
docker logs <container_name>
```

**Step 4 — Check if the port is reachable from host**

```bash
curl http://localhost:5672
```

If it responds (even with garbage), the port is open. If it refuses, the mapping is missing.

**Step 5 — Check container to container connectivity**

```bash
docker exec -it fastapi-sqlite-web-1 ping rabbitmq
```

If ping works, DNS resolution is fine and they're on the same network.

---

### Today's Bug Chain — Summarised

| Error                                                   | Cause                                                             | Fix                                          |
| ------------------------------------------------------- | ----------------------------------------------------------------- | -------------------------------------------- |
| `AMQPConnectionError` with `localhost` in web container | `localhost` inside container = the container itself, not RabbitMQ | Use service name `rabbitmq`                  |
| `Name or service not known` with `rabbitmq`             | Containers not on same network yet / compose not rebuilt          | `docker-compose up --build`                  |
| `AMQPConnectionError` in consumer.py                    | Port 5672 not mapped to host                                      | Add `ports: 5672:5672` in docker-compose     |
| Port already allocated                                  | Old standalone rabbitmq container still holding port 5672         | `docker stop rabbitmq && docker rm rabbitmq` |

---

### The Golden Rules to Remember

1. **Inside Docker → use service name.** `rabbitmq`, `redis`, `db` — not `localhost`
2. **Outside Docker → use `localhost` + port must be mapped in docker-compose**
3. **Port mapping left=host, right=container.** No left side = invisible to host
4. **Connection errors → check `docker ps` ports column first**
5. **Name errors → you're using the wrong hostname for your context**
6. **Always `docker logs <name>` when a container misbehaves**

---
