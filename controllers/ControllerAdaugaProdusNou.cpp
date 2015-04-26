//
// Created by xiodine on 4/19/15.
//

#include "ControllerAdaugaProdusNou.h"
#include "../views/ViewConsole.h"

#include <sstream>

ControllerAdaugaProdusNou::ControllerAdaugaProdusNou() : Controller() {

}

ControllerAdaugaProdusNou::~ControllerAdaugaProdusNou() {

}

void ControllerAdaugaProdusNou::run(ModelStoc &stoc) {
    ViewConsole &con = ViewConsole::getSingleton();

    using namespace std;

    con << "Introduce nume produs: ";
    string nume = con.getLine();
    for (std::size_t i = 0, n = nume.length(); i < n; i++) {
        if (nume[i] == '\\')
            nume[i] = '_';
    }
    con << "Introduce masura (buc/kg/etc): ";
    string masura = con.getLine();

    bool introduceTrasaturi = true;
    ModelBun::trasaturi_t trasaturi;
    do {
        con << "Introduce trasatura (stop/blonda/bruna/anul/etc): ";
        string temp = con.getLine();
        if (temp == "stop" || temp == "STOP") {
            introduceTrasaturi = false;
        } else {
            trasaturi.push_back(temp);
        }
    } while (introduceTrasaturi);

    stringstream reader;

    con << "Introduceti numar produse in stoc: ";
    reader << con.getLine() << "\n";
    con << "Introduce pret de vanzare (virgula cu punct): ";
    reader << con.getLine() << "\n";
    con << "Introduce pretul de la furnizor (virgula cu punct): ";
    reader << con.getLine() << "\n";

    int nr_stoc;
    reader >> nr_stoc;

    double pret;
    reader >> pret;

    double pret_furnizor;
    reader >> pret_furnizor;

    ModelBun bun(nume, masura, trasaturi, nr_stoc, pret, pret_furnizor);

    stoc.addBun(bun);
}
