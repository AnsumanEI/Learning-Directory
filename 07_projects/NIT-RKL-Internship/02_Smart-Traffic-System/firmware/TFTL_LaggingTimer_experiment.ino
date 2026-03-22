#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <ArduinoJson.h>

#define NUM_LIGHTS 4

struct TrafficLight {
  int redPin;
  int yellowPin;
  int greenPin;
  int adjGreenPin;
  int vehicleCount;
  unsigned long lastUpdate;
  String currentState;
};

TrafficLight lights[NUM_LIGHTS] = {
  {26, 27, 33, 32, 0, 0, "Red"},
  {13, 14, 12, 16, 0, 0, "Red"},
  {17, 18, 19, 4, 0, 0, "Red"},
  {21, 22, 23, 25, 0, 0, "Red"}
};

const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

AsyncWebServer server(80);

bool densityMode = false;
bool paused = false;
unsigned long lastMillis = 0;
unsigned long greenDuration = 5000; // 5 seconds
unsigned long yellowDuration = 2000; // 2 seconds
unsigned long redDelay = 500; // 500 ms delay between yellow and red
int threshold = 5; // Threshold value for density mode
bool priorityMode = false; // Flag to check if priority mode is active
int priorityPost = -1; // Post with priority
int currentLight = 0;
unsigned long changeTime = 0;

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML>
<html>
<head>
  <title>Traffic Light Control</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <style>
    /* Styles here */
  </style>
</head>
<body>
  <!-- HTML content here -->
  <script>
    /* JavaScript here */
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
  Serial.println(WiFi.localIP()); //prints ip in the serial monitor

  for (int i = 0; i < NUM_LIGHTS; i++) {
    pinMode(lights[i].redPin, OUTPUT);
    pinMode(lights[i].yellowPin, OUTPUT);
    pinMode(lights[i].greenPin, OUTPUT);
    pinMode(lights[i].adjGreenPin, OUTPUT);
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
        lights[i].vehicleCount = request->getParam("count")->value().toInt();
      }
      request->send(200, "text/plain", "OK");
    });
  }

  server.on("/status", HTTP_GET, [](AsyncWebServerRequest *request) {
    String json = "{";
    for (int i = 0; i < NUM_LIGHTS; i++) {
      json += "\"vehiclecount" + String(i+1) + "\":" + String(lights[i].vehicleCount) + ",";
      json += "\"lightStatus" + String(i+1) + "\":\"" + lights[i].currentState + "\",";
      json += "\"timer" + String(i+1) + "\":" + String(getTimer(i));
      if (i < NUM_LIGHTS - 1) json += ",";
    }
    json += "}";
    request->send(200, "application/json", json);
  });

  server.begin();
}

int getTimer(int index) {
  if (index == currentLight) {
    unsigned long elapsed = millis() - changeTime;
    if (elapsed < greenDuration) {
      return (greenDuration - elapsed) / 1000;
    } else if (elapsed < greenDuration + yellowDuration) {
      return (greenDuration + yellowDuration - elapsed) / 1000;
    } else {
      return (greenDuration + yellowDuration + redDelay - elapsed) / 1000;
    }
  }
  return 0;
}

void setLight(int index, const char* color) {
  if (strcmp(color, "Red") == 0) {
    digitalWrite(lights[index].redPin, HIGH);
    digitalWrite(lights[index].yellowPin, LOW);
    digitalWrite(lights[index].greenPin, LOW);
    digitalWrite(lights[index].adjGreenPin, LOW);
    lights[index].currentState = "Red";
  } else if (strcmp(color, "Yellow") == 0) {
    digitalWrite(lights[index].redPin, LOW);
    digitalWrite(lights[index].yellowPin, HIGH);
    digitalWrite(lights[index].greenPin, LOW);
    digitalWrite(lights[index].adjGreenPin, LOW);
    lights[index].currentState = "Yellow";
  } else if (strcmp(color, "Green") == 0) {
    digitalWrite(lights[index].redPin, LOW);
    digitalWrite(lights[index].yellowPin, LOW);
    digitalWrite(lights[index].greenPin, HIGH);
    digitalWrite(lights[index].adjGreenPin, LOW);
    lights[index].currentState = "Green";
  } else if (strcmp(color, "Adjacent") == 0) {
    digitalWrite(lights[index].redPin, LOW);
    digitalWrite(lights[index].yellowPin, LOW);
    digitalWrite(lights[index].greenPin, LOW);
    digitalWrite(lights[index].adjGreenPin, HIGH);
    lights[index].currentState = "Adjacent";
  }
}

void controlLights() {
  static bool transitioning = false;

  if (priorityMode) {
    if (millis() - changeTime >= greenDuration + yellowDuration + redDelay) {
      transitioning = false;
      changeTime = millis();
      priorityMode = false;
    } else if (!transitioning) {
      setLight(priorityPost, "Green");
      transitioning = true;
      lights[priorityPost].vehicleCount = max(lights[priorityPost].vehicleCount - 1, 0);
    } else if (millis() - changeTime >= greenDuration) {
      setLight(priorityPost, "Yellow");
    }
    return;
  }

  if (millis() - changeTime >= greenDuration + yellowDuration + redDelay) {
    changeTime = millis();
    currentLight = (currentLight + 1) % NUM_LIGHTS;
    if (densityMode) {
      int maxCount = -1;
      int maxIndex = -1;
      for (int i = 0; i < NUM_LIGHTS; i++) {
        if (lights[i].vehicleCount > maxCount) {
          maxCount = lights[i].vehicleCount;
          maxIndex = i;
        }
      }
      if (maxCount > threshold) {
        priorityMode = true;
        priorityPost = maxIndex;
        currentLight = maxIndex;
      }
    }
  }

  for (int i = 0; i < NUM_LIGHTS; i++) {
    if (i == currentLight) {
      if (millis() - changeTime < greenDuration) {
        setLight(i, "Green");
        if (millis() - lights[i].lastUpdate >= 300) {
          lights[i].vehicleCount = max(lights[i].vehicleCount - 1, 0);
          lights[i].lastUpdate = millis();
        }
      } else if (millis() - changeTime < greenDuration + yellowDuration) {
        setLight(i, "Yellow");
        if (millis() - lights[i].lastUpdate >= 600) {
          lights[i].vehicleCount = max(lights[i].vehicleCount - 1, 0);
          lights[i].lastUpdate = millis();
        }
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
        lights[i].vehicleCount++;
      }
    }
  }
}

void loop() {
  if (!paused) {
    controlLights();
  }
  delay(100);
}
