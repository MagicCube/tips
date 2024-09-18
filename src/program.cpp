#include "ui/App.h"

TipApp *app = nullptr;

void mx_setup() {
  // Start application immediately
  app = new TipApp();
  app->start();
}

void mx_loop() {
  // Update application periodically
  app->update();
}
