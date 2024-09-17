/**
 ******************************************************************************
 * @file    main.c
 * @author  Ac6
 * @version V1.0
 * @date    01-December-2013
 * @brief   Default main function.
 ******************************************************************************
 */

#include <lvgl.h>
#include <mx_ui.h>

#include "app_hal.h"

Scene* getDefaultScene();

int main(void) {
  lv_init();

  hal_setup();

  Scene* defaultScene = getDefaultScene();
  if (defaultScene != nullptr) {
    defaultScene->begin();
    defaultScene->show();
  }

  while (1) {
    hal_loop();
  }
}
