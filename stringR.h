//
// Created by xiodine on 4/19/15.
//

#ifndef POO_2_STRINGR_H
#define POO_2_STRINGR_H

#include <string>

class stringR : public std::string {
public:
    stringR();

    stringR(const std::string &r);
    void toLowerCase();
};


#endif //POO_2_STRINGR_H
