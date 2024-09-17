#include "Component.h"

void Component::begin() {
  if (initialized) {
    return;
  }

  onInit();

  initialized = true;
};

void Component::update() {
  willUpdate();
  onUpdate();
  didUpdate();
}
