#include <Arduino.h>
#include <lvgl.h>

// Always include `device_conf.h` first
#include "device_conf.h"
#include "lv_conf.h"

// Drivers
#include "drivers/cst816/cst816_lv_8.h"
#include "drivers/st77916/st77916_lv_8.h"

// MX Framework
#include "mx_conf.h"
#include "mx_display.h"
#include "mx_ui.h"

// Application
#include "ui/DefaultScene.h"

TouchDisplay display;
DefaultScene *defaultScene = nullptr;

void initDrivers() {
  lv_st77916_init();
  lv_cst816_init();
}

void setup() {
  delay(200);

  Serial.begin(115200);
  Serial.println("Tips is starting...");

  initDrivers();

  display.begin();
  display.setBrightness(10);

  defaultScene = new DefaultScene();
  defaultScene->begin();
  defaultScene->show();

  Serial.println("Tips is now started");
}

void loop() { display.update(); }
