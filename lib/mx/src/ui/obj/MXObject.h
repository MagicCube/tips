#pragma once

#include <lvgl.h>

#include <algorithm>

class Scene;

class MXObject {
 public:
  MXObject(lv_obj_t* obj) : _internalObj(obj) {}
  ~MXObject() {
    if (_internalObj != nullptr) {
      lv_obj_del(_internalObj);
    }
    _internalObj = nullptr;
  }

  MXObject* ptr() { return this; }
  lv_obj_t* lv_obj() { return _internalObj; }
  lv_obj_t* parent() { return lv_obj_get_parent(_internalObj); }

  /* Creation */
  MXObject& label(const char* label = "") {
    _internalObj = lv_label_create(_internalObj);
    text(label);
    return *this;
  }

  MXObject& image(const char* imageSrc = "") {
    _internalObj = lv_img_create(_internalObj);
    src(imageSrc);
    return *this;
  }

  MXObject& spinner(const lv_coord_t diameter = -1,
                    const uint16_t period = 2000, const uint16_t arc = 60) {
    _internalObj = lv_spinner_create(_internalObj, period, arc);
    auto d = diameter;
    if (d < 0) {
      auto parent = _internalObj->parent;
      auto parentW = lv_obj_get_width(parent);
      auto parentH = lv_obj_get_height(parent);
      d = std::min(parentW, parentH);
      center();
    }
    lv_obj_set_size(_internalObj, d, d);
    return *this;
  }

  /* Positioning */
  lv_coord_t x() { return lv_obj_get_x(_internalObj); }
  MXObject& x(lv_coord_t x) {
    lv_obj_set_x(_internalObj, x);
    return *this;
  }
  lv_coord_t y() { return lv_obj_get_y(_internalObj); }
  MXObject& y(lv_coord_t y) {
    lv_obj_set_y(_internalObj, y);
    return *this;
  }
  MXObject& pos(lv_coord_t x, lv_coord_t y) {
    lv_obj_set_pos(_internalObj, x, y);
    return *this;
  }

  MXObject& center() {
    lv_obj_center(_internalObj);
    return *this;
  }

  MXObject& center_x() {
    lv_obj_align(_internalObj, LV_ALIGN_TOP_MID, 0, 0);
    return *this;
  }

  MXObject& center_y() {
    lv_obj_align(_internalObj, LV_ALIGN_LEFT_MID, 0, 0);
    return *this;
  }

  /* Size */
  MXObject& size(lv_coord_t width, lv_coord_t height) {
    lv_obj_set_size(_internalObj, width, height);
    return *this;
  }

  lv_coord_t w() { return lv_obj_get_width(_internalObj); }
  MXObject& w(lv_coord_t width) {
    lv_obj_set_width(_internalObj, width);
    return *this;
  }

  lv_coord_t h() { return lv_obj_get_width(_internalObj); }
  MXObject& h(lv_coord_t height) {
    lv_obj_set_height(_internalObj, height);
    return *this;
  }

  MXObject& w_full() {
    lv_obj_set_width(_internalObj, lv_pct(100));
    return *this;
  }

  MXObject& h_full() {
    lv_obj_set_height(_internalObj, lv_pct(100));
    return *this;
  }

  MXObject& size_full() {
    lv_obj_set_size(_internalObj, lv_pct(100), lv_pct(100));
    return *this;
  }

  /* Padding */
  MXObject& p(lv_coord_t top, lv_coord_t right, lv_coord_t bottom,
              lv_coord_t left) {
    lv_obj_set_style_pad_top(_internalObj, top, LV_PART_MAIN);
    lv_obj_set_style_pad_right(_internalObj, right, LV_PART_MAIN);
    lv_obj_set_style_pad_bottom(_internalObj, bottom, LV_PART_MAIN);
    lv_obj_set_style_pad_left(_internalObj, left, LV_PART_MAIN);
    return *this;
  }

  MXObject& p(lv_coord_t x, lv_coord_t y) {
    p(y, x, y, x);
    return *this;
  }

  MXObject& p(lv_coord_t padding) {
    p(padding, padding, padding, padding);
    return *this;
  }

  MXObject& p_x(lv_coord_t padding) {
    lv_obj_set_style_pad_hor(_internalObj, padding, LV_PART_MAIN);
    return *this;
  }

  MXObject& p_y(lv_coord_t padding) {
    lv_obj_set_style_pad_ver(_internalObj, padding, LV_PART_MAIN);
    return *this;
  }

  /* Background */
  MXObject& bg_color(uint32_t color) {
    lv_obj_set_style_bg_color(_internalObj, lv_color_hex(color), LV_PART_MAIN);
    return *this;
  }

  /* Rounded */
  MXObject& clip_corner() {
    lv_obj_set_style_clip_corner(_internalObj, true, LV_PART_MAIN);
    return *this;
  }

  MXObject& rounded(lv_coord_t radius) {
    lv_obj_set_style_radius(_internalObj, radius, LV_PART_MAIN);
    return *this;
  }

  MXObject& rounded_full() {
    rounded(LV_RADIUS_CIRCLE);
    return *this;
  }

  /* Text */
  const char* text() { return lv_label_get_text(_internalObj); }
  MXObject& text(const char* text) {
    lv_label_set_text(_internalObj, text);
    return *this;
  }

  MXObject& text_fmt(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    lv_label_set_text_fmt(_internalObj, fmt, args);
    va_end(args);
    return *this;
  }

  MXObject& text_color(uint32_t color) {
    lv_obj_set_style_text_color(_internalObj, lv_color_hex(color),
                                LV_PART_MAIN);
    return *this;
  }

  MXObject& font(const lv_font_t* font) {
    lv_obj_set_style_text_font(_internalObj, font, LV_PART_MAIN);
    return *this;
  }

  const void* src() { return lv_img_get_src(_internalObj); }
  MXObject& src(const char* src) {
    lv_img_set_src(_internalObj, src);
    return *this;
  }

 private:
  lv_obj_t* _internalObj;
};

MXObject* mx(lv_obj_t* obj);
MXObject* mx(MXObject* obj);
MXObject* mx(Scene* scene);
MXObject* mx();
