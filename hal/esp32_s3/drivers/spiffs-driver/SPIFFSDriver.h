#pragma once

#include "bridge.h"

class SPIFFSDriver : public Component {
 protected:
  void onInit() override {
    Component::onInit();

    SPIFFS.begin(true);

    static lv_fs_drv_t drv;
    lv_fs_drv_init(&drv);

    drv.letter = 'A';
    drv.cache_size = 0;

    drv.ready_cb = nullptr;
    drv.open_cb = __lv_fs_spiffs_open_cb;
    drv.close_cb = __lv_fs_spiffs_close_cb;
    drv.read_cb = __lv_fs_spiffs_read_cb;
    drv.write_cb = __lv_fs_spiffs_write_cb;
    drv.seek_cb = __lv_fs_spiffs_seek_cb;
    drv.tell_cb = __lv_fs_spiffs_tell_cb;

    drv.dir_open_cb = __lv_fs_spiffs_dir_open_cb;
    drv.dir_read_cb = __lv_fs_spiffs_dir_read_cb;
    drv.dir_close_cb = __lv_fs_spiffs_dir_close_cb;

    drv.user_data = nullptr;

    lv_fs_drv_register(&drv);
  }
};