#define BLYNK_TEMPLATE_ID "TMPL3_fOE_6xO"
#define BLYNK_TEMPLATE_NAME "Smart Dustbin 2"
#define BLYNK_AUTH_TOKEN "DhXU430biwETdx0JKqedsNeILMPFKjl5"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// 🔹 WiFi Credentials (Replace with actual SSID & Password)
char ssid[] = "Redmi Note 13 5G";
char pass[] = "9876543211";

// 🔹 Ultrasonic Sensor Pins
const int trigPin =17;
const int echoPin = 16;

// 🔹 Dustbin Parameters
const float dustbinHeight = 100.0; // Height in cm

void setup() {
  Serial.begin(115200);  // ✅ Start Serial Monitor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // ✅ Connect to WiFi & Blynk
  Serial.println("Connecting to WiFi...");
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  Serial.println("✅ Connected to Blynk!");
}

void loop() {
  Blynk.run();  // ✅ Keep Blynk running
  sendDataToBlynk();
  delay(5000); // Update every 5 seconds
}

// 🔹 Function to Measure Distance (Ultrasonic Sensor)
float measureDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  float distance = (duration * 0.0343) / 2; // Convert to cm
  return (distance >= 0 && distance <= dustbinHeight) ? distance : dustbinHeight;
}

// 🔹 Function to Calculate Fill Level
float calculateFillLevel(float distance) {
  float filledHeight = dustbinHeight - distance;
  float fillPercent = (filledHeight / dustbinHeight) * 100;
  return constrain(fillPercent, 0, 100); // Keep between 0-100%
}

// 🔹 Function to Send Data & Trigger Alarm
void sendDataToBlynk() {
    float distance = measureDistance();
    float fillPercent = calculateFillLevel(distance);

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.print(" cm, Fill Level: ");
    Serial.print(fillPercent);
    Serial.println(" %");

    Blynk.virtualWrite(V0, fillPercent);  // Fill Percentage
    Blynk.virtualWrite(V1, distance);     // Raw Distance in cm

    // ✅ Trigger Alarm if Fill Level > 90%
    if (fillPercent > 90) {
        Blynk.logEvent("dustbin_full", "🚨 Dustbin is Full! Please Empty It.");
        Serial.println("🚨 ALERT! Dustbin is Full! Notification Sent.");
    }
}
