//
// Created by xiodine on 4/19/15.
//

#include "ModelReadme.h"

#include <fstream>
#include <sstream>

std::string ModelReadme::getAll() {

    std::ifstream in("README.md");

    if (!in.is_open())
        return "Nu exista fisierul!\n";

    std::stringstream reader;

    std::string temp;
    while (getline(in, temp)) {
        reader << temp << "\n";
    }

    return reader.str();
}

std::istream &ModelReadme::loadSettings(std::istream &in) {
    return in;
}

std::ostream &ModelReadme::saveSettings(std::ostream &out) const {
    return out;
}
