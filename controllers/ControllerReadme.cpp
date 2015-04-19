//
// Created by xiodine on 4/19/15.
//

#include "ControllerReadme.h"
#include "../views/ViewConsole.h"
#include "../models/ModelReadme.h"


ControllerReadme::ControllerReadme() : Controller() {

}

ControllerReadme::~ControllerReadme() {

}

void ControllerReadme::run(ModelStoc &stoc) {
    ViewConsole &out = ViewConsole::getSingleton();

    ModelReadme readme;

    out << readme.getAll();

}
