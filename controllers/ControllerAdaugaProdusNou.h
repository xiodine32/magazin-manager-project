//
// Created by xiodine on 4/19/15.
//

#ifndef POO_2_CONTROLLERADAUGAPRODUSNOU_H
#define POO_2_CONTROLLERADAUGAPRODUSNOU_H


#include "Controller.h"

class ControllerAdaugaProdusNou : public Controller {
public:

    ControllerAdaugaProdusNou();

    virtual ~ControllerAdaugaProdusNou();

    virtual void run(ModelStoc &stoc);
};


#endif //POO_2_CONTROLLERADAUGAPRODUSNOU_H
