#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <ArduinoJson.h>

#define NUM_LIGHTS 4
int REDLIGHT[NUM_LIGHTS];
int YELLOWLIGHT[NUM_LIGHTS];
int GREENLIGHT[NUM_LIGHTS];
int ADJGREEN[NUM_LIGHTS];

const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

AsyncWebServer server(80);

bool densityMode = false;
int vehiclecount1 = 0, vehiclecount2 = 0, vehiclecount3 = 0, vehiclecount4 = 0;
int threshold = 20;  // Threshold for vehicle difference

// HTML content for the web server
const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML>
<html>
<head>
  <title>Traffic Light Control</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <style>
    body {
      background-image: url('https://skai.io/wp-content/uploads/2021/06/skai-blue-background-web-1.jpg');
      background-size: cover;
      background-attachment: fixed;
      font-family: 'Arial', sans-serif;
      color: #fff;
      text-align: center;
      margin: 0;
      padding: 0;
      overflow-x: hidden;
    }
    header {
      background: rgba(0, 0, 0, 0.8);
      padding: 20px;
      font-size: 1.5em;
    }
    h1 {
      margin: 50px 0 20px 0;
    }
    form {
      background: rgba(0, 0, 0, 0.8);
      padding: 20px;
      border-radius: 10px;
      display: inline-block;
    }
    label, input {
      display: block;
      margin: 10px 0;
      text-align: left;
    }
    input[type="submit"], #switchMode {
      background: #4CAF50;
      color: white;
      border: none;
      padding: 10px 20px;
      cursor: pointer;
      border-radius: 5px;
      transition: background 0.3s;
    }
    input[type="submit"]:hover, #switchMode:hover {
      background: #45a049;
    }
    .status {
      background: rgba(0, 0, 0, 0.8);
      padding: 20px;
      border-radius: 10px;
      display: inline-block;
      margin-top: 20px;
    }
  </style>
</head>
<body>
  <header>
    <span>Traffic Light Control System</span>
  </header>
  <h1>Traffic Light Control</h1>
  <div class="status">
    <p>Current Mode: <span id="currentMode">Normal</span></p>
    <p>LED Status:</p>
    <p>Traffic Post 1: <span id="lightStatus1">Red</span></p>
    <p>Traffic Post 2: <span id="lightStatus2">Red</span></p>
    <p>Traffic Post 3: <span id="lightStatus3">Red</span></p>
    <p>Traffic Post 4: <span id="lightStatus4">Red</span></p>
    <p>Total Vehicles: <span id="totalVehicles">0</span></p>
  </div>
  <form action="/setvehiclecounts" method="post">
    <label for="vehiclecount1">Vehicle Count 1:</label>
    <input type="number" id="vehiclecount1" name="vehiclecount1" min="0" max="100">
    <label for="vehiclecount2">Vehicle Count 2:</label>
    <input type="number" id="vehiclecount2" name="vehiclecount2" min="0" max="100">
    <label for="vehiclecount3">Vehicle Count 3:</label>
    <input type="number" id="vehiclecount3" name="vehiclecount3" min="0" max="100">
    <label for="vehiclecount4">Vehicle Count 4:</label>
    <input type="number" id="vehiclecount4" name="vehiclecount4" min="0" max="100">
    <input type="submit" value="Set Vehicle Counts">
  </form>
  <br>
  <button id="switchMode">Switch to Density Mode</button>
  <script>
    document.getElementById('switchMode').addEventListener('click', function() {
      fetch('/switchmode')
        .then(response => response.text())
        .then(data => {
          document.getElementById('currentMode').innerText = data;
        });
    });

    function updateStatus() {
      fetch('/status')
        .then(response => response.json())
        .then(data => {
          document.getElementById('lightStatus1').innerText = data.lightStatus1;
          document.getElementById('lightStatus2').innerText = data.lightStatus2;
          document.getElementById('lightStatus3').innerText = data.lightStatus3;
          document.getElementById('lightStatus4').innerText = data.lightStatus4;
          document.getElementById('totalVehicles').innerText = data.totalVehicles;
          document.getElementById('currentMode').innerText = data.currentMode;
        });
    }

    setInterval(updateStatus, 1000); // Update status every second
  </script>
</body>
</html>
)rawliteral";


String getLEDStatus(int redPin, int yellowPin, int greenPin) {
  if (digitalRead(redPin) == HIGH) {
    return "Red";
  } else if (digitalRead(yellowPin) == HIGH) {
    return "Yellow";
  } else if (digitalRead(greenPin) == HIGH) {
    return "Green";
  } else {
    return "Off";
  }
}

int getTotalVehicles() {
  return vehiclecount1 + vehiclecount2 + vehiclecount3 + vehiclecount4;
}

void setup() {
  // Initialize serial communication
  Serial.begin(115200);

  // Initialize pin arrays
  REDLIGHT[0] = 26; YELLOWLIGHT[0] = 27; GREENLIGHT[0] = 33; ADJGREEN[0] = 32;
  REDLIGHT[1] = 13; YELLOWLIGHT[1] = 14; GREENLIGHT[1] = 12; ADJGREEN[1] = 16;
  REDLIGHT[2] = 17; YELLOWLIGHT[2] = 18; GREENLIGHT[2] = 19; ADJGREEN[2] = 4;
  REDLIGHT[3] = 21; YELLOWLIGHT[3] = 22; GREENLIGHT[3] = 23; ADJGREEN[3] = 25;

  // Set traffic lights and adjacent turn LEDs as outputs
  for (int i = 0; i < NUM_LIGHTS; i++) {
    pinMode(REDLIGHT[i], OUTPUT);
    pinMode(YELLOWLIGHT[i], OUTPUT);
    pinMode(GREENLIGHT[i], OUTPUT);
    pinMode(ADJGREEN[i], OUTPUT);
  }

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  Serial.print("The IP Address: ");
  Serial.println(WiFi.localIP());

  // Serve the HTML page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html);
  });

  // Handle form submission
  server.on("/setvehiclecounts", HTTP_POST, [](AsyncWebServerRequest *request){
    if (request->hasParam("vehiclecount1", true)) {
      vehiclecount1 = request->getParam("vehiclecount1", true)->value().toInt();
      Serial.println("Vehicle count 1: " + String(vehiclecount1));
    }
    if (request->hasParam("vehiclecount2", true)) {
      vehiclecount2 = request->getParam("vehiclecount2", true)->value().toInt();
      Serial.println("Vehicle count 2: " + String(vehiclecount2));
    }
    if (request->hasParam("vehiclecount3", true)) {
      vehiclecount3 = request->getParam("vehiclecount3", true)->value().toInt();
      Serial.println("Vehicle count 3: " + String(vehiclecount3));
    }
    if (request->hasParam("vehiclecount4", true)) {
      vehiclecount4 = request->getParam("vehiclecount4", true)->value().toInt();
      Serial.println("Vehicle count 4: " + String(vehiclecount4));
    }
    request->send(200, "text/plain", "Vehicle counts set");
  });

  // Handle mode switch
  server.on("/switchmode", HTTP_GET, [](AsyncWebServerRequest *request){
    densityMode = !densityMode;
    request->send(200, "text/plain", densityMode ? "Density" : "Normal");
  });

  // Handle status request
  server.on("/status", HTTP_GET, [](AsyncWebServerRequest *request){
    DynamicJsonDocument jsonDoc(1024);
    jsonDoc["currentMode"] = densityMode ? "Density" : "Normal";
    jsonDoc["lightStatus1"] = getLEDStatus(REDLIGHT[0], YELLOWLIGHT[0], GREENLIGHT[0]);
    jsonDoc["lightStatus2"] = getLEDStatus(REDLIGHT[1], YELLOWLIGHT[1], GREENLIGHT[1]);
    jsonDoc["lightStatus3"] = getLEDStatus(REDLIGHT[2], YELLOWLIGHT[2], GREENLIGHT[2]);
    jsonDoc["lightStatus4"] = getLEDStatus(REDLIGHT[3], YELLOWLIGHT[3], GREENLIGHT[3]);
    jsonDoc["totalVehicles"] = getTotalVehicles();
    String jsonString;
    serializeJson(jsonDoc, jsonString);
    request->send(200, "application/json", jsonString);
  });

  server.begin();
}

void controlTrafficLights() {
  // Simulate random vehicle counts
  vehiclecount1 = random(0, 100);
  vehiclecount2 = random(0, 100);
  vehiclecount3 = random(0, 100);
  vehiclecount4 = random(0, 100);

  int vehicleDiff1 = abs(vehiclecount1 + vehiclecount3 - vehiclecount2 - vehiclecount4);
  int vehicleDiff2 = abs(vehiclecount2 + vehiclecount4 - vehiclecount1 + vehiclecount3);
  
  if (vehicleDiff1 > threshold || vehicleDiff2 > threshold) {
    densityMode = true;
  } else {
    densityMode = false;
  }

  if (densityMode) {
    if (vehicleDiff1 > vehicleDiff2) {
      // Lane 1 and 3 have more vehicles
      Serial.println("Density Mode: Traffic Post 1 and 3 have more vehicles");
      digitalWrite(REDLIGHT[0], LOW);
      digitalWrite(GREENLIGHT[0], HIGH);
      digitalWrite(REDLIGHT[2], LOW);
      digitalWrite(GREENLIGHT[2], HIGH);
      delay(5000); // Keep green for 5 seconds
      digitalWrite(GREENLIGHT[0], LOW);
      digitalWrite(YELLOWLIGHT[0], HIGH);
      digitalWrite(GREENLIGHT[2], LOW);
      digitalWrite(YELLOWLIGHT[2], HIGH);
      delay(2000); // Yellow for 2 seconds
      digitalWrite(YELLOWLIGHT[0], LOW);
      digitalWrite(REDLIGHT[0], HIGH);
      digitalWrite(YELLOWLIGHT[2], LOW);
      digitalWrite(REDLIGHT[2], HIGH);
    } else {
      // Lane 2 and 4 have more vehicles
      Serial.println("Density Mode: Traffic Post 2 and 4 have more vehicles");
      digitalWrite(REDLIGHT[1], LOW);
      digitalWrite(GREENLIGHT[1], HIGH);
      digitalWrite(REDLIGHT[3], LOW);
      digitalWrite(GREENLIGHT[3], HIGH);
      delay(5000); // Keep green for 5 seconds
      digitalWrite(GREENLIGHT[1], LOW);
      digitalWrite(YELLOWLIGHT[1], HIGH);
      digitalWrite(GREENLIGHT[3], LOW);
      digitalWrite(YELLOWLIGHT[3], HIGH);
      delay(2000); // Yellow for 2 seconds
      digitalWrite(YELLOWLIGHT[1], LOW);
      digitalWrite(REDLIGHT[1], HIGH);
      digitalWrite(YELLOWLIGHT[3], LOW);
      digitalWrite(REDLIGHT[3], HIGH);
    }
  } else {
    // Normal Mode Logic
    Serial.println("Normal Mode");
    // Set all to red initially
    for (int i = 0; i < NUM_LIGHTS; i++) {
      digitalWrite(REDLIGHT[i], HIGH);
      digitalWrite(YELLOWLIGHT[i], LOW);
      digitalWrite(GREENLIGHT[i], LOW);
      digitalWrite(ADJGREEN[i], LOW);
    }

    // Cycle through the lights
    for (int i = 0; i < NUM_LIGHTS; i++) {
      digitalWrite(REDLIGHT[i], LOW);
      digitalWrite(GREENLIGHT[i], HIGH);
      digitalWrite(ADJGREEN[i], HIGH); // Adjacent turn LED on
      delay(5000); // Green for 5 seconds
      digitalWrite(GREENLIGHT[i], LOW);
      digitalWrite(ADJGREEN[i], LOW);
      digitalWrite(YELLOWLIGHT[i], HIGH);
      delay(2000); // Yellow for 2 seconds
      digitalWrite(YELLOWLIGHT[i], LOW);
      digitalWrite(REDLIGHT[i], HIGH);
    }
  }
}

void loop() {
  controlTrafficLights();
}
