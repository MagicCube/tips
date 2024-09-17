#pragma once

class Screen {
 public:
  ~Screen() {}

  static Screen *getMain() { return _main; }

  int getWidth() { return lv_disp_get_hor_res(_display); }

  int getHeight() { return lv_disp_get_ver_res(_display); }

 protected:
  Screen(lv_disp_t *display) { _display = display; }

 private:
  static Screen *_main;
  lv_disp_t *_display;
};

Screen *Screen::_main = new Screen(nullptr);
