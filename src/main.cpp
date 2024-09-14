#include <Arduino.h>
#include <lvgl.h>

// Always include `pin_conf.h` first
#include "pins.h"

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

// To keep the serial port always alive
long __lastWakeUpTime = 0;
void wakeUp() {
  if (millis() - __lastWakeUpTime > 1000) {
    __lastWakeUpTime = millis();
    Serial.println(".");
  }
}

void setup() {
  delay(200);

  Serial.begin(115200);
  display.begin();
  display.setBrightness(10);

  defaultScene = new DefaultScene();
  defaultScene->begin();
  defaultScene->show();
}

void loop() {
  display.update();

  wakeUp();
}
