//
// Created by xiodine on 4/18/15.
//

#include "Controller.h"

#ifndef POO_2_VIEWER_H
#define POO_2_VIEWER_H


class ControllerStats : public Controller {

public:
    void run(ModelStoc &stoc);

    ControllerStats();

    ~ControllerStats();
};


#endif //POO_2_VIEWER_H