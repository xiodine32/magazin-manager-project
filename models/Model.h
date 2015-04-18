//
// Created by xiodine on 4/15/15.
//

#ifndef POO_2_MODEL_H
#define POO_2_MODEL_H

#include <iostream>

class Model {
public:
    virtual std::istream &loadSettings(std::istream &in)=0;
    virtual std::ostream &saveSettings(std::ostream &out) const =0;
};


#endif //POO_2_MODEL_H
