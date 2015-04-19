//
// Created by xiodine on 4/15/15.
//

#ifndef POO_2_CONSOLE_H
#define POO_2_CONSOLE_H

#include <iostream>

class ViewConsole {
    static ViewConsole *singleton_;

    ViewConsole();

    ~ViewConsole();

public:
    static ViewConsole &getSingleton();

    template<class T>
    ViewConsole &operator<<(const T &ceva) {
        std::cout << ceva << "\n";
        return *this;
    }
};


#endif //POO_2_CONSOLE_H

