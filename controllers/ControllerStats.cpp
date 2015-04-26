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

    typedef std::vector<ModelBun *> vect;

    vect elemente = stoc.getBunuriPointer();
    for (vect::const_iterator i = elemente.begin(); i != elemente.end(); ++i) {
        const ModelBun *bun = (*i);
        con << "Bun: " << bun->getNume() << "\n";
        con << "Masura: " << bun->getMasura() << "\n";
        con << "Stoc: " << bun->getStoc() << "\n";
        con << "Trasaturi: ";
        ModelBun::trasaturi_t trasaturi = bun->getTrasaturi();
        for (ModelBun::trasaturi_t::const_iterator j = trasaturi.begin(); j != trasaturi.end(); ++j) {
            if (j != trasaturi.begin())
                con << ", ";
            con << '\'' << *j << '\'';
        }
        con << "\n";
        con << "Pret vanzare: " << bun->getPret() << "\n";
        con << "Pret furnizor: " << bun->getPretFurnizor() << "\n";
    }
}
