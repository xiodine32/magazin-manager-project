//
// Created by xiodine on 4/15/15.
//

#ifndef POO_2_ENGINE_H
#define POO_2_ENGINE_H


#include "models/ModelStoc.h"

class Engine {
private:
    ModelStoc stoc_;
    void load();

public:
    Engine();
    ~Engine();
    void run();
};

#endif //POO_2_ENGINE_H
