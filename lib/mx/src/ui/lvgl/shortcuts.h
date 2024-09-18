#include <lvgl.h>

#define mx_left(obj, x) lv_obj_set_x(obj, x)
#define mx_top(obj, y) lv_obj_set_y(obj, y)
#define mx_pos(obj, y) lv_obj_set_pos(obj, x, y)

#define mx_center(obj) lv_obj_center(obj)
#define mx_center_x(obj) lv_obj_align(obj, LV_ALIGN_TOP_MID, 0, 0);
#define mx_center_y(obj) lv_obj_align(obj, LV_ALIGN_LEFT_MID, 0, 0);

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

#define mx_p(obj, top, right, bottom, left)               \
  lv_obj_set_style_pad_top(obj, top, LV_PART_MAIN);       \
  lv_obj_set_style_pad_right(obj, right, LV_PART_MAIN);   \
  lv_obj_set_style_pad_bottom(obj, bottom, LV_PART_MAIN); \
  lv_obj_set_style_pad_left(obj, left, LV_PART_MAIN);
#define mx_p_all(obj, padding) lv_obj_set_style_pad_all(obj, padding, LV_PART_MAIN)
#define mx_p_x(obj, padding) lv_obj_set_style_pad_hor(obj, padding, LV_PART_MAIN)
#define mx_p_y(obj, padding) lv_obj_set_style_pad_ver(obj, padding, LV_PART_MAIN)
#define mx_p_xy(obj, x, y) \
  mx_p_x(x);               \
  mx_p_y(y)

#define mx_bg_color(obj, color) lv_obj_set_style_bg_color(obj, lv_color_hex(color), LV_PART_MAIN)

#define mx_clip_corner(obj) lv_obj_set_style_clip_corner(obj, true, LV_PART_MAIN)

#define mx_rounded(obj, radius) lv_obj_set_style_radius(obj, radius, LV_PART_MAIN)
#define mx_rounded_full(obj) mx_rounded(obj, LV_RADIUS_CIRCLE)

#define mx_text(obj, text) lv_label_set_text(obj, text)
#define mx_text_color(obj, color) lv_obj_set_style_text_color(obj, lv_color_hex(color), LV_PART_MAIN)
#define mx_font_custom(obj, font_name, size) lv_obj_set_style_text_font(obj, &lv_font_##font_name##_##size, LV_PART_MAIN)
#define mx_font(obj, size) mx_font_custom(obj, montserrat, size)

#define mx_img(obj, path) lv_img_set_src(obj, path)
