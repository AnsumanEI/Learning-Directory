# ESP32 Smart Traffic Light System 🚦

> **Platform:** ESP32 (DOIT DevKit V1)  
> **Interface:** Self-hosted web dashboard over WiFi  
> **Versions:** 5 firmware iterations + Blynk cloud version  
> **Guide:** Dr. Santos Kumar Das, NIT Rourkela

A 4-intersection dynamic traffic light controller that runs entirely on an ESP32. It hosts its own web dashboard, adapts signal timings based on real-time vehicle density, and supports cloud control via Blynk.

---

## 💡 The Problem It Solves

Traditional traffic lights run on fixed timers regardless of how many vehicles are actually waiting. This wastes time at empty roads and causes congestion at busy ones. This system solves that by:

- Counting vehicles at each intersection
- Giving longer green time to busier lanes (Density Mode)
- Triggering priority signals for emergency vehicles
- Letting operators pause, resume, and tune everything from a phone browser

---

## 🏗️ System Architecture

```
┌─────────────────────────────────────────────────┐
│                   ESP32                         │
│                                                 │
│  ┌──────────────┐    ┌────────────────────────┐ │
│  │  Traffic     │    │   AsyncWebServer        │ │
│  │  Logic       │◄──►│   (port 80)             │ │
│  │  Engine      │    │                        │ │
│  └──────┬───────┘    └──────────┬─────────────┘ │
│         │                       │               │
│   GPIO outputs            HTTP / JSON           │
│   (12 LEDs × 4)          API endpoints          │
└─────────┼───────────────────────┼───────────────┘
          │                       │
    ┌─────┴──────┐         ┌──────┴──────┐
    │  4 Traffic  │         │  Web Browser │
    │  Posts      │         │  Dashboard   │
    │  R/Y/G/Adj  │         │  (any device)│
    └────────────┘         └─────────────┘
```

---

## ✨ Features

**Normal Mode** — Cycles through all 4 posts with fixed green/yellow durations. Each post gets equal time.

**Density Mode** — Monitors vehicle count at each intersection. The post with the most vehicles gets priority green time. Automatically returns to normal cycling after clearing congestion.

**Priority Mode** — Triggered when any post exceeds the density threshold. That post jumps the queue and gets an extended green phase.

**Web Dashboard** — Served directly from the ESP32. Shows live traffic light status (colour indicators), per-post countdown timers, vehicle counts (click to edit), Pause/Resume button, and Normal/Density mode toggle.

**Blynk Version** — Adds IR sensor input for automatic vehicle counting, manual/IR/auto mode switching, emergency vehicle priority detection, and peak-hour profiles based on real-time clock (8–11 AM).

---

## 📌 Hardware

**Components:** ESP32, 16× LEDs (4 Red, 4 Yellow, 4 Green, 4 Adjacent Green), resistors

**Pin Mapping:**

| Post | Red | Yellow | Green | Adj. Green |
|------|-----|--------|-------|------------|
| 1 | GPIO 26 | GPIO 27 | GPIO 33 | GPIO 32 |
| 2 | GPIO 13 | GPIO 14 | GPIO 12 | GPIO 16 |
| 3 | GPIO 17 | GPIO 18 | GPIO 19 | GPIO 4  |
| 4 | GPIO 21 | GPIO 22 | GPIO 23 | GPIO 25 |

**IR Sensors (Blynk version):** GPIO 34, 35, 32, 33

---

## 📁 Firmware — Evolution

| File | What changed |
|------|-------------|
| `TFTL_v1.1.ino` | First working version. Used `delay()` for timing. Density mode compared lane pairs. Vehicle counts via HTML form POST. |
| `TFTL_v1.2.ino` | Improved cycling logic, better density mode handling. |
| `TFTL_v1.4.ino` | Major refactor — replaced all `delay()` with `millis()` for non-blocking async timing. Added proper priority mode and threshold. Click-to-edit vehicle counts. |
| `TFTL_v1.5.ino` | Added per-post countdown timers to dashboard. Added `/pause` and `/resume` endpoints. Added `delayAfterYellow` transition gap. Gradual vehicle count decrement during green. |
| `TFTL_LaggingTimer_experiment.ino` | Experimental struct-based refactor to improve timer accuracy. |
| `TFTL_Blynk_v2.ino` | Full Blynk cloud integration. IR sensors on GPIO 34/35/32/33. Manual, IR, and Auto modes. Emergency vehicle priority. Peak-hour scheduling with RTC. |

---

## 🌐 Web API Endpoints

| Endpoint | Method | Description |
|----------|--------|-------------|
| `/` | GET | Serves the full dashboard HTML |
| `/status` | GET | Returns JSON with light states, timers, vehicle counts |
| `/switchmode` | GET | Toggles Normal ↔ Density mode |
| `/pause` | GET | Pauses the traffic cycle |
| `/resume` | GET | Resumes the traffic cycle |
| `/setvehiclecount1` | GET | Sets vehicle count for post 1 (`?count=N`) |
| `/setvehiclecount2` | GET | Sets vehicle count for post 2 |
| `/setvehiclecount3` | GET | Sets vehicle count for post 3 |
| `/setvehiclecount4` | GET | Sets vehicle count for post 4 |

---

## 🚀 Setup

1. Install [Arduino IDE](https://www.arduino.cc/en/software) and the ESP32 board package
2. Install libraries: `ESPAsyncWebServer`, `ArduinoJson`, `BlynkSimpleEsp32` (for Blynk version)
3. Open your chosen `.ino` file and replace credentials:
```cpp
const char* ssid     = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";
// Blynk version only:
#define BLYNK_AUTH_TOKEN "YOUR_BLYNK_AUTH_TOKEN"
```
4. Flash to ESP32 (board: DOIT ESP32 DEVKIT V1)
5. Open Serial Monitor at 115200 baud — the IP address will be printed
6. Open that IP in any browser on the same network

---

## 🔗 Protocols Used

`WiFi (802.11)` · `HTTP` · `JSON` · `mDNS` · `Blynk MQTT` · `GPIO`
