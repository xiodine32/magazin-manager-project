//
// Created by xiodine on 4/15/15.
//

#include "Stoc.h"
#include "../log.h"

const Bun *Stoc::getBunQuery(std::string query) const {

    return NULL;
}

std::istream &Stoc::loadSettings(std::istream &in) {
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
        bunuri_.push_back(Bun(in));
    }
    return in;
}

std::ostream &Stoc::saveSettings(std::ostream &out) const {
    out<<bunuri_.size()<<"\n";
    d("saving bunuri_ size: %d", bunuri_.size());
    for (std::vector<Bun>::const_iterator i = bunuri_.begin(); i != bunuri_.end(); ++i) {
        i->saveSettings(out);
    }
    return out;
}

void Stoc::addBun(Bun bun) {
    bunuri_.push_back(bun);
}
