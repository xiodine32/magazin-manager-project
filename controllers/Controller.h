//
// Created by xiodine on 4/15/15.
//

#ifndef POO_2_CONTROLLER_H
#define POO_2_CONTROLLER_H


#include "../models/ModelStoc.h"

class Controller {
public:
    Controller();
    virtual ~Controller();

    virtual void run(ModelStoc &stoc);
};


#endif //POO_2_CONTROLLER_H
