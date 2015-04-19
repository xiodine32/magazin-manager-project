//
// Created by xiodine on 4/19/15.
//

#ifndef POO_2_MODELREADME_H
#define POO_2_MODELREADME_H


#include "Model.h"

class ModelReadme : public Model {
public:
    virtual std::istream &loadSettings(std::istream &in);

    virtual std::ostream &saveSettings(std::ostream &out) const;

public:
    std::string getAll();
};


#endif //POO_2_MODELREADME_H
