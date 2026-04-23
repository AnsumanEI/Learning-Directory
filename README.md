# Programming & DSA Learning Repository

> A structured collection of programs covering C, C++, Java, Data Structures & Algorithms,
> Backend Development, DevOps, IoT & Embedded Systems, and personal projects —
> built during active learning and organized for easy reference and recruiter review.

---

## Repository Structure

```
.
├── 01_languages/
│   ├── c/                              C language fundamentals (24 programs + chapters)
│   ├── cpp/                            C++ complete course (27 chapters)
│   └── java/                           Java basics — collections, OOP, strings, I/O
│
├── 02_dsa/
│   ├── binary-search/                  LeetCode binary search problems
│   ├── complete-course/                Full DSA course — Arrays, Maths, Recursion, STL
│   ├── core/                           Linked lists, arrays, BST, recursion deep-dives
│   ├── leetcode/                       LeetCode solutions
│   └── stl-cheatsheet/                 STL quick reference
│
├── 03_courses/
│   ├── internshala/                    Internshala DSA — Arrays, Trees, Graphs, Linked Lists, Sorting
│   ├── striver-a2z/                    Striver A2Z DSA sheet
│   └── supreme-batch/                  Supreme Batch (Babbar) — Binary Search
│
├── 04_interview-prep/
│   └── cc-qna/                         Competitive coding Q&A practice
│
├── 05_web/
│   ├── html-basics/                    HTML fundamentals, CSS, JavaScript
│   └── full-stack/                     HTML5, CSS, JS full-stack experiments
│
├── 06_college/                         College assignment programs (C++)
│
├── 07_projects/                        Showpiece projects + NIT Internship
│   └── NIT-RKL-Internship/             NIT Rourkela Internship 2024 (IoT + Embedded)
│
├── 08_repeat/
│   ├── lc-problems/                    ← Active Phase 1 DSA (LeetCode solutions)
│   ├── excercise/                      Cold-write practice files
│   └── phase1-backend/                 ← Active Phase 1 Backend
│       ├── week1/                      FastAPI intro + C++ KV store
│       ├── week2/                      FastAPI + Postgres + Docker + nginx
│       └── week3/                      C++ TCP echo server (Dockerized)
│
├── 09_claud_Learning/                  Daily session notes (W1–W5)
├── 10_brain/                           Obsidian-style knowledge vault
├── 11_memo-cheat/                      Cheat sheets — Backend, FastAPI, curl, JSON
└── 18month_full_tracker.html           18-month learning roadmap tracker
```

---

## 🚀 Active Work — Phase 1 (March–July 2026)

**Goal:** DSA in C++ + Backend (FastAPI/Python) + Linux/Networking + Docker

### DSA — `08_repeat/lc-problems/`

26 LeetCode problems solved across 5 weeks:

| Pattern | Problems |
|---|---|
| HashMap | LC #1, #217, #242, #49, #347 |
| Stack | LC #20, #155 |
| Sliding Window | LC #3, #239 |
| Binary Search | LC #704, #33 |
| Prefix/Suffix | LC #238 |
| Trees | LC #226, #104, #100, #572 |
| Graphs | LC #200, #133, #417, #130, #207, #210 |
| Dynamic Programming | LC #70, #198, #1143, #72, #139 |

### Backend API — `08_repeat/phase1-backend/week2/fastapi-sqlite/`

Production-grade FastAPI backend with:
- **Auth:** `/register` + `/login` — bcrypt password hashing, JWT tokens, OAuth2PasswordBearer
- **Protected routes:** Bearer token + API key middleware
- **CRUD:** `/users` + `/devices` — full 5-route CRUD with SQLAlchemy ORM
- **Database:** PostgreSQL (via Docker), SQLAlchemy, Alembic-ready models
- **Infrastructure:** Docker + docker-compose + nginx reverse proxy on port 80
- **Config:** `.env` + `os.getenv()` + `python-dotenv`
- **Middleware:** CORS + logging + global exception handler
- **Healthcheck:** `pg_isready` on db before web starts

```bash
# Run the full stack
cd 08_repeat/phase1-backend/week2/fastapi-sqlite
docker-compose up --build

# Test via nginx on port 80
curl -X POST http://localhost/register -H "Content-Type: application/json" -d '{"username":"test","password":"pass"}'
curl -X POST http://localhost/login -d "username=test&password=pass"
curl http://localhost/protected -H "Authorization: Bearer <token>" -H "x-api-key: realapi"
```

### TCP Server — `08_repeat/phase1-backend/week3/tcp-server/`

Raw C++ TCP echo server:
- Single client → multi-client → SET/GET KV store
- Dockerized with `docker-compose`

---

## Highlighted Projects

### 🔬 NIT Rourkela Internship 2024 (`07_projects/NIT-RKL-Internship/`)
Research internship at NIT Rourkela under Dr. Santos Kumar Das, Dept. of ECE (May–July 2024).

**EWARN IoT Development Kit** — 33 experiments on a custom ESP32 board: DHT11, BMP180, MPU9250 IMU, SSD1306 OLED, SD Card, Relay, GSM A7672S, LoRa (868 MHz), FSO (Free Space Optics). Includes a live Node.js + WebSocket IMU dashboard.

**ESP32 Smart Traffic Light System** — 4-intersection dynamic traffic controller with real-time web dashboard over WiFi. Evolved through 5 firmware iterations (v1.1 → v1.5 → Blynk). Blynk version adds IR sensors, emergency vehicle priority, and peak-hour profiles.

### Employee Management System (`07_projects/employee-management-system-final.cpp`)
Terminal-based C++ EMS — structs, classes, static variables, `iomanip` formatting, animated loading screen.

### Sorting Visualizer (`07_projects/sorting-visualizer-sfml.cpp`)
Real-time SFML insertion sort visualizer — 80 bars, live rendering, active bar highlighted.

### Tetris Game (`07_projects/tetris-game.cpp`)
Console Tetris in C++ using `wstring` Tetrimino encoding with rotation logic.

---

## Languages & Tools

**Languages:** C, C++, Java, Python, HTML, CSS, JavaScript, Arduino (C++)

**Backend:** FastAPI, SQLAlchemy, PostgreSQL, JWT, bcrypt, passlib, OAuth2, python-dotenv

**DevOps:** Docker, docker-compose, nginx, Dockerfile, healthchecks, volumes

**Networking:** TCP/IP, HTTP/HTTPS, TLS, DNS, libcurl, tcpdump, SSH, raw socket programming

**DSA:** HashMap, Stack, Sliding Window, Binary Search, Trees, Graphs (BFS/DFS/Topo), Dynamic Programming

**Libraries:** STL, SFML, ESPAsyncWebServer, ArduinoJson, Blynk, pydantic, uvicorn

**Tools:** GCC, Git, VS Code, Docker Desktop, WSL, Git Bash, Arduino IDE, Node.js, Obsidian

---

## Setup

```bash
# Compile any C file
gcc 01_languages/c/08-even-odd-check.c -o even-odd

# Compile any C++ file
g++ 08_repeat/lc-problems/lc-1-two-sum-problem.cpp -o two-sum

# Run the FastAPI backend (Docker)
cd 08_repeat/phase1-backend/week2/fastapi-sqlite
docker-compose up --build

# Run the TCP server (Docker)
cd 08_repeat/phase1-backend/week3/tcp-server
docker-compose up --build

# Compile SFML project
g++ 07_projects/sorting-visualizer-sfml.cpp -lsfml-graphics -lsfml-window -lsfml-system -o sorting-visualizer

# Run the IMU Node.js server
cd 07_projects/NIT-RKL-Internship/01_EWARN-IoT-Development-Kit/IMU-NodeJS-Server
npm install && node server.js
```

---

## Roadmap

| Phase | Timeline | Focus |
|---|---|---|
| Phase 1 | Mar–Jul 2026 | DSA (C++) + FastAPI + Linux + Docker |
| Phase 2 | Jul 2026–Jan 2027 | System Design + Kubernetes + AWS SAA + IoT Core |
| Phase 3 | Jan–Sep 2027 | Kafka + TimescaleDB + Observability + IoT Capstone |
| Phase 4 | Sep 2027–Mar 2028 | Interview Prep + Portfolio + Applications |