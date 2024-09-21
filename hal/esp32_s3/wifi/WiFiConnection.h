#include <WiFi.h>

#include <functional>

#include "hal/wifi/WiFiConnection.h"

void WiFiConnection::begin(const char* ssid,
                           std::function<void()> onConnected) {
  WiFi.begin(ssid);
  onConnectedHandler = onConnected;
}

void WiFiConnection::begin(const char* ssid, const char* password,
                           std::function<void()> onConnected) {
  WiFi.begin(ssid, password);
  onConnectedHandler = onConnected;
}

void WiFiConnection::disconnect() { WiFi.disconnect(); }

bool WiFiConnection::isConnected() { return WiFi.status() == WL_CONNECTED; }

void WiFiConnection::checkConnection() {
  if (WiFi.status() == WL_CONNECTED) {
    onConnectedHandler();
    onConnectedHandler = nullptr;
  }
}
