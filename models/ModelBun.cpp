//
// Created by xiodine on 4/15/15.
//

#include "ModelBun.h"
#include "../log.h"

ModelBun::ModelBun(std::string nume,
         std::string masura,
         std::vector<std::string> const &trasaturi,
         int stoc,
         double pret,
         double pret_furnizor)
: nume_(nume), masura_(masura), trasaturi_(trasaturi), stoc_(stoc), pret_(pret), pret_furnizor_(pret_furnizor) {

}

std::string ModelBun::getNume() const {
    return nume_;
}

std::string ModelBun::getMasura() const {
    return masura_;
}

const ModelBun::trasaturi_t &ModelBun::getTrasaturi() const {
    return trasaturi_;
}

int ModelBun::getStoc() const {
    return stoc_;
}

double ModelBun::getPret() const {
    return pret_;
}

double ModelBun::getPretFurnizor() const {
    return pret_furnizor_;
}

std::istream &ModelBun::loadSettings(std::istream &in) {
    return in;
}

std::ostream &ModelBun::saveSettings(std::ostream &out) const {
    d("saving nume: %s", nume_.c_str());
    d("saving masura: %s", masura_.c_str());
    d("saving trasaturi size: %d", trasaturi_.size());

    out<<nume_<<"\n";
    out<<masura_<<"\n";
    out<<trasaturi_.size()<<"\n";
    for (std::vector<std::string>::const_iterator i = trasaturi_.begin(); i != trasaturi_.end(); ++i) {
        out<<(*i)<<"\n";
        d("saving trasatura: %s", i->c_str());
    }
    d("saving stoc: %d", stoc_);
    out<<stoc_<<"\n";
    d("saving pret: %3.3f", pret_);
    out<<pret_<<"\n";
    d("saving pret furnizor: %3.3f", pret_furnizor_);
    out<<pret_furnizor_<<"\n";
    d("done saving bun");
    return out;
}

ModelBun::ModelBun(std::istream &input) {
    bool success = true;

    if (!(getline(input, nume_)))
        success = false;

    if (!(getline(input, masura_)))
        success = false;

    int size;
    if (success && !(input>>size))
        success = false;

    if (success) {

        // I've used cin before, so I need to read into a temporary string, before I can continue using getline
        std::string temporary;
        getline(input, temporary);

        for (int i = 0; i < size; i++) {
            std::string trasatura;
            if (success && !(getline(input, trasatura)))
                success = false;

            if (success)
                trasaturi_.push_back(trasatura);
        }
    }

    if (success && !(input>>stoc_))
        success = false;
    if (success && !(input>>pret_))
        success = false;
    if (success && !(input>>pret_furnizor_))
        success = false;


    if (!success) {
        d("cannot read bun, implicit values set");
        stoc_ = 0;
        pret_ = 0;
        pret_furnizor_ = 0;
        trasaturi_.clear();
        masura_ = "invalid";
        nume_ = "BUN INVALID";
    }

    std::string temporary;
    getline(input, temporary);

    d("done loading bun");
}
