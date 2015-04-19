//
// Created by xiodine on 4/18/15.
//

#include "Controller.h"
#include "../models/Stoc.h"

#ifndef POO_2_VIEWER_H
#define POO_2_VIEWER_H


class Stats : public Controller {

public:
    void run(Stoc &stoc);

    Stats();

    ~Stats();
};


#endif //POO_2_VIEWER_H