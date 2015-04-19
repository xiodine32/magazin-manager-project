//
// Created by xiodine on 4/19/15.
//

#ifndef POO_2_CONTROLLERADAUGA_H
#define POO_2_CONTROLLERADAUGA_H


#include "Controller.h"

class ControllerAdauga : public Controller {
public:

    ControllerAdauga();

    virtual ~ControllerAdauga();

    virtual void run(ModelStoc &stoc);
};


#endif //POO_2_CONTROLLERADAUGA_H
