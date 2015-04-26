//
// Created by xiodine on 4/15/15.
//

#include "ModelStoc.h"
#include "../log.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma clang diagnostic ignored "-Wunused-parameter"
const ModelBun *ModelStoc::getBunQuery(std::string query) const {

    return NULL;
}

#pragma clang diagnostic pop

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

std::vector<ModelBun *> ModelStoc::getBunuriPointer() {
    std::vector<ModelBun *> bunuri;

    for (std::vector<ModelBun>::iterator i = bunuri_.begin(); i != bunuri_.end(); ++i) {
        bunuri.push_back(&(*i));
    }

    return bunuri;
}
