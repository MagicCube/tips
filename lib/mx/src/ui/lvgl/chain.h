#pragma once

#include "fonts.h"
#include "shortcuts.h"

class MXChain {
  lv_obj_t* obj;

 public:
  MXChain(lv_obj_t* obj) : obj(obj) {}

  lv_obj_t* self() { return obj; }
  lv_obj_t* parent() { return lv_obj_get_parent(obj); }

  /* Creation */
  MXChain& label(const char* label = "") {
    obj = lv_label_create(obj);
    text(label);
    return *this;
  }

  MXChain& image(const char* imageSrc = "") {
    obj = lv_img_create(obj);
    src(imageSrc);
    return *this;
  }

  /* Positioning */
  MXChain& left(lv_coord_t x) {
    mx_left(obj, x);
    return *this;
  }
  MXChain& top(lv_coord_t y) {
    mx_top(obj, y);
    return *this;
  }
  MXChain& pos(lv_coord_t x, lv_coord_t y) {
    mx_pos(obj, x, y);
    return *this;
  }

  MXChain& center() {
    mx_center(obj);
    return *this;
  }

  MXChain& center_x() {
    mx_center_x(obj);
    return *this;
  }

  MXChain& center_y() {
    mx_center_y(obj);
    return *this;
  }

  /* Size */
  MXChain& size(lv_coord_t w, lv_coord_t h) {
    mx_size(obj, w, h);
    return *this;
  }

  MXChain& w(lv_coord_t w) {
    mx_w(obj, w);
    return *this;
  }

  MXChain& h(lv_coord_t h) {
    mx_h(obj, h);
    return *this;
  }

  MXChain& w_full() {
    mx_w_full(obj);
    return *this;
  }

  MXChain& h_full() {
    mx_h_full(obj);
    return *this;
  }

  MXChain& size_full() {
    mx_size_full(obj);
    return *this;
  }

  /* Padding */
  MXChain& p(lv_coord_t top, lv_coord_t right, lv_coord_t bottom, lv_coord_t left) {
    mx_p(obj, top, right, bottom, left);
    return *this;
  }

  MXChain& p_all(lv_coord_t padding) {
    mx_p_all(obj, padding);
    return *this;
  }

  MXChain& p_x(lv_coord_t padding) {
    mx_p_x(obj, padding);
    return *this;
  }

  MXChain& p_y(lv_coord_t padding) {
    mx_p_y(obj, padding);
    return *this;
  }

  MXChain& p_xy(lv_coord_t x, lv_coord_t y) {
    mx_p_xy(obj, x, y);
    return *this;
  }

  /* Background */
  MXChain& bg_color(uint32_t color) {
    mx_bg_color(obj, color);
    return *this;
  }

  /* Rounded */
  MXChain& clip_corner() {
    mx_clip_corner(obj);
    return *this;
  }

  MXChain& rounded(lv_coord_t radius) {
    mx_rounded(obj, radius);
    return *this;
  }

  MXChain& rounded_full() {
    mx_rounded_full(obj);
    return *this;
  }

  /* Text */
  MXChain& text(const char* text) {
    mx_text(obj, text);
    return *this;
  }

  MXChain& text_fmt(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    mx_text_fmt(obj, fmt, args);
    va_end(args);
    return *this;
  }

  MXChain& text_color(uint32_t color) {
    mx_text_color(obj, color);
    return *this;
  }

  MXChain& font_custom(const char* font_name, uint16_t size) {
    if (strcmp(font_name, "montserrat") == 0) {
      if (size == 72) {
        lv_obj_set_style_text_font(obj, &lv_font_montserrat_72, LV_PART_MAIN);
        return *this;
      }
    }
    lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN);
    return *this;
  }

  MXChain& font(uint16_t size) {
    font_custom("montserrat", size);
    return *this;
  }

  MXChain& src(const char* src) {
    mx_src(obj, src);
    return *this;
  }
};

MXChain mx(lv_obj_t* obj) { return MXChain(obj); }
MXChain mx(Scene* scene) { return MXChain(scene->getRoot()); }
