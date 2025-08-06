# -Iot-Project-
An IoT-based smart dustbin using ESP32, ultrasonic sensor, and Blynk. It monitors the fill level in real-time, sends data to the Blynk app, and triggers alerts when the dustbin is over 90% full. Ideal for smart city waste management. Easy integration with Wi-Fi and mobile dashboard.
📦 Smart Dustbin with IoT (ESP32 + Blynk)
A smart IoT-based dustbin system built using ESP32, Ultrasonic Sensor, and Blynk IoT platform that monitors real-time fill levels and alerts the user when the dustbin is nearly full.

🚀 Features
📡 Real-time Monitoring: Continuously measures dustbin fill level using an ultrasonic sensor.

📲 IoT Integration (Blynk): Sends live data (distance & fill percentage) to Blynk mobile app dashboard.

🚨 Smart Notifications: Automatically triggers a Blynk notification if the dustbin is more than 90% full.

💡 Serial Output: Displays sensor readings and alerts via Serial Monitor for debugging.

🛠️ Tech Stack
ESP32 microcontroller

Ultrasonic Sensor (HC-SR04)

Blynk IoT platform

C++ (Arduino Framework)

📊 Blynk Virtual Pins
Data	Virtual Pin
Fill Level (%)	V0
Distance (cm)	V1

📥 How to Use
Flash the code to your ESP32 using Arduino IDE.

Update the following:

BLYNK_AUTH_TOKEN with your Blynk token

ssid and pass with your Wi-Fi credentials

Connect your ultrasonic sensor to the defined GPIO pins.

Open Blynk app and create widgets:

Gauge/Display on V0 for Fill Level

Display on V1 for Distance

You’ll receive notifications when the dustbin is nearly full ( > 90%).

🔐 Security Note
For production use, avoid hardcoding your Wi-Fi and Blynk credentials directly in the code. Consider using a secure configuration or EEPROM-based setup.
