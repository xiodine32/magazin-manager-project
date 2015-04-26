//
// Created by xiodine on 4/26/15.
//

#include "ControllerGoale.h"
#include "../log.h"
#include "../views/ViewConsole.h"

ControllerGoale::ControllerGoale() : Controller() {
    d("ControllerGoale init");
}

ControllerGoale::~ControllerGoale() {
    d("ControllerGoale destruct");
}

void ControllerGoale::run(ModelStoc &stoc) {
    ViewConsole &con = ViewConsole::getSingleton();
    con << "Produse cu stocul 0:\n\n";
    ModelStoc::bunuri_pointer_t goale = stoc.getBunuriGoalePointer();
    for (ModelStoc::bunuri_pointer_t::const_iterator i = goale.begin(); i != goale.end(); ++i) {
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
        con << "---\n";
    }
}
