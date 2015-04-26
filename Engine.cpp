//
// Created by xiodine on 4/15/15.
//

#include "Engine.h"
#include "log.h"
#include "controllers/Controller.h"
#include "controllers/ControllerStats.h"
#include "controllers/ControllerReadme.h"
#include "controllers/ControllerAdauga.h"
#include "views/ViewConsole.h"
#include "controllers/ControllerGoale.h"

#include <fstream>

void Engine::run() {
    ViewConsole &con = ViewConsole::getSingleton();
    ViewConsole::queryOptions_t options;
    options.push_back("stop");
    options.push_back("adauga");
    options.push_back("comanda");
    options.push_back("stats");
    options.push_back("goale");
    options.push_back("readme");
    std::string query;
    do {
        query = con.quizUser("Query?", options);
        Controller *controller = NULL;
        if (query == "stats") {
            controller = new ControllerStats();
        } else if (query == "d") {
            LOG_TOGGLE = !LOG_TOGGLE;
        } else if (query == "readme") {
            controller = new ControllerReadme();
        } else if (query == "adauga") {
            controller = new ControllerAdauga();
        } else if (query == "goale") {
            controller = new ControllerGoale();
        }

        if (controller != NULL) {
            controller->run(stoc_);
            delete controller;
        }
    } while (query != "stop");
//    std::vector<std::string> trasaturi;
//    trasaturi.push_back("bruna");
//    trasaturi.push_back("blonda");
//    stoc_.addBun(ModelBun("Bere", "halba", trasaturi, 0, 15.0, 13.0));
}

void Engine::load() {
    d("");
    std::ifstream input("data/models.dat");
    stoc_.loadSettings(input);
}

Engine::Engine() {
    d("engine started");
    load();
}

Engine::~Engine() {
    std::ofstream output("data/models.dat");
    stoc_.saveSettings(output);
    d("engine stopped");
}
