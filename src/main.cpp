#include <Arduino.h>
#include <lvgl.h>

// Always include `pin_conf.h` first
#include "pins.h"

// MX Framework
#include "mx_display.h"
#include "mx_ui.h"

// Application
#include "ui/DefaultScene.h"

Display display;
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
  display.setBrightness(20);

  defaultScene = new DefaultScene();
  SceneManager::getInstance().activateScene(defaultScene);
}

void loop() {
  display.update();

  wakeUp();
}
