//
// Created by xiodine on 4/15/15.
//

#ifndef POO_2_BUN_H
#define POO_2_BUN_H

#include "Model.h"

#include <string>
#include <vector>

class Bun : public Model {
public:


    Bun(std::string nume, std::string masura, std::vector<std::string> const &trasaturi, int stoc, double pret,
        double pret_furnizor);


    Bun(std::istream &input);

    std::istream &loadSettings(std::istream &in);

    std::ostream & saveSettings(std::ostream &out) const;

    std::string getMasura() const;
    std::string getNume() const;
    std::vector<std::string> getTrasaturi() const;
    int getStoc() const;
    double getPret() const;
    double getPretFurnizor() const;

private:
    std::string nume_;
    std::string masura_;
    std::vector<std::string> trasaturi_;
    int stoc_;
    double pret_;
    double pret_furnizor_;

};


#endif //POO_2_BUN_H
