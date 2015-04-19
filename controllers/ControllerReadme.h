//
// Created by xiodine on 4/19/15.
//

#ifndef POO_2_README_H
#define POO_2_README_H


#include "Controller.h"


class ControllerReadme : public Controller {

public:
    ControllerReadme();

    virtual ~ControllerReadme();

    virtual void run(ModelStoc &stoc);
};


#endif //POO_2_README_H
