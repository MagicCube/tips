#pragma once

#include <mx_ui.h>

#include "ui/scenes/WiFiConnectScene.h"

Scene *scene;

class TipApp : public Application {
 protected:
  void onInit() override {
    Application::onInit();
    scene = new WiFiConnectScene();
  }

  void onLaunch() override {
    Application::onLaunch();

    scene->show();
  }
};
