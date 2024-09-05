#include <ESP8266WiFi.h>

const char* ssid = "TestWiFi";
const char* password = "TestWiFi123";
const char* server = "https://localhost:7002";  // Your ASP.NET API endpoint

WiFiClient client;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

void loop() {
  // Read sensor data (e.g., analog sensor)
  int sensorValue = analogRead(A0);
  
  if (client.connect(server, 80)) {
    String postData = "{\"sensorValue\":" + String(sensorValue) + "}";

    client.println("POST /api/sensor HTTP/1.1");
    client.println("Host: yourapiendpoint.azurewebsites.net");
    client.println("Content-Type: application/json");
    client.println("Content-Length: " + String(postData.length()));
    client.println();
    client.println(postData);

    while (client.available()) {
      String response = client.readString();
      Serial.println(response);
    }

    client.stop();
  }
  delay(60000);  // Send data every minute
}
