#include "ui/App.h"

TipApp app;

void mx_bootstrap() {
  // Start application immediately
  app.start();
}

void mx_loop() {
  // Update application periodically
  app.update();
}
