
- **Image** — a read-only snapshot/blueprint (like a class in OOP). Built from a `Dockerfile`. Never changes once built.
- **Container** — a running instance of an image (like an object). Has its own writable layer. You can run many containers from one image.
- **Tag** — a label on an image to identify its version (e.g., `myapp:v1.0`, `myapp:latest`)

**The flow:**  
`Dockerfile` → `docker build` → **Image** → `docker run` → **Container**

---

## Basic Docker Commands (Single Container Workflow)

### 1. Building an Image

```bash
# Basic build — image has no name (just an ID)
docker build .

# Build with a name and tag
docker build -t myapp:v1.0 .

# Build with name only (tag defaults to "latest")
docker build -t myapp .

# Force rebuild from scratch (no cached layers)
docker build --no-cache -t myapp .
```

**Breakdown of `docker build -t myapp:v1.0 .`:**
- `docker build` — build an image from a Dockerfile
- `-t myapp:v1.0` — tag the image as `myapp` version `v1.0`
- `.` — build context = current directory (where Dockerfile lives)

**Rule:** Use `--no-cache` when your `requirements.txt` or base image changes and cached layers are stale.

---

### 2. Tagging an Image

```bash
# Tag an existing image with a new name/version
docker tag myapp:v1.0 myapp:latest

# Tag for pushing to Docker Hub (username/repo:tag)
docker tag myapp:v1.0 ansuman966/myapp:v1.0
```

**Why tag?** Tags are how you version images. `latest` is just a convention — it doesn't auto-update. Always tag explicitly in production.

---

### 3. Listing Images and Containers

```bash
# List all locally stored images
docker images

# List running containers only
docker ps

# List ALL containers (running + stopped)
docker ps -a
```

---

### 4. Running a Container

```bash
# Basic run — creates and starts a container from image
docker run myapp

# Run with interactive terminal (for debugging)
docker run -it myapp bash

# Run in detached mode (background)
docker run -d myapp

# Run with port mapping (host:container)
docker run -d -p 8000:8000 myapp

# Run with environment variables
docker run -d -e SECRET_KEY=mysecret myapp

# Run with a custom name
docker run -d --name my-container myapp

# Run and auto-delete when stopped
docker run --rm myapp
```

**Common combo:**
```bash
docker run -d -p 8000:8000 --name fastapi-app myapp:latest
```

---

### 5. Stopping and Removing Containers

```bash
# Stop a running container (graceful)
docker stop my-container

# Force kill a container
docker kill my-container

# Remove a stopped container
docker rm my-container

# Stop and remove in one go
docker rm -f my-container

# Remove all stopped containers
docker container prune
```

---

### 6. Removing Images

```bash
# Remove an image by name/tag
docker rmi myapp:v1.0

# Remove image by ID
docker rmi abc123

# Remove all unused images (dangling)
docker image prune

# Remove ALL unused images (more aggressive)
docker image prune -a
```

---

### 7. Executing Commands Inside a Running Container

```bash
# Open interactive bash shell
docker exec -it my-container bash

# Run a one-off command
docker exec my-container ls /app

# Check environment variables
docker exec my-container env
```

---

### 8. Viewing Logs

```bash
# View logs from a container
docker logs my-container

# Follow logs in real time (like tail -f)
docker logs -f my-container

# Show last 50 lines
docker logs --tail 50 my-container
```

---

### 9. Inspecting a Container or Image

```bash
# Full JSON details about a container
docker inspect my-container

# Check port mappings
docker port my-container

# See resource usage (CPU, memory)
docker stats
```

---

## Docker Compose Commands

### Starting the stack
```bash
docker-compose up          # start with existing images (fast)
docker-compose up --build  # rebuild images first then start (use when code changed)
docker-compose up -d       # detached mode — runs in background
```

**Rule:** Changed `models.py`, `requirements.txt`, or `Dockerfile`? Always use `--build`.

### Stopping the stack
```bash
docker-compose down        # stop and remove containers
docker-compose down -v     # stop + delete volumes (wipes database data)
```

**Warning:** Never use `-v` unless you want to wipe the database completely.

### Checking running containers
```bash
docker-compose ps
```
Shows all containers, their status, and ports.

### Viewing logs
```bash
docker-compose logs web    # logs from web container only
docker-compose logs db     # logs from db container only
docker-compose logs        # logs from all containers
docker-compose logs -f     # follow logs in real time
```

### Executing commands inside a container
```bash
docker exec -it fastapi-sqlite-db-1 psql -U ansuman966 -d db
```
Breakdown:
- `docker exec` — run a command inside a running container
- `-it` — interactive terminal (so you can type commands)
- `fastapi-sqlite-db-1` — container name
- `psql -U ansuman966 -d db` — connect to Postgres as user ansuman966, database db

### Checking environment variables inside a container
```bash
# Linux/WSL
docker exec fastapi-sqlite-db-1 env | grep POSTGRES

# Windows PowerShell
docker exec fastapi-sqlite-db-1 env | findstr POSTGRES
```

### Exposing Postgres port to host machine
In `docker-compose.yml` under the `db` service:
```yaml
ports:
  - "5432:5432"
```
Left side = your machine port. Right side = container port.
Without this, Alembic (running outside Docker) cannot reach Postgres.

---

## psql Commands Used Today

```sql
\dt                  -- list all tables
\d device_readings   -- show columns, types, indexes, FK constraints of a table
exit                 -- leave psql
```

---

## Alembic Commands Used Today

### Setup — run once per project
```bash
alembic init migrations
```
Creates:
- `migrations/` folder
- `migrations/versions/` — where migration scripts live
- `alembic.ini` — config file
- `migrations/env.py` — tells Alembic how to connect and which models to track

### Generate a migration script
```bash
alembic revision --autogenerate -m "add device reading table"
```
- `--autogenerate` — Alembic compares your models against the live database and detects differences
- `-m "..."` — message label for this migration (like a git commit message)
- Creates a new file in `migrations/versions/`

### Apply migrations
```bash
alembic upgrade head
```
- `head` = apply all pending migrations up to the latest
- Runs the `upgrade()` function in each pending migration script

### Other useful Alembic commands (good to know)
```bash
alembic downgrade -1        # undo the last migration
alembic current             # show which migration is currently applied
alembic history             # show all migrations in order
```

---

## Config Changes Required After `alembic init`

### 1. `alembic.ini` — set the database URL
Find:
```
sqlalchemy.url = driver://user:pass@localhost/dbname
```
Replace with your actual URL (use localhost, not Docker service name):
```
sqlalchemy.url = postgresql://ansuman966:tracker@localhost:5432/db
```
Why localhost? Alembic runs outside Docker, so it connects via your machine's port.

### 2. `migrations/env.py` — tell Alembic about your models
Find:
```python
target_metadata = None
```
Replace with:
```python
from models import Base
target_metadata = Base.metadata
```
Without this, Alembic generates empty migration scripts — it doesn't know your models exist.

---

## Problems Faced Today + How They Were Debugged

### Problem 1: `sqlalchemy.url` written twice
```
sqlalchemy.url = sqlalchemy.url = postgresql://...
```
**How spotted:** Alembic threw `Could not parse SQLAlchemy URL` error.  
**Fix:** Remove the duplicate. Should be just `sqlalchemy.url = postgresql://...`  
**Lesson:** Copy-paste error. Always read the line after editing.

---

### Problem 2: Alembic can't connect — `Connection refused`
```
connection to server at "localhost", port 5432 failed: Connection refused
```
**How spotted:** Alembic error said port 5432 refused.  
**Why:** Postgres was inside Docker. Port 5432 was not exposed to the host machine.  
**Fix:** Add `ports: - "5432:5432"` under the `db` service in `docker-compose.yml`.  
**Lesson:** Alembic runs on your machine, not inside Docker. It needs the port open.

---

### Problem 3: `database "ansuman966" does not exist`
**How spotted:** `docker-compose logs db` showed repeated FATAL errors.  
**Why:** Postgres logs internal connection attempts during startup that default to using the username as the database name. This is noise — not a real app error.  
**How confirmed:** Ran `curl http://localhost/docs` → got 200. App was working fine.  
**Lesson:** Always test the actual app, not just the logs. Logs can have noise.

---

### Problem 4: `.env` file had spaces and wrong values
```
API_KEY = realapi          # spaces around = — risky
SECRET_KEY = SECRET_KEY    # set to literal string "SECRET_KEY" — wrong
ALGORITHM = "HS256"        # quotes in .env — wrong
```
**Fix:** No spaces, no quotes, no Python code in `.env`:
```
API_KEY=realapi
SECRET_KEY=realsecret
ALGORITHM=HS256
```
**Lesson:** `.env` is plain text. No Python. No quotes. No spaces around `=`.

---

### Problem 5: `grep` not found in PowerShell
```
grep : The term 'grep' is not recognized
```
**Why:** `grep` is a Linux command. PowerShell uses `findstr`.  
**Fix:**
```powershell
docker exec container_name env | findstr POSTGRES
```
**Lesson:** On Windows PowerShell, always use `findstr` instead of `grep`.

---

## How to Debug Docker/Alembic Problems — General Rules

| Symptom | First thing to check |
|---------|---------------------|
| Can't connect to database | Is the port exposed? Is the container running? |
| Wrong database name error | Check `.env` values. Check `docker exec container env` |
| Alembic generates empty migration | Did you set `target_metadata = Base.metadata` in `env.py`? |
| Alembic URL error | Check `alembic.ini` — no duplicates, correct format |
| App works but logs show errors | Test the actual endpoint. Logs can have noise |
| `command not found` | Are you in PowerShell or WSL? Different commands |

---

## Mental Model — How It All Connects

```
Your Machine
    │
    ├── alembic (runs here, connects via localhost:5432)
    │
    └── Docker
            ├── web container (FastAPI, port 8000)
            ├── db container (Postgres, port 5432 exposed)
            └── nginx container (port 80 → web:8000)
```

Alembic lives outside Docker. It needs `localhost:5432` to reach Postgres.  
FastAPI lives inside Docker. It uses `db:5432` (Docker service name) to reach Postgres.  
That's why the URLs are different in `alembic.ini` vs `.env`.

---

## Quick Reference — Docker Single Container Cheatsheet

| Goal | Command |
|------|---------|
| Build image | `docker build -t myapp:v1.0 .` |
| Tag image | `docker tag myapp:v1.0 myapp:latest` |
| List images | `docker images` |
| List running containers | `docker ps` |
| List all containers | `docker ps -a` |
| Run container (background) | `docker run -d -p 8000:8000 myapp` |
| Run with shell | `docker run -it myapp bash` |
| Stop container | `docker stop my-container` |
| Remove container | `docker rm my-container` |
| Remove image | `docker rmi myapp:v1.0` |
| View logs | `docker logs -f my-container` |
| Shell into running container | `docker exec -it my-container bash` |
| Inspect container | `docker inspect my-container` |
| Clean stopped containers | `docker container prune` |
| Clean unused images | `docker image prune -a` |

---

*Reference built: W6 D4, April 27, 2026*
