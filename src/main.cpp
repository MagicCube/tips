#include <Arduino.h>
#include <lvgl.h>

// Always include `pin_conf.h` first
#include "pins.h"

// Then comes the `lv_conf.h`
#include "lv_conf.h"

// MX Framework
#include "mx_display.h"

// Others
#include "drivers.h"

Display display;

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

  lv_obj_set_style_bg_color(lv_scr_act(), lv_color_hex(0x00ff00), 0);
}

void loop() {
  display.update();

  wakeUp();
}
