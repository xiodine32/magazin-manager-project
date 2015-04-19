//
// Created by xiodine on 4/19/15.
//

#include "Readme.h"

#include <fstream>

Readme::Readme() : Controller() {

}

Readme::~Readme() {

}

void Readme::run(Stoc &stoc) {
    using namespace std;
    ifstream readme("README.md");
    string str;
    if (!readme.is_open()) {
        cout << "\nAti sters README.md!\nVa rugam sa il copiati iar!\n\n";
        return;
    }
    while (getline(readme, str)) {
        cout << str << "\n";
    }
}
