#include <lvgl.h>

#define mx_center(obj) lv_obj_center(obj)

#define mx_w(obj, width) lv_obj_set_width(obj, width)
#define mx_h(obj, width) lv_obj_set_height(obj, width)
#define mx_size(obj, width, height) \
  mx_w(obj, width);                 \
  mx_h(obj, height)
#define mx_w_full(obj) lv_obj_set_width(obj, lv_pct(100))
#define mx_h_full(obj) lv_obj_set_height(obj, lv_pct(100))
#define mx_size_full(obj) \
  mx_w_full(obj);         \
  mx_h_full(obj)

#define mx_bg_color(obj, color) lv_obj_set_style_bg_color(obj, lv_color_hex(color), LV_PART_MAIN)

#define mx_clip_corner(obj) lv_obj_set_style_clip_corner(obj, true, LV_PART_MAIN)

#define mx_rounded(obj, radius) lv_obj_set_style_radius(obj, radius, LV_PART_MAIN)
#define mx_rounded_full(obj) mx_rounded(obj, LV_RADIUS_CIRCLE)
