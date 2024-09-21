#pragma once

#include <mx_ui.h>

#include "ui/scenes/ClockScene.h"
#include "ui/scenes/WiFiConnectScene.h"

Scene *scene;

class TipApp : public Application {
 protected:
  void onInit() override {
    Application::onInit();

    static WiFiConnectScene *connectScene = new WiFiConnectScene();
    connectScene->show();
    WiFiConnection::singleton()->begin("Henry's iPhone 14 Pro", "13913954971",
                                       []() {
                                         scene = new ClockScene();
                                         scene->show();
                                       });
  }
};
