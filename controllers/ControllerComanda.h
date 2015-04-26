//
// Created by xiodine on 4/26/15.
//

#include "Controller.h"

#ifndef POO_2_CONTROLLERCOMANDA_H
#define POO_2_CONTROLLERCOMANDA_H


class ControllerComanda : public Controller {

    // an immutable product
    class Produs {
        const ModelBun &bun_;
        int nr_;
    public:

        const ModelBun &getModelBun() const;

        int getNr() const;

        Produs(const ModelBun &bun, int nr);

        ~Produs();
    };

    typedef std::vector<Produs *> cos_t;

    cos_t cos_;

    double getTotal() const;

public:
    ControllerComanda();

    ~ControllerComanda();

    void run(ModelStoc &stoc);

    int stocRamas(const ModelBun *bun);
};

#endif //POO_2_CONTROLLERCOMANDA_H