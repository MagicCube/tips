#pragma once

#include <lvgl.h>

#include "../Updatable.h"
#include "drivers/st77916/st77916_lv_8.h"

class Display : public Updatable {
 public:
  virtual void begin() override {
    initDrivers();
    resetDisplay();
  }

  virtual void setRotation(uint8_t rotation) {
    if (rotation > 3) return;
    if (lcd == NULL) return;

    switch (rotation) {
      case 1:  // 顺时针90度
        lcd->swapXY(true);
        lcd->mirrorX(true);
        lcd->mirrorY(false);
        break;
      case 2:
        lcd->swapXY(false);
        lcd->mirrorX(true);
        lcd->mirrorY(true);
        break;
      case 3:
        lcd->swapXY(true);
        lcd->mirrorX(false);
        lcd->mirrorY(true);
        break;
      default:
        lcd->swapXY(false);
        lcd->mirrorX(false);
        lcd->mirrorY(false);
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

 protected:
  virtual void initDrivers() { lv_st77916_init(); }

  virtual void resetDisplay() {
    switchBacklightOn();
    setRotation(1);
    clear();
  }
};
