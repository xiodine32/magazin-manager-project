//
// Created by xiodine on 4/15/15.
//

#ifndef POO_2_STOC_H
#define POO_2_STOC_H

#include "ModelBun.h"
#include "Model.h"

#include <vector>

class ModelStoc : public Model {
    typedef std::vector<ModelBun> bunuri_t;

    bunuri_t bunuri_;
public:

    std::istream &loadSettings(std::istream &in);

    std::ostream &saveSettings(std::ostream &out) const;

    const ModelBun *getBunQuery(std::string query) const;

    typedef std::vector<const ModelBun *> bunuri_pointer_t;

    bunuri_pointer_t getBunuriPointer();

    bunuri_pointer_t getBunuriGoalePointer();

    void addBun(ModelBun bun);

    void addStocToBun(const ModelBun *bun, int nrStoc);

    void scoateStocFromBun(const ModelBun *bun, int nrStoc);
};


#endif //POO_2_STOC_H
