//
// Created by xiodine on 4/26/15.
//

#ifndef POO_2_CONTROLLERGOALE_H
#define POO_2_CONTROLLERGOALE_H


#include "Controller.h"

class ControllerGoale : public Controller {

public:
    ControllerGoale();

    ~ControllerGoale();

    void run(ModelStoc &stoc);
};


#endif //POO_2_CONTROLLERGOALE_H
