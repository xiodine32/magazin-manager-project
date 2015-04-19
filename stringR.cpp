//
// Created by xiodine on 4/19/15.
//

#include "stringR.h"

void stringR::toLowerCase() {

    for (size_t i = 0; i < this->length(); i++) {
        char &elm = this->at(i);
        if (elm >= 'A' && elm <= 'Z')
            elm = elm - 'A' + 'a';
    }
}

stringR::stringR(const std::string &r) : std::string(r) { }

stringR::stringR() : std::string() {}
