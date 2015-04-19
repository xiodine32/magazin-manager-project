//
// Created by xiodine on 4/18/15.
//

#include "Stats.h"
#include "../log.h"

Stats::Stats() {
    d("Stats");
}

Stats::~Stats() {
    d("Stats ended");
}


void Stats::run(Stoc &stoc) {

    typedef std::vector<const Bun *> vect;

    vect elemente = stoc.getBunuriPointer();
    for (vect::const_iterator i = elemente.begin(); i != elemente.end(); ++i) {
        const Bun *bun = (*i);
        std::cout << "Bun: " << bun->getNume() << "\n";
        std::cout << "Stoc: " << bun->getStoc() << "\n";
        std::cout << "\n";
    }
}
