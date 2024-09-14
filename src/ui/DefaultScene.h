#pragma once

#include <mx_ui.h>

#include "fonts.h"

class DefaultScene : public Scene {
 private:
  lv_obj_t* _speedLabel = nullptr;

 public:
  void init() override {
    Scene::init();

    lv_obj_clear_flag(this->root, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_flex_flow(this->root, LV_FLEX_FLOW_COLUMN);

    _applyContainerStyle(this->root);

    lv_obj_t* header = lv_obj_create(this->root);
    lv_obj_set_size(header, LV_PCT(100), 96);
    _applyContainerStyle(header);
    // lv_obj_set_style_border_width(header, 2, LV_PART_MAIN);
    // lv_obj_set_style_border_side(header, LV_BORDER_SIDE_BOTTOM,
    // LV_PART_MAIN);

    lv_obj_t* body = lv_obj_create(this->root);
    lv_obj_set_size(body, LV_PCT(100), LV_SIZE_CONTENT);
    _applyContainerStyle(body);

    lv_obj_t* footer = lv_obj_create(this->root);
    lv_obj_set_size(footer, LV_PCT(100), 84);
    _applyContainerStyle(footer);

    this->_initSpeedLabel(body);

    this->initialized = true;
  }

  void update() override {
    Scene::update();

    if (this->initialized) {
      // lv_label_set_text(_speedLabel,
      //                   timeClient.getFormattedTime().substring(0,
      //                   5).c_str());
    }
  }

 private:
  void _initSpeedLabel(lv_obj_t* parent) {
    _speedLabel = lv_label_create(parent);

    lv_label_set_text(_speedLabel, "--:00");

    static lv_style_t style;
    lv_style_init(&style);
    lv_style_set_text_color(&style, lv_color_hex(0xffffff));
    lv_style_set_text_font(&style, &orbitron_medium_96);
    lv_obj_add_style(_speedLabel, &style, LV_PART_MAIN);
    lv_obj_align(_speedLabel, LV_ALIGN_CENTER, 0, 0);
  }

  void _applyContainerStyle(lv_obj_t* container) {
    lv_obj_set_scrollbar_mode(container, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_style_pad_row(container, 0, LV_PART_MAIN);
    lv_obj_set_style_border_width(container, 0, LV_PART_MAIN);
    lv_obj_set_style_bg_color(container, lv_color_hex(0x000000), LV_PART_MAIN);
  }
};
