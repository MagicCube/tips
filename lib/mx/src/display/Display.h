#pragma once

#include <lvgl.h>

#include "../Updatable.h"
#include "drivers/st77916/st77916.h"

class Display : public Updatable {
 public:
  void begin() override {
    scr_lvgl_init();
    switchBacklightOn();
    setRotation(1);
    clear();
  }

  void setRotation(uint8_t rotation) {
    if (rotation > 3) return;
    if (lcd == NULL || touch == NULL) return;

    switch (rotation) {
      case 1:  // 顺时针90度
        lcd->swapXY(true);
        lcd->mirrorX(true);
        lcd->mirrorY(false);
        touch->swapXY(true);
        touch->mirrorX(true);
        touch->mirrorY(false);
        break;
      case 2:
        lcd->swapXY(false);
        lcd->mirrorX(true);
        lcd->mirrorY(true);
        touch->swapXY(false);
        touch->mirrorX(true);
        touch->mirrorY(true);
        break;
      case 3:
        lcd->swapXY(true);
        lcd->mirrorX(false);
        lcd->mirrorY(true);
        touch->swapXY(true);
        touch->mirrorX(false);
        touch->mirrorY(true);
        break;
      default:
        lcd->swapXY(false);
        lcd->mirrorX(false);
        lcd->mirrorY(false);
        touch->swapXY(false);
        touch->mirrorX(false);
        touch->mirrorY(false);
        break;
    }
  }

  void switchBacklightOn() { backlight->on(); }

  void switchBacklightOff() { backlight->off(); }

  void setBrightness(uint8_t brightness) {
    if (NULL == backlight) {
      return;
    }
    backlight->setBrightness(brightness);
  }

  void update() override {
    lv_task_handler();
    vTaskDelay(5);
  }

  void clear(lv_color_t color = lv_color_hex(0x000000)) {
    lv_obj_set_style_bg_color(lv_scr_act(), color, 0);
  }
};
