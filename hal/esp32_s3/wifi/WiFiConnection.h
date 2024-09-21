#include <WiFi.h>

#include "hal/wifi/WiFiConnection.h"

void WiFiConnection::begin(const char* ssid) { WiFi.begin(ssid); }
void WiFiConnection::begin(const char* ssid, const char* password) {
  WiFi.begin(ssid, password);
}
void WiFiConnection::disconnect() { WiFi.disconnect(); }
bool WiFiConnection::isConnected() { return WiFi.status() == WL_CONNECTED; }
