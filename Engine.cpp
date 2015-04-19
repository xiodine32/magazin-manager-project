//
// Created by xiodine on 4/15/15.
//

#include "Engine.h"
#include "log.h"
#include "controllers/Controller.h"
#include "controllers/Stats.h"
#include "controllers/Readme.h"
#include "stringR.h"

#include <fstream>

void Engine::run() {
    stringR query;
    do {
        std::cout << "Query (vezi README): ";
        getline(std::cin, query);
        query.toLowerCase();
        Controller *controller = NULL;
        if (query == "stats") {
            controller = new Stats();
        } else if (query == "d") {
            LOG_TOGGLE = !LOG_TOGGLE;
        } else if (query == "readme") {
            controller = new Readme();
        } else {
            if (query != "stop") {
                std::cout << "Nu am inteles!\n";
            }
        }

        if (controller != NULL) {
            controller->run(stoc_);
            delete controller;
        }
    } while (query != "stop");
//    std::vector<std::string> trasaturi;
//    trasaturi.push_back("bruna");
//    trasaturi.push_back("blonda");
//    stoc_.addBun(Bun("Bere", "halba", trasaturi, 0, 15.0, 13.0));
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
