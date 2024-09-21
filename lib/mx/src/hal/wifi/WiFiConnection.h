#pragma once

#include <functional>

class WiFiConnection {
 public:
  static WiFiConnection* singleton() {
    static WiFiConnection* connection = new WiFiConnection();
    return connection;
  }

  void begin(const char* ssid, std::function<void()> onConnected = nullptr);
  void begin(const char* ssid, const char* password,
             std::function<void()> onConnected = nullptr);
  void disconnect();
  bool isConnected();
  void checkConnection();

 protected:
  std::function<void()> onConnectedHandler = nullptr;
};
