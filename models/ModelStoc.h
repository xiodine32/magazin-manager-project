//
// Created by xiodine on 4/15/15.
//

#ifndef POO_2_STOC_H
#define POO_2_STOC_H

#include "ModelBun.h"
#include "Model.h"

#include <vector>

class ModelStoc : public Model {
    std::vector<ModelBun> bunuri_;
public:

    std::istream &loadSettings(std::istream &in);

    std::ostream &saveSettings(std::ostream &out) const;

    const ModelBun *getBunQuery(std::string query) const;

    std::vector<const ModelBun *> getBunuriPointer() const;

    void addBun(ModelBun bun);
};


#endif //POO_2_STOC_H
