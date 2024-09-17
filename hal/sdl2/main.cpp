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

void init_frame() {
  lv_obj_t* frame = lv_scr_act();
  lv_obj_set_size(frame, 360, 360);
  lv_obj_set_flex_flow(frame, LV_FLEX_FLOW_COLUMN);
  lv_obj_set_style_radius(frame, LV_RADIUS_CIRCLE, 0);
  lv_obj_set_style_clip_corner(frame, true, 0);
  lv_obj_set_scroll_dir(frame, LV_DIR_VER);
  lv_obj_set_scroll_snap_y(frame, LV_SCROLL_SNAP_CENTER);
  lv_obj_set_scrollbar_mode(frame, LV_SCROLLBAR_MODE_OFF);

  lv_obj_set_style_border_width(frame, 1, 0);
  lv_obj_set_style_border_color(frame, lv_color_hex(0xFF0000), 0);
}

int main(void) {
  lv_init();

  hal_setup();

  init_frame();
  bootstrap();

  while (1) {
    hal_loop();
  }
}
