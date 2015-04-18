//
// Created by xiodine on 4/15/15.
//

#include "Controller.h"
#include "../log.h"

Controller::Controller() {
    d("Controller spawned");
}
Controller::~Controller() {
    d("Controller despawned");
}

void Controller::run() {
    d("Controller running");
}
