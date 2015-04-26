//
// Created by xiodine on 4/19/15.
//

#include <sstream>
#include "ControllerAdaugaRefill.h"
#include "../views/ViewConsole.h"

ControllerAdaugaRefill::ControllerAdaugaRefill() : Controller() {

}

ControllerAdaugaRefill::~ControllerAdaugaRefill() {

}

std::size_t ControllerAdaugaRefill::showOptions(ModelStoc &stoc) {
    ViewConsole &con = ViewConsole::getSingleton();

    // typedefs
    typedef ModelBun::trasaturi_t trasaturi_t;


    // for each bun
    ModelStoc::bunuri_pointer_t bunuri = stoc.getBunuriPointer();

    std::size_t nrProduse = 0;

    for (ModelStoc::bunuri_pointer_t::const_iterator i = bunuri.begin(); i != bunuri.end(); ++i) {
        const ModelBun &bun = **i;

        nrProduse++;

        con << nrProduse << ". " << bun.getNume() << " (";

        const trasaturi_t &trasaturi = bun.getTrasaturi();
        for (trasaturi_t::const_iterator j = trasaturi.begin(); j != trasaturi.end(); ++j) {
            if (j != trasaturi.begin())
                con << ", ";
            con << '\'' << *j << '\'';
        }
        con << ") - " << bun.getStoc() << " in stoc";
    }
    return nrProduse;
}

void ControllerAdaugaRefill::run(ModelStoc &stoc) {
    std::size_t maxSize = showOptions(stoc);
    ViewConsole &con = ViewConsole::getSingleton();
    std::size_t nr;
    do {
        con << "\nIntroduceti numarul produsului (0 pentru stop): ";
        std::stringstream str(con.getLine());
        str >> nr;
        if (nr) {
            // test for validity
            if (nr > maxSize) {
                con << "Numar invalid!";
            } else {

                con << "Numarul de produse de adaugat (numar): ";
                std::stringstream nrProdStr(con.getLine());
                int nrProd;
                nrProdStr >> nrProd;

                ModelStoc::bunuri_pointer_t bunuri = stoc.getBunuriPointer();
                stoc.addStocToBun(bunuri[nr - 1], nrProd);
            }
        } // else nr == 0
    } while (nr != 0);
}
