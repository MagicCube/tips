#pragma once

#include <mx_ui.h>

#include "ui/scenes/ClockScene.h"

Scene *testScene;

class TipApp : public Application {
 protected:
  void onInit() override {
    Application::onInit();
    testScene = new ClockScene();
  }

  void onLaunch() override {
    Application::onLaunch();

    testScene->show();
  }
};
