/**
 ******************************************************************************
 * @file    main.c
 * @author  Ac6
 * @version V1.0
 * @date    01-December-2013
 * @brief   Default main function.
 ******************************************************************************
 */

#include "app_hal.h"
#include "lvgl.h"

void bootstrap();

int main(void) {
  lv_init();

  hal_setup();

  bootstrap();

  while (1) {
    hal_loop();
  }
}
