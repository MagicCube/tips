#pragma once

class WiFiConnection {
 public:
  static WiFiConnection* singleton() {
    static WiFiConnection connection;
    return &connection;
  }

  void begin(const char* ssid);
  void begin(const char* ssid, const char* password);
  void disconnect();
  bool isConnected();
};
