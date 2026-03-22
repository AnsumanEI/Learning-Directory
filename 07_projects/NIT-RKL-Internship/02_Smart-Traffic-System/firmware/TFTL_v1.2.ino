#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <ArduinoJson.h>

#define NUM_LIGHTS 4
int REDLIGHT[NUM_LIGHTS] = {26, 13, 17, 21};
int YELLOWLIGHT[NUM_LIGHTS] = {27, 14, 18, 22};
int GREENLIGHT[NUM_LIGHTS] = {33, 12, 19, 23};
int ADJGREEN[NUM_LIGHTS] = {32, 16, 4, 25};

const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

AsyncWebServer server(80);

bool densityMode = false;
int vehiclecount[NUM_LIGHTS] = {0, 0, 0, 0};
bool paused = false;
unsigned long lastMillis = 0;
unsigned long greenDuration = 5000; // 5 seconds
unsigned long yellowDuration = 2000; // 2 seconds

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML>
<html>
<head>
  <title>Traffic Light Control</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <style>
    body {
      background-image: url('https://skai.io/wp-content/themes/skai/assets/images/bg-hero.jpg');
      background-size: cover;
      font-family: Arial, sans-serif;
      color: #fff;
      text-align: center;
      margin: 0;
      padding: 0;
    }
    h1 {
      margin-top: 50px;
      font-size: 2.5em;
      color: #4CAF50;
    }
    .container {
      display: flex;
      justify-content: center;
      flex-wrap: wrap;
      gap: 20px;
      padding: 20px;
    }
    .post-box {
      background: rgba(0, 0, 0, 0.8);
      border: 2px solid #4CAF50;
      border-radius: 10px;
      padding: 20px;
      width: 200px;
      text-align: center;
      transition: transform 0.3s, background 0.3s;
    }
    .post-box:hover {
      transform: scale(1.05);
      background: rgba(0, 0, 0, 0.9);
    }
    .status-box {
      margin-top: 20px;
      padding: 10px;
      border-radius: 10px;
      background: rgba(0, 0, 0, 0.8);
    }
    .light-indicator {
      width: 30px;
      height: 30px;
      border-radius: 50%;
      display: inline-block;
      margin: 5px;
    }
    .red-light {
      background: red;
    }
    .yellow-light {
      background: yellow;
    }
    .green-light {
      background: green;
    }
    .adjacent-light {
      background: #00FF00; /* Different green for adjacent turn */
    }
    button {
      background: #4CAF50;
      color: white;
      border: none;
      padding: 10px 20px;
      cursor: pointer;
      border-radius: 5px;
      transition: background 0.3s;
      margin: 10px;
    }
    button:hover {
      background: #45a049;
    }
  </style>
</head>
<body>
  <h1>Traffic Light Control</h1>
  <div class="container">
    <div class="post-box" id="post1" onclick="editVehicleCount(1)">
      <h2>Traffic Post 1</h2>
      <p>Vehicles: <span id="vehiclecount1">0</span></p>
      <div class="status-box">
        <div class="light-indicator red-light" id="lightStatus1Red"></div>
        <div class="light-indicator yellow-light" id="lightStatus1Yellow"></div>
        <div class="light-indicator green-light" id="lightStatus1Green"></div>
        <div class="light-indicator adjacent-light" id="lightStatus1Adjacent"></div>
      </div>
    </div>
    <div class="post-box" id="post2" onclick="editVehicleCount(2)">
      <h2>Traffic Post 2</h2>
      <p>Vehicles: <span id="vehiclecount2">0</span></p>
      <div class="status-box">
        <div class="light-indicator red-light" id="lightStatus2Red"></div>
        <div class="light-indicator yellow-light" id="lightStatus2Yellow"></div>
        <div class="light-indicator green-light" id="lightStatus2Green"></div>
        <div class="light-indicator adjacent-light" id="lightStatus2Adjacent"></div>
      </div>
    </div>
    <div class="post-box" id="post3" onclick="editVehicleCount(3)">
      <h2>Traffic Post 3</h2>
      <p>Vehicles: <span id="vehiclecount3">0</span></p>
      <div class="status-box">
        <div class="light-indicator red-light" id="lightStatus3Red"></div>
        <div class="light-indicator yellow-light" id="lightStatus3Yellow"></div>
        <div class="light-indicator green-light" id="lightStatus3Green"></div>
        <div class="light-indicator adjacent-light" id="lightStatus3Adjacent"></div>
      </div>
    </div>
    <div class="post-box" id="post4" onclick="editVehicleCount(4)">
      <h2>Traffic Post 4</h2>
      <p>Vehicles: <span id="vehiclecount4">0</span></p>
      <div class="status-box">
        <div class="light-indicator red-light" id="lightStatus4Red"></div>
        <div class="light-indicator yellow-light" id="lightStatus4Yellow"></div>
        <div class="light-indicator green-light" id="lightStatus4Green"></div>
        <div class="light-indicator adjacent-light" id="lightStatus4Adjacent"></div>
      </div>
    </div>
  </div>
  <button id="pauseButton">Pause</button>
  <button id="resumeButton" style="display:none;">Resume</button>
  <button id="switchMode">Switch to Density Mode</button>
  <script>
    let paused = false;
    document.getElementById('pauseButton').addEventListener('click', function() {
      paused = true;
      document.getElementById('pauseButton').style.display = 'none';
      document.getElementById('resumeButton').style.display = 'inline-block';
    });
    document.getElementById('resumeButton').addEventListener('click', function() {
      paused = false;
      document.getElementById('pauseButton').style.display = 'inline-block';
      document.getElementById('resumeButton').style.display = 'none';
    });

    document.getElementById('switchMode').addEventListener('click', function() {
      fetch('/switchmode')
        .then(response => response.text())
        .then(data => {
          document.getElementById('switchMode').innerText = `Switch to ${data} Mode`;
        });
    });

    function updateStatus() {
      if (!paused) {
        fetch('/status')
          .then(response => response.json())
          .then(data => {
            for (let i = 1; i <= 4; i++) {
              document.getElementById(`vehiclecount${i}`).innerText = data[`vehiclecount${i}`];
              document.getElementById(`lightStatus${i}Red`).style.display = data[`lightStatus${i}`] === 'Red' ? 'inline-block' : 'none';
              document.getElementById(`lightStatus${i}Yellow`).style.display = data[`lightStatus${i}`] === 'Yellow' ? 'inline-block' : 'none';
              document.getElementById(`lightStatus${i}Green`).style.display = data[`lightStatus${i}`] === 'Green' ? 'inline-block' : 'none';
              document.getElementById(`lightStatus${i}Adjacent`).style.display = data[`lightStatus${i}`] === 'Adjacent' ? 'inline-block' : 'none';
            }
          });
      }
    }

    function editVehicleCount(post) {
      let count = prompt(`Enter vehicle count for Traffic Post ${post}:`);
      if (count !== null) {
        fetch(`/setvehiclecount${post}?count=${count}`);
      }
    }

    setInterval(updateStatus, 1000);
  </script>
</body>
</html>
)rawliteral";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  for (int i = 0; i < NUM_LIGHTS; i++) {
    pinMode(REDLIGHT[i], OUTPUT);
    pinMode(YELLOWLIGHT[i], OUTPUT);
    pinMode(GREENLIGHT[i], OUTPUT);
    pinMode(ADJGREEN[i], OUTPUT);
  }

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send_P(200, "text/html", index_html);
  });

  server.on("/switchmode", HTTP_GET, [](AsyncWebServerRequest *request) {
    densityMode = !densityMode;
    String mode = densityMode ? "Normal" : "Density";
    request->send(200, "text/plain", mode);
  });

  for (int i = 0; i < NUM_LIGHTS; i++) {
    server.on(("/setvehiclecount" + String(i+1)).c_str(), HTTP_GET, [i](AsyncWebServerRequest *request) {
      if (request->hasParam("count")) {
        vehiclecount[i] = request->getParam("count")->value().toInt();
      }
      request->send(200, "text/plain", "OK");
    });
  }

  server.on("/status", HTTP_GET, [](AsyncWebServerRequest *request) {
    String json = "{";
    for (int i = 0; i < NUM_LIGHTS; i++) {
      json += "\"vehiclecount" + String(i+1) + "\":" + String(vehiclecount[i]) + ",";
      json += "\"lightStatus" + String(i+1) + "\":\"" + getLightStatus(i) + "\"";
      if (i < NUM_LIGHTS - 1) json += ",";
    }
    json += "}";
    request->send(200, "application/json", json);
  });

  server.begin();
}

String getLightStatus(int index) {
  if (digitalRead(REDLIGHT[index])) return "Red";
  if (digitalRead(YELLOWLIGHT[index])) return "Yellow";
  if (digitalRead(GREENLIGHT[index])) return "Green";
  if (digitalRead(ADJGREEN[index])) return "Adjacent";
  return "Unknown";
}

void controlLights() {
  static int currentLight = 0;
  static unsigned long changeTime = 0;

  if (millis() - changeTime >= greenDuration + yellowDuration) {
    changeTime = millis();
    currentLight = (currentLight + 1) % NUM_LIGHTS;
  }

  if (densityMode) {
    int maxCount = -1;
    for (int i = 0; i < NUM_LIGHTS; i++) {
      if (vehiclecount[i] > maxCount) {
        maxCount = vehiclecount[i];
        currentLight = i;
      }
    }
  }

  for (int i = 0; i < NUM_LIGHTS; i++) {
    if (i == currentLight) {
      if (millis() - changeTime < greenDuration) {
        setLight(i, "Green");
        vehiclecount[i] = max(vehiclecount[i] - 7, 0);
      } else if (millis() - changeTime < greenDuration + yellowDuration) {
        setLight(i, "Yellow");
      } else {
        setLight(i, "Red");
      }
    } else {
      setLight(i, "Red");
    }
  }

  if (millis() - lastMillis >= 1000) {
    lastMillis = millis();
    for (int i = 0; i < NUM_LIGHTS; i++) {
      if (random(100) < 20) { // 20% chance to add a vehicle
        vehiclecount[i]++;
      }
    }
  }
}

void setLight(int index, String color) {
  digitalWrite(REDLIGHT[index], color == "Red" ? HIGH : LOW);
  digitalWrite(YELLOWLIGHT[index], color == "Yellow" ? HIGH : LOW);
  digitalWrite(GREENLIGHT[index], color == "Green" ? HIGH : LOW);
  digitalWrite(ADJGREEN[index], color == "Adjacent" ? HIGH : LOW);
}

void loop() {
  controlLights();
  delay(100);
}
