//
// Created by xiodine on 4/26/15.
//

#include <sstream>
#include "ControllerComanda.h"
#include "../views/ViewConsole.h"
#include "../log.h"
#include "../stringR.h"

#pragma mark - ControllerComanda

ControllerComanda::ControllerComanda() : Controller() {

}

ControllerComanda::~ControllerComanda() {
    // created memory gets deleted... because we can't have nice things like move constructors :(
    for (cos_t::iterator i = cos_.begin(); i != cos_.end(); ++i) {
        delete *i;
    }
    cos_.clear();
}

void ControllerComanda::run(ModelStoc &stoc) {


    ViewConsole &con = ViewConsole::getSingleton();

    con << "Comanda noua\n\n";
    con << "Comenzi posibile: \n";
    con << " - nume [trasaturi, ...]\n";
    con << " - subtotal\n";
    con << " - total\n";
    bool cautaProduse = true;
    while (cautaProduse) {
        con << "Query?: ";
        std::string str = con.getLine();
        stringR strLowerCase = str;
        strLowerCase.c_str();
        if (strLowerCase == "total") {
            cautaProduse = false;
        } else if (strLowerCase == "subtotal") {
            for (cos_t::const_iterator i = cos_.begin(); i != cos_.end(); ++i) {
                const Produs *prod = *i;
                con << "Subtotal:\n";
                con << "  * " << prod->getModelBun().getNume() << " - " << prod->getModelBun().getPret() << " * " <<
                prod->getNr() << " = " << prod->getModelBun().getPret() * prod->getNr() << "\n";

            }
            con << "\n";
            con << "---------- SUBTOTAL ---------\n";
            con << "Subtotal: " << getTotal() << "\n";
        } else if (strLowerCase == "stop") {
            return;
        } else {
            // it's a query, get product.
            d("entering getBunQuery");
            const ModelBun *produs = stoc.getBunQuery(str);
            if (produs == NULL) {
                con << "Produsul nu a fost gasit!\n";
            } else {
                const ModelBun *bun = produs;
                con << "Bun: " << bun->getNume() << "\n";
                con << "Trasaturi: ";
                ModelBun::trasaturi_t trasaturi = bun->getTrasaturi();
                for (ModelBun::trasaturi_t::const_iterator j = trasaturi.begin(); j != trasaturi.end(); ++j) {
                    if (j != trasaturi.begin())
                        con << ", ";
                    con << '\'' << *j << '\'';
                }
                con << "\n";
                con << "Pret: " << bun->getPret() << "\n";
#ifdef DEBUG
                con << "** Masura: " << bun->getMasura() << "\n";
                con << "** Stoc: " << bun->getStoc() << "\n";
#endif
                con << "\n";
                con << "Cantitate dorita? (numar): ";
                std::stringstream strstream(con.getLine());
                int cantitateDorita = 0;
                strstream >> cantitateDorita;
                int stoc_ramas = stocRamas(bun);
                if (cantitateDorita > stoc_ramas) {
                    con << "Avem doar " << stoc_ramas << " produse in stoc! Clientul e de acord (D/N)?: ";
                    std::string confirmare = con.getLine();
                    if (confirmare == "D") {
                        cantitateDorita = stoc_ramas;
                    } else {
                        con << "Produs anulat!\n";
                        cantitateDorita = 0;
                    }
                }
                if (cantitateDorita) {
                    Produs *produsDorit = new Produs(*bun, cantitateDorita);
                    cos_.push_back(produsDorit);
                }
            }
        }
    }

    for (cos_t::const_iterator i = cos_.begin(); i != cos_.end(); ++i) {
        const Produs *prod = *i;
        con << "Total:\n";
        con << "  * " << prod->getModelBun().getNume() << " - " << prod->getModelBun().getPret() << " * " <<
        prod->getNr() << " = " << prod->getModelBun().getPret() * prod->getNr() << "\n";

    }
    con << "\n";
    con << "---------- TOTAL ---------\n";
    double total = getTotal();
    con << total << "\n";
    con << "\n";
    con << "Confirma comanda (D/N): ";
    std::string response = con.getLine();
    if (response == "N") {
        con << "Comanda anulata!\n";
        return;
    }
    con << "Confirma plata (D/N): ";
    response = con.getLine();
    if (response == "N") {
        con << "Comanda anulata!\n";
        return;
    }
    con << "Puteti inmana produsele!\n";
    for (cos_t::const_iterator i = cos_.begin(); i != cos_.end(); ++i) {
        const Produs *prod = *i;
        stoc.scoateStocFromBun(&prod->getModelBun(), prod->getNr());
    }
}

double ControllerComanda::getTotal() const {
    double total = 0;
    for (cos_t::const_iterator i = cos_.begin(); i != cos_.end(); ++i) {
        const Produs *prod = *i;
        total += prod->getModelBun().getPret() * prod->getNr();
    }
    return total;
}


int ControllerComanda::stocRamas(const ModelBun *bun) {
    int stocRamas = bun->getStoc();
    for (cos_t::const_iterator i = cos_.begin(); i != cos_.end(); ++i) {
        const Produs *prod = *i;
        if (&(prod->getModelBun()) == bun) {
            stocRamas -= prod->getNr();
        }
    }
    return stocRamas;
}


#pragma mark - Produs


ControllerComanda::Produs::Produs(const ModelBun &bun, int nr) : bun_(bun), nr_(nr) {
    d("created produs");
}

ModelBun const &ControllerComanda::Produs::getModelBun() const {
    return bun_;
}

int ControllerComanda::Produs::getNr() const {
    return nr_;
}

ControllerComanda::Produs::~Produs() {
    d("destroyed");
}
