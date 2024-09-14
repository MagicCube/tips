#pragma once

#include <lvgl.h>

#include "../Updatable.h"
#include "drivers/st77916/st77916.h"

class Display : public Updatable {
 public:
  void begin() override { scr_lvgl_init(); }

  void switchOn() { screen_switch(true); }

  void switchOff() { screen_switch(false); }

  void setBrightness(uint8_t brightness) { set_brightness(brightness); }

  void update() override {
    lv_task_handler();
    vTaskDelay(5);
  }
};
