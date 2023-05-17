#include "ESP8266Client.h"

ESP8266Client::ESP8266Client(const char* ssid, const char* password, IPAddress serverIP, uint16_t serverPort)
    : ssid_(ssid), password_(password), serverIP_(serverIP), serverPort_(serverPort) {}

void ESP8266Client::connectToWiFi() {
  WiFi.begin(ssid_, password_);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");
}

void ESP8266Client::connectToServer() {
  if (client_.connect(serverIP_, serverPort_)) {
    Serial.println("Connected to ESP32 server");
  } else {
    Serial.println("Failed to connect to ESP32 server");
  }
}

void ESP8266Client::sendRequest(String data) {
  client_.println(data);
  delay(1000);
}

String ESP8266Client::receiveResponse() {
  String response = client_.readString();
  return response;
}