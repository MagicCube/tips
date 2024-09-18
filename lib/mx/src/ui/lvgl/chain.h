#pragma once

#include "fonts.h"
#include "shortcuts.h"

class MXChain {
 public:
  MXChain(lv_obj_t* obj) : _self(obj) {}

  lv_obj_t* self() { return _self; }
  lv_obj_t* parent() { return lv_obj_get_parent(_self); }

  /* Creation */
  MXChain& label(const char* label = "") {
    _self = lv_label_create(_self);
    text(label);
    return *this;
  }

  MXChain& image(const char* imageSrc = "") {
    _self = lv_img_create(_self);
    src(imageSrc);
    return *this;
  }

  /* Positioning */
  MXChain& left(lv_coord_t x) {
    mx_left(_self, x);
    return *this;
  }
  MXChain& top(lv_coord_t y) {
    mx_top(_self, y);
    return *this;
  }
  MXChain& pos(lv_coord_t x, lv_coord_t y) {
    mx_pos(_self, x, y);
    return *this;
  }

  MXChain& center() {
    mx_center(_self);
    return *this;
  }

  MXChain& center_x() {
    mx_center_x(_self);
    return *this;
  }

  MXChain& center_y() {
    mx_center_y(_self);
    return *this;
  }

  /* Size */
  MXChain& size(lv_coord_t w, lv_coord_t h) {
    mx_size(_self, w, h);
    return *this;
  }

  MXChain& w(lv_coord_t w) {
    mx_w(_self, w);
    return *this;
  }

  MXChain& h(lv_coord_t h) {
    mx_h(_self, h);
    return *this;
  }

  MXChain& w_full() {
    mx_w_full(_self);
    return *this;
  }

  MXChain& h_full() {
    mx_h_full(_self);
    return *this;
  }

  MXChain& size_full() {
    mx_size_full(_self);
    return *this;
  }

  /* Padding */
  MXChain& p(lv_coord_t top, lv_coord_t right, lv_coord_t bottom, lv_coord_t left) {
    mx_p(_self, top, right, bottom, left);
    return *this;
  }

  MXChain& p(lv_coord_t x, lv_coord_t y) {
    mx_p_xy(_self, x, y);
    return *this;
  }

  MXChain& p(lv_coord_t padding) {
    mx_p_all(_self, padding);
    return *this;
  }

  MXChain& p_x(lv_coord_t padding) {
    mx_p_x(_self, padding);
    return *this;
  }

  MXChain& p_y(lv_coord_t padding) {
    mx_p_y(_self, padding);
    return *this;
  }

  /* Background */
  MXChain& bg_color(uint32_t color) {
    mx_bg_color(_self, color);
    return *this;
  }

  /* Rounded */
  MXChain& clip_corner() {
    mx_clip_corner(_self);
    return *this;
  }

  MXChain& rounded(lv_coord_t radius) {
    mx_rounded(_self, radius);
    return *this;
  }

  MXChain& rounded_full() {
    mx_rounded_full(_self);
    return *this;
  }

  /* Text */
  MXChain& text(const char* text) {
    mx_text(_self, text);
    return *this;
  }

  MXChain& text_fmt(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    mx_text_fmt(_self, fmt, args);
    va_end(args);
    return *this;
  }

  MXChain& text_color(uint32_t color) {
    mx_text_color(_self, color);
    return *this;
  }

  MXChain& font_custom(const char* font_name, uint16_t size) {
    if (strcmp(font_name, "montserrat") == 0) {
      if (size == 72) {
        lv_obj_set_style_text_font(_self, &lv_font_montserrat_72, LV_PART_MAIN);
        return *this;
      }
    }
    lv_obj_set_style_text_font(_self, &lv_font_montserrat_24, LV_PART_MAIN);
    return *this;
  }

  MXChain& font(uint16_t size) {
    font_custom("montserrat", size);
    return *this;
  }

  MXChain& src(const char* src) {
    mx_src(_self, src);
    return *this;
  }

 private:
  lv_obj_t* _self;
};

MXChain mx(lv_obj_t* obj) { return MXChain(obj); }
MXChain mx(Scene* scene) { return MXChain(scene->getRoot()); }
