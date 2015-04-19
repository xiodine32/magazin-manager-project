//
// Created by xiodine on 4/18/15.
//

#include "ControllerStats.h"
#include "../log.h"
#include "../views/ViewConsole.h"

ControllerStats::ControllerStats() {
    d("ControllerStats");
}

ControllerStats::~ControllerStats() {
    d("ControllerStats ended");
}


void ControllerStats::run(ModelStoc &stoc) {

    ViewConsole &con = ViewConsole::getSingleton();

    typedef std::vector<const ModelBun *> vect;

    vect elemente = stoc.getBunuriPointer();
    for (vect::const_iterator i = elemente.begin(); i != elemente.end(); ++i) {
        const ModelBun *bun = (*i);
        con << "Bun: " << bun->getNume() << "\n";
        con << "ModelStoc: " << bun->getStoc() << "\n";
        con << "\n";
    }
}
