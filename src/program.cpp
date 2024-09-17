#include <mx_ui.h>

#include "ui/DefaultScene.h"

Scene *getDefaultScene() {
  static Scene *defaultScene = new DefaultScene();
  return defaultScene;
}
