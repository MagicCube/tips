#include "hal/wifi/WiFiConnection.h"

#include "shims.h"

static uint64_t timestamp = 0;
static bool connected = false;

void WiFiConnection::begin(const char* ssid, const char* password,
                           std::function<void()> onConnected) {
  timestamp = millis();
  onConnectedHandler = onConnected;
}

void WiFiConnection::begin(const char* ssid,
                           std::function<void()> onConnected) {
  begin(ssid, nullptr, onConnected);
}

void WiFiConnection::disconnect() {
  timestamp = 0;
  connected = false;
}

bool WiFiConnection::isConnected() { return connected; }

void WiFiConnection::checkConnection() {
  if (timestamp == 0) {
    connected = false;
  }
  connected = millis() - timestamp > 1000;
  if (connected) {
    onConnectedHandler();
    onConnectedHandler = nullptr;
  }
}
