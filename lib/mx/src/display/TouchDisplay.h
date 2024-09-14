#pragma once

#include "Display.h"
#include "drivers/cst816/cst816_lv_8.h"

class TouchDisplay : public Display {
 public:
  void setRotation(uint8_t rotation) override {
    Display::setRotation(rotation);

    if (rotation > 3) return;
    if (lcd == NULL || touch == NULL) return;

    switch (rotation) {
      case 1:  // 顺时针90度
        touch->swapXY(true);
        touch->mirrorX(true);
        touch->mirrorY(false);
        break;
      case 2:
        touch->swapXY(false);
        touch->mirrorX(true);
        touch->mirrorY(true);
        break;
      case 3:
        touch->swapXY(true);
        touch->mirrorX(false);
        touch->mirrorY(true);
        break;
      default:
        touch->swapXY(false);
        touch->mirrorX(false);
        touch->mirrorY(false);
        break;
    }
  }

 protected:
  void initDrivers() override {
    Display::initDrivers();

    lv_cst816_init();
  }
};
