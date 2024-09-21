#include "hal/wifi/WiFiConnection.h"

#include "shims.h"

static uint64_t timestamp = 0;

void WiFiConnection::begin(const char* ssid, const char* password) {
  timestamp = millis();
}

void WiFiConnection::begin(const char* ssid) {}

void WiFiConnection::disconnect() { timestamp = 0; }

bool WiFiConnection::isConnected() {
  if (timestamp == 0) {
    return false;
  }

  return millis() - timestamp > 1000;
}
