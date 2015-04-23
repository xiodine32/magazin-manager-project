//
// Created by xiodine on 4/19/15.
//

#include "ControllerAdauga.h"
#include "../views/ViewConsole.h"
#include "ControllerStats.h"
#include "../stringR.h"
#include "ControllerAdaugaProdusNou.h"
#include "ControllerAdaugaRefill.h"

ControllerAdauga::ControllerAdauga() : Controller() {

}

ControllerAdauga::~ControllerAdauga() {

}

void ControllerAdauga::run(ModelStoc &stoc) {

    ViewConsole &con = ViewConsole::getSingleton();

    ControllerStats stats;
    stats.run(stoc);

    ViewConsole::queryOptions_t options;
    options.push_back("stop");
    options.push_back("nou");
    options.push_back("refill");

    stringR ce;

    do {
        ce = con.quizUser("Query?", options);
        ce.toLowerCase();
        if (ce == "nou") {
            ControllerAdaugaProdusNou controllerAdaugaProdusNou;
            controllerAdaugaProdusNou.run(stoc);
        } else if (ce == "refill") {
            ControllerAdaugaRefill controllerAdaugaRefill;
            controllerAdaugaRefill.run(stoc);
        } else if (ce == "stop") {

        }
    } while (ce != "stop");

}
