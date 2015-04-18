#include "Engine.h"

int main() {

    Engine *engine = new Engine();

    engine->run();

    delete engine;

    return 0;
}

