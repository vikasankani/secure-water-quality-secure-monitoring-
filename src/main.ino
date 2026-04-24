#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

// Pins (adjust based on your wiring)
#define TDS_PIN 34
#define TEMP_PIN 35

// Secret key
String SECRET_KEY = "K123";

// ---------- SENSOR FUNCTIONS ----------

int readTDS() {
  return analogRead(TDS_PIN);
}

int readTemp() {
  return analogRead(TEMP_PIN);
}

// ---------- TIMESTAMP ----------

unsigned long getTimestamp() {
  return millis();
}

// ---------- ENCRYPTION (XOR) ----------

String encryptData(String data) {
  String encrypted = "";
  for (int i = 0; i < data.length(); i++) {
    encrypted += char(data[i] ^ SECRET_KEY[0]);
  }
  return encrypted;
}

// ---------- MAC ----------

String generateMAC(String data) {
  int hash = 0;

  for (int i = 0; i < data.length(); i++) {
    hash += data[i];
  }

  for (int i = 0; i < SECRET_KEY.length(); i++) {
    hash += SECRET_KEY[i];
  }

  return String(hash);
}

// ---------- SETUP ----------

void setup() {
  Serial.begin(115200);
  SerialBT.begin("WaterMonitor"); // Bluetooth name

  Serial.println("ESP32 Water Monitoring System Started");
}

// ---------- LOOP ----------

void loop() {

  // 1. Read sensors
  int tds = readTDS();
  int temp = readTemp();

  // 2. Timestamp
  unsigned long timestamp = getTimestamp();

  // 3. Create data
  String data = String(tds) + "," + String(temp) + "," + String(timestamp);

  // 4. Generate MAC
  String mac = generateMAC(data);

  // 5. Append MAC
  String finalData = data + "," + mac;

  // 6. Encrypt
  String encrypted = encryptData(finalData);

  // 7. Send via Bluetooth
  SerialBT.println(encrypted);

  // Debug
  Serial.println("Raw: " + finalData);
  Serial.println("Encrypted: " + encrypted);

  delay(2000);
}
