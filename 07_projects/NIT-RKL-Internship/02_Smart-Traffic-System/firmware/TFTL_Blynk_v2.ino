#define BLYNK_TEMPLATE_ID "YOUR_BLYNK_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "traffic"
#define BLYNK_AUTH_TOKEN "YOUR_BLYNK_AUTH_TOKEN"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <time.h> // For RTC

// WiFi credentials
char ssid[] = "YOUR_WIFI_SSID";
char pass[] = "YOUR_WIFI_PASSWORD";

// Traffic light pins
const int red[]    = {23, 22, 21, 19};
const int yellow[] = {18, 5, 4, 2};
const int green[]  = {15, 13, 12, 14};

// IR sensor pins
const int irPins[] = {34, 35, 32, 33};

// IR detection variables
bool irActive[4] = {false, false, false, false};
unsigned long irDetectedTime[4] = {0, 0, 0, 0};

// Simple IR trigger
bool irSimpleActive[4] = {false, false, false, false};
unsigned long irSimpleDetectedTime[4] = {0, 0, 0, 0};
const unsigned long irSimpleThreshold = 2000; // 2 sec

// Vehicle counting
int vehicleCount[4] = {0, 0, 0, 0};
unsigned long lastDetectionTime[4] = {0, 0, 0, 0};
const unsigned long detectionInterval = 1000; // 1 sec

// Modes
bool manualMode = false;
bool IRMode = false;
bool yellowPhase = false;
bool failSafeMode = false;

// Traffic system variables
int activePole = -1;
int currentPole = 0;
unsigned long lastChangeTime = 0;
unsigned long manualStartTime = 0;
unsigned long yellowStartTime = 0;
unsigned long greenDuration = 5000; // default 5 seconds
const unsigned long yellowDuration = 1000; // 1 second
unsigned long totalTimeLeft = 0;

// Emergency Vehicle Priority
bool emergencyDetected = false;
int emergencyPole = -1;

// Peak hour profile
bool isPeakHour = false;

// RTC Variables (for peak hours)
const int peakStartHour = 8;     // 8 AM
const int peakEndHour   = 11;    // 11 AM
const int eveningPeakStart = 17; // 5 PM
const int eveningPeakEnd   = 20; // 8 PM

// Emergency flags from Blynk
volatile bool blynkEmergencyFlag = false;
volatile int  blynkEmergencyPole = -1;

void setup() {
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  configTime(0, 0, "pool.ntp.org"); // Get time from internet

  for (int i = 0; i < 4; i++) {
    pinMode(red[i], OUTPUT);
    pinMode(yellow[i], OUTPUT);
    pinMode(green[i], OUTPUT);
    pinMode(irPins[i], INPUT);
  }

  allRed();
  delay(100);
  setGreenPole(currentPole);
}

void loop() {
  if (WiFi.status() != WL_CONNECTED) {
    failSafeMode = true;
  } else {
    failSafeMode = false;
  }

  Blynk.run();
  unsigned long now = millis();

  checkSimpleIRTrigger();
  checkPeakHour();

  if (blynkEmergencyFlag) {
    emergencyDetected = true;
    emergencyPole = blynkEmergencyPole;
    blynkEmergencyFlag = false;
  }

  if (failSafeMode) {
    handleFailSafeMode();
  } else if (IRMode) {
    handleIRDensityMode();
  } else {
    handleManualMode();
  }
}

// ---------------- Functions ----------------

void allRed() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(red[i], HIGH);
    digitalWrite(yellow[i], LOW);
    digitalWrite(green[i], LOW);
  }
}

void setGreenPole(int pole) {
  allRed();
  digitalWrite(green[pole], HIGH);
  Serial.print("Green on Pole: ");
  Serial.println(pole);
}

void setYellowPole(int pole) {
  allRed();
  digitalWrite(yellow[pole], HIGH);
  Serial.print("Yellow Phase on Pole: ");
  Serial.println(pole);
}

// ---------------- Manual Mode ----------------

void handleManualMode() {
  unsigned long now = millis();
  
  if (manualMode && now - manualStartTime > greenDuration) {
    manualMode = false;
    yellowPhase = true;
    yellowStartTime = now;
    setYellowPole(activePole);
  }

  if (!manualMode) {
    if (!yellowPhase && now - lastChangeTime >= greenDuration) {
      yellowPhase = true;
      yellowStartTime = now;
      setYellowPole(currentPole);
    }
    else if (yellowPhase && now - yellowStartTime >= yellowDuration) {
      yellowPhase = false;
      currentPole = (currentPole + 1) % 4;
      setGreenPole(currentPole);
      lastChangeTime = now;
    }
  }

  totalTimeLeft = (manualMode ? greenDuration - (now - manualStartTime) : 
                   (yellowPhase ? yellowDuration - (now - yellowStartTime) : greenDuration - (now - lastChangeTime)));
  Blynk.virtualWrite(V6, totalTimeLeft / 1000);
}

// ---------------- IR Density Mode ----------------

void handleIRDensityMode() {
  unsigned long now = millis();

  for (int i = 0; i < 4; i++) {
    if (digitalRead(irPins[i]) == LOW && now - lastDetectionTime[i] > detectionInterval) {
      vehicleCount[i]++;
      lastDetectionTime[i] = now;
    }
  }

  if (!yellowPhase && now - lastChangeTime >= greenDuration) {
    yellowPhase = true;
    yellowStartTime = now;
    setYellowPole(currentPole);
  }
  else if (yellowPhase && now - yellowStartTime >= yellowDuration) {
    yellowPhase = false;

    if (emergencyDetected) {
      currentPole = emergencyPole;
      emergencyDetected = false;
    } else {
      currentPole = selectNextPole();
    }

    setGreenPole(currentPole);
    lastChangeTime = now;
    adaptiveGreenDuration(currentPole);
  }

  totalTimeLeft = (yellowPhase ? yellowDuration - (now - yellowStartTime) : greenDuration - (now - lastChangeTime));
  Blynk.virtualWrite(V6, totalTimeLeft / 1000);
  updateVehicleCounts();
}

// ---------------- Fail Safe Mode ----------------

void handleFailSafeMode() {
  unsigned long now = millis();

  if (!yellowPhase && now - lastChangeTime >= 5000) {
    yellowPhase = true;
    yellowStartTime = now;
    setYellowPole(currentPole);
  }
  else if (yellowPhase && now - yellowStartTime >= yellowDuration) {
    yellowPhase = false;
    currentPole = (currentPole + 1) % 4;
    setGreenPole(currentPole);
    lastChangeTime = now;
  }
}

// ---------------- Helper Functions ----------------

int selectNextPole() {
  int maxPressure = -1;
  int selectedPole = 0;
  unsigned long now = millis();

  for (int i = 0; i < 4; i++) {
    long waitingTime = now - lastDetectionTime[i];
    int pressure = (vehicleCount[i] * 2) + (waitingTime / 1000);

    if (vehicleCount[i] >= 10) {
      Serial.print("Critical Traffic at Pole: ");
      Serial.println(i);
      return i;
    }

    if (pressure > maxPressure) {
      maxPressure = pressure;
      selectedPole = i;
    }
  }
  return selectedPole;
}

void adaptiveGreenDuration(int pole) {
  greenDuration = 4000 + (vehicleCount[pole] * 500);
  if (greenDuration > 15000) greenDuration = 15000;

  if (isPeakHour) {
    greenDuration += 3000;
  }

  Serial.print("New Green Duration for Pole ");
  Serial.print(pole);
  Serial.print(": ");
  Serial.print(greenDuration / 1000);
  Serial.println(" sec");

  vehicleCount[pole] = 0;
}

void updateVehicleCounts() {
  Blynk.virtualWrite(V10, vehicleCount[0]);
  Blynk.virtualWrite(V11, vehicleCount[1]);
  Blynk.virtualWrite(V12, vehicleCount[2]);
  Blynk.virtualWrite(V13, vehicleCount[3]);
}

void checkPeakHour() {
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) return;

  int hour = timeinfo.tm_hour;
  isPeakHour = (hour >= peakStartHour && hour <= peakEndHour) || (hour >= eveningPeakStart && hour <= eveningPeakEnd);
}

// ---------------- Simple IR Trigger ----------------

void checkSimpleIRTrigger() {
  unsigned long now = millis();

  for (int i = 0; i < 4; i++) {
    if (digitalRead(irPins[i]) == LOW) {
      if (!irSimpleActive[i]) {
        irSimpleActive[i] = true;
        irSimpleDetectedTime[i] = now;
      }
      else if (now - irSimpleDetectedTime[i] >= irSimpleThreshold && !manualMode && !yellowPhase && !failSafeMode) {
        switchToManual(i);
        Serial.print("Simple IR Triggered on Pole: ");
        Serial.println(i);
      }
    } else {
      irSimpleActive[i] = false;
      irSimpleDetectedTime[i] = 0;
    }
  }
}

// ---------------- Blynk Handlers ----------------

BLYNK_WRITE(V1) { if (param.asInt() == 1) switchToManual(0); }
BLYNK_WRITE(V2) { if (param.asInt() == 1) switchToManual(1); }
BLYNK_WRITE(V3) { if (param.asInt() == 1) switchToManual(2); }
BLYNK_WRITE(V4) { if (param.asInt() == 1) switchToManual(3); }
BLYNK_WRITE(V5) { IRMode = param.asInt(); }
BLYNK_WRITE(V7) { blynkEmergencyFlag = true; }
BLYNK_WRITE(V37) { blynkEmergencyPole = param.asInt(); }

void switchToManual(int pole) {
  manualMode = true;
  manualStartTime = millis();
  activePole = pole;
  setGreenPole(activePole);
  
  Blynk.virtualWrite(V1, 0);
  Blynk.virtualWrite(V2, 0);
  Blynk.virtualWrite(V3, 0);
  Blynk.virtualWrite(V4, 0);
}

