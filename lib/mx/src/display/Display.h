#pragma once

#include <lvgl.h>

#include "../Updatable.h"
#include "drivers/st77916/st77916.h"

class Display : public Updatable {
 public:
  void begin() override {
    scr_lvgl_init();
    clear();
  }

  void switchOn() { screen_switch(true); }

  void switchOff() { screen_switch(false); }

  void setBrightness(uint8_t brightness) { set_brightness(brightness); }

  void update() override {
    lv_task_handler();
    vTaskDelay(5);
  }

  void clear(lv_color_t color = lv_color_hex(0x000000)) {
    lv_obj_set_style_bg_color(lv_scr_act(), color, 0);
  }
};
