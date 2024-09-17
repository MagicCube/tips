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

void mx_setup();
void mx_loop();

int main(void) {
  lv_init();

  hal_setup();

  mx_setup();

  while (1) {
    mx_loop();
    hal_loop();
  }
}
