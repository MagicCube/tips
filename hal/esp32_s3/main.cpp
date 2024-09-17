#include <Arduino.h>
#include <lvgl.h>

// Always include `device_conf.h` first
#include "device_conf.h"

// Hardwares
#include "hardwares/cst816/cst816_lv_8.h"
#include "hardwares/st77916/st77916_lv_8.h"

// Drivers
#include "drivers/display/TouchDisplay.h"

TouchDisplay display;

void bootstrap();

void initHardwares() {
  lv_st77916_init();
  lv_cst816_init();
}

void initDrivers() {
  display.begin();
  display.setBrightness(10);
}

void setup() {
  delay(200);

  Serial.begin(115200);
  Serial.println("Tips is starting...");

  initHardwares();
  initDrivers();

  bootstrap();

  Serial.println("Tips is now started");
}

void loop() { display.update(); }
