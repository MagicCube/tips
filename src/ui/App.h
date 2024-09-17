#pragma once

#include <mx_ui.h>

#include "ui/scenes/TestScene.h"

Scene *testScene;

class App : public Application {
 protected:
  void onInit() override {
    Application::onInit();
    testScene = new TestScene();
    testScene->begin();
  }

  void onLaunch() override {
    Application::onLaunch();

    activateScene(testScene);
  }
};
