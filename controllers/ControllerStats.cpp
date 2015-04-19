//
// Created by xiodine on 4/18/15.
//

#include "ControllerStats.h"
#include "../log.h"

ControllerStats::ControllerStats() {
    d("ControllerStats");
}

ControllerStats::~ControllerStats() {
    d("ControllerStats ended");
}


void ControllerStats::run(ModelStoc &stoc) {

    typedef std::vector<const ModelBun *> vect;

    vect elemente = stoc.getBunuriPointer();
    for (vect::const_iterator i = elemente.begin(); i != elemente.end(); ++i) {
        const ModelBun *bun = (*i);
        std::cout << "Bun: " << bun->getNume() << "\n";
        std::cout << "ModelStoc: " << bun->getStoc() << "\n";
        std::cout << "\n";
    }
}
