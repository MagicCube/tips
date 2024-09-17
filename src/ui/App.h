#pragma once

#include <mx_ui.h>

#include "ui/scenes/TestScene.h"

Scene *testScene;

class TipApp : public Application {
 protected:
  void onInit() override {
    Application::onInit();
    testScene = new TestScene();
  }

  void onLaunch() override {
    Application::onLaunch();

    testScene->show();
  }
};
