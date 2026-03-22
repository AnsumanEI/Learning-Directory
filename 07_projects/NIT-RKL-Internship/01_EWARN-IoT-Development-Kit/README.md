# EWARN IoT Development Kit — 33 Experiments

> **Platform:** ESP32 (DOIT DevKit V1)  
> **Tools:** Arduino IDE, Node.js, Blynk, ThingSpeak, SQLite  
> **Guide:** Dr. Santos Kumar Das, NIT Rourkela

The **EWARN IoT Development Board** is a custom-built ESP32-based kit packed with sensors, actuators, and communication modules. This folder documents every experiment done on it — from basic GPIO to long-range wireless communication with LoRa and FSO.

---

## 🔧 What's on the Board

| Component | Interface | What it measures / does |
|-----------|-----------|--------------------------|
| DHT11 | Single-wire | Temperature & Humidity |
| BMP180 | I2C | Barometric Pressure & Altitude |
| MPU9250 (IMU) | I2C | 9-axis: Accelerometer, Gyroscope, Magnetometer |
| SSD1306 OLED (0.96") | I2C | Display output |
| SD Card Module | SPI | Data storage |
| Relay Module | GPIO | Switching high-power loads |
| LM386 Audio Amplifier | GPIO/PWM | Speaker / alarm output |
| HC-05 Bluetooth | UART | Wireless serial to mobile |
| GSM A7672S (4G) | UART (AT Commands) | SMS, cellular data |
| LoRa Module (868 MHz) | SPI | Long-range wireless (up to 15 km) |
| FSO Transceiver | UART | Free Space Optical (laser) communication |
| LED | GPIO | Basic output / indicator |
| Push Button | GPIO | Digital input |

---

## 🧪 All 33 Experiments

### Basics & GPIO
| # | Experiment | Key Concepts |
|---|-----------|-------------|
| 01 | ESP32 Setup & Arduino IDE | Board manager, CP210x drivers, port config |
| 02 | LED Blink | GPIO output, `digitalWrite`, `delay` |
| 03 | LED + Push Button | Digital input, pull-up resistors |

### Sensors → Serial Monitor
| # | Experiment | Key Concepts |
|---|-----------|-------------|
| 04 | DHT11 → Serial Monitor | `DHT.h`, temperature & humidity |
| 05 | BMP180 → Serial Monitor | I2C, `Adafruit_BMP085_U.h`, pressure & altitude |
| 06 | IMU (MPU9250) → Serial Monitor | I2C, `MPU9250_asukiaaa.h`, accel & gyro |

### Sensors → OLED Display
| # | Experiment | Key Concepts |
|---|-----------|-------------|
| 07 | Serial input → OLED | `Adafruit_SSD1306.h`, I2C display |
| 08 | DHT11 → OLED | Sensor + display pipeline |
| 09 | BMP180 → OLED | Pressure/altitude on display |
| 10 | IMU → OLED | Real-time motion data on display |

### Actuators & Alarms
| # | Experiment | Key Concepts |
|---|-----------|-------------|
| 11 | Relay Toggling | GPIO relay switching, LED status on OLED |
| 12 | Speaker (Beep Sound) | PWM audio, LM386 amplifier, volume control |
| 13 | High-Temp Alarm | DHT11 threshold trigger, `tone()` |
| 14 | IMU Accident Alarm | Acceleration magnitude threshold, `sqrt()` |

### Storage
| # | Experiment | Key Concepts |
|---|-----------|-------------|
| 15 | SD Card Read → OLED | SPI + I2C, hex file read, `SD.h` |
| 16 | DHT11 → SD Card Write | SPI logging, web-triggered file write |

### Wireless Communication
| # | Experiment | Key Concepts |
|---|-----------|-------------|
| 17 | Bluetooth → Mobile App | `BluetoothSerial.h`, serial terminal pairing |
| 18 | Blynk Relay Control | Blynk IoT app, virtual pins, remote relay toggle |
| 19 | WiFi Web Server | ESP32 as web server, DHT11 live page |
| 20 | Blynk Sensor Display | DHT11 → Blynk mobile + web dashboard |
| 21 | ThingSpeak Data Retrieval | HTTP GET, JSON parsing, OLED display |

### GSM (Cellular)
| # | Experiment | Key Concepts |
|---|-----------|-------------|
| 22 | GSM AT Commands | HardwareSerial, AT+CMGF, AT+CSQ, AT+CREG |
| 23 | GSM Data Transmission | SMS with DHT11 + BMP180 readings |
| 24 | SMS Accident Alert | IMU threshold → emergency SMS via GSM A7672S |

### Long-Range Communication
| # | Experiment | Key Concepts |
|---|-----------|-------------|
| 25 | LoRa Test | SPI, 868 MHz, CSS modulation, `LoRa.h` |
| 26 | LoRa Data Transmission | DHT11 Tx→Rx over LoRa, RSSI monitoring |
| 27 | FSO Data Transmission | Laser + phototransistor, UART over free space |

### Cloud & Database
| # | Experiment | Key Concepts |
|---|-----------|-------------|
| 28 | SQLite Upload | HTTP GET to custom backend, SQL INSERT |
| 29 | SQLite Retrieve | SQL SELECT, JSON parsing, serial output |
| 30 | Web Server LED Control | Login page, authenticated relay control |
| 31 | Weather Station | DHT11 + BMP180 + OLED + ThingSpeak dashboard |
| 32 | IMU → Node.js → ThingSpeak | HTTP POST, WebSocket, live browser dashboard |
| 33 | ThingSpeak Relay Toggle | Read ThingSpeak field → toggle relay |

---

## 🌐 IMU Node.js Server (Experiment 32)

A local server that receives MPU9250 IMU data from the ESP32, broadcasts it live to a browser via WebSocket, and pushes it to ThingSpeak.

```bash
cd IMU-NodeJS-Server
npm install
# Add your ThingSpeak API key in server.js
node server.js
# Open http://localhost:3000
```

**Stack:** Node.js · Express · WebSocket (`ws`) · Axios · ThingSpeak

---

## 📡 Communication Protocols Used

`I2C` · `SPI` · `UART` · `WiFi (802.11)` · `HTTP` · `WebSocket` · `Bluetooth (BT Classic)` · `GSM/4G (AT Commands)` · `LoRa (CSS @ 868 MHz)` · `FSO (Free Space Optics)` · `Blynk` · `ThingSpeak` · `SQLite`

---

## 📚 Libraries Used

```
DHT.h                   // DHT11 sensor
Adafruit_BMP085_U.h     // BMP180 barometric sensor
MPU9250_asukiaaa.h      // MPU9250 IMU
Adafruit_SSD1306.h      // OLED display
Adafruit_GFX.h          // Graphics primitives
Wire.h                  // I2C
SPI.h                   // SPI
SD.h                    // SD card
BluetoothSerial.h       // BT Classic
BlynkSimpleEsp32.h      // Blynk IoT
WiFi.h                  // WiFi
HTTPClient.h            // HTTP requests
ArduinoJson.h           // JSON parsing
ThingSpeak.h            // ThingSpeak cloud
LoRa.h                  // LoRa (Sandeep Mistry)
HardwareSerial.h        // GSM / FSO UART
```
