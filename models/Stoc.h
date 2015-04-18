//
// Created by xiodine on 4/15/15.
//

#ifndef POO_2_STOC_H
#define POO_2_STOC_H

#include "Bun.h"
#include "Model.h"

#include <vector>

class Stoc : public Model {
    std::vector<Bun> bunuri_;
public:

    std::istream &loadSettings(std::istream &in);

    std::ostream &saveSettings(std::ostream &out) const;

    const Bun *getBunQuery(std::string query) const;

    void addBun(Bun bun);
};


#endif //POO_2_STOC_H
