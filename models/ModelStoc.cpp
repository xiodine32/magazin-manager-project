//
// Created by xiodine on 4/15/15.
//

#include <sstream>
#include "ModelStoc.h"
#include "../log.h"
#include "../stringR.h"

const ModelBun *ModelStoc::getBunQuery(std::string query) const {
    std::stringstream sstr(query);
    ModelBun::trasaturi_t trasaturi;
    stringR produs;
    stringR trasatura;

    sstr >> produs;
    produs.toLowerCase();


    while (!sstr.eof()) {
        sstr >> trasatura;
        trasatura.toLowerCase();
        trasaturi.push_back(trasatura);
    }

    typedef ModelBun::trasaturi_t::const_iterator tci_t;


    const ModelBun *produsGasit = NULL;

    for (bunuri_t::const_iterator i = bunuri_.begin(); i != bunuri_.end(); ++i) {
        stringR numeProdus;
        numeProdus = i->getNume();
        numeProdus.toLowerCase();

        if (numeProdus == produs) {
            bool produsBun = true;
            const ModelBun::trasaturi_t &trasaturiProdus = i->getTrasaturi();

            // for all trasaturi requested
            for (tci_t j = trasaturi.begin(); j != trasaturi.end(); ++j) {
                stringR trasaturaProdus = *j;
                trasaturaProdus.toLowerCase();
                // check if they all exist in the product.
                bool trasaturaGasita = false;
                for (tci_t k = trasaturiProdus.begin(); k != trasaturiProdus.end(); ++k) {
                    if ((*k) == trasaturaProdus) {
                        trasaturaGasita = true;
                        break;
                    }
                }
                if (!trasaturaGasita) {
                    produsBun = false;
                    break;
                }
            }
            if (produsBun) {
                produsGasit = &(*i);
                break;
            }
        }
    }

    return produsGasit;
}

std::istream &ModelStoc::loadSettings(std::istream &in) {
    int lungimeStocuri = 0;
    if (!(in>>lungimeStocuri)) {
        w("nu avem input!");
    }

    // lungimeStocuri through >>
    std::string temporary;
    getline(in, temporary);

    d("reading bunuri size: %d", lungimeStocuri);
    for (int i = 0; i < lungimeStocuri; i++) {
        d("reading element #%d", i);
        bunuri_.push_back(ModelBun(in));
    }
    return in;
}

std::ostream &ModelStoc::saveSettings(std::ostream &out) const {
    out<<bunuri_.size()<<"\n";
    d("saving bunuri_ size: %d", bunuri_.size());
    for (std::vector<ModelBun>::const_iterator i = bunuri_.begin(); i != bunuri_.end(); ++i) {
        i->saveSettings(out);
    }
    return out;
}

void ModelStoc::addBun(ModelBun bun) {
    bunuri_.push_back(bun);
}

ModelStoc::bunuri_pointer_t ModelStoc::getBunuriPointer() {
    ModelStoc::bunuri_pointer_t bunuri;

    for (std::vector<ModelBun>::iterator i = bunuri_.begin(); i != bunuri_.end(); ++i) {
        bunuri.push_back(&(*i));
    }

    return bunuri;
}

ModelStoc::bunuri_pointer_t ModelStoc::getBunuriGoalePointer() {
    bunuri_pointer_t bunuri;
    for (bunuri_t::const_iterator i = bunuri_.begin(); i != bunuri_.end(); ++i) {
        if (i->getStoc() == 0)
            bunuri.push_back(&(*i));
    }
    return bunuri;
}

void ModelStoc::addStocToBun(const ModelBun *bun, int nrStoc) {
    //find bun
    for (bunuri_t::iterator i = bunuri_.begin(); i != bunuri_.end(); ++i) {
        if (&(*i) == bun) {
            i->adaugaStoc(nrStoc);
            return;
        }
    }
}

void ModelStoc::scoateStocFromBun(const ModelBun *bun, int nrStoc) {
    for (bunuri_t::iterator i = bunuri_.begin(); i != bunuri_.end(); ++i) {
        if (&(*i) == bun) {
            i->adaugaStoc(-nrStoc);
        }
    }
}
