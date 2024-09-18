#include <Arduino.h>
#include <SPIFFS.h>
#include <WiFi.h>
#include <lvgl.h>

// Always include `device_conf.h` first
#include "device_conf.h"

// Hardwares
#include "hardwares/cst816/cst816_lv_8.h"
#include "hardwares/st77916/st77916_lv_8.h"

// Drivers
#include "drivers/display/TouchDisplay.h"
#include "drivers/spiffs-driver/SPIFFSDriver.h"

TouchDisplay display;
SPIFFSDriver spiffsDriver;

void mx_setup();
void mx_loop();

void initLogging() {
  lv_log_register_print_cb([](const char* buf) { Serial.print(buf); });
}

void initHardwares() {
  lv_st77916_init();
  lv_cst816_init();
}

void initDrivers() {
  display.begin();
  display.setBrightness(66);

  spiffsDriver.begin();
}

void initWiFi() {
  WiFi.begin("Henry's iPhone 14 Pro", "13913954971");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void setup() {
  Serial.begin(115200);
  Serial.println("Welcome to Tips");

  initLogging();
  initHardwares();
  initDrivers();

  mx_setup();

  LV_LOG_INFO("Tips is now started");
}

void loop() {
  mx_loop();
  display.update();
}
