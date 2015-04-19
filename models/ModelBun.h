//
// Created by xiodine on 4/15/15.
//

#ifndef POO_2_BUN_H
#define POO_2_BUN_H

#include "Model.h"

#include <string>
#include <vector>

class ModelBun : public Model {
public:

    typedef std::vector<std::string> trasaturi_t;

    ModelBun(std::string nume, std::string masura, trasaturi_t const &trasaturi, int stoc, double pret,
        double pret_furnizor);


    ModelBun(std::istream &input);

    std::istream &loadSettings(std::istream &in);

    std::ostream & saveSettings(std::ostream &out) const;

    std::string getMasura() const;
    std::string getNume() const;

    trasaturi_t getTrasaturi() const;
    int getStoc() const;
    double getPret() const;
    double getPretFurnizor() const;

private:
    std::string nume_;
    std::string masura_;
    trasaturi_t trasaturi_;
    int stoc_;
    double pret_;
    double pret_furnizor_;

};


#endif //POO_2_BUN_H
