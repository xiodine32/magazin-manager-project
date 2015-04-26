//
// Created by xiodine on 4/19/15.
//

#ifndef POO_2_CONTROLLERADAUGAREFILL_H
#define POO_2_CONTROLLERADAUGAREFILL_H


#include "Controller.h"

class ControllerAdaugaRefill : public Controller {

public:
    ControllerAdaugaRefill();

    virtual ~ControllerAdaugaRefill();

    virtual void run(ModelStoc &stoc);

    size_t showOptions(ModelStoc &stoc);
};


#endif //POO_2_CONTROLLERADAUGAREFILL_H
