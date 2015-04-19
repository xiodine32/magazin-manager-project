//
// Created by xiodine on 4/15/15.
//

#ifndef POO_2_CONSOLE_H
#define POO_2_CONSOLE_H

#include <iostream>
#include <string>
#include <vector>

class ViewConsole {
    static ViewConsole *singleton_;

    ViewConsole();

    ~ViewConsole();

public:
    static ViewConsole &getSingleton();

    typedef std::vector<std::string> queryOptions_t;

    template<class T>
    ViewConsole &operator<<(const T &ceva) {
        std::cout << ceva;
        return *this;
    }

    template<class T>
    ViewConsole &operator>>(T &ceva) {
        std::cin >> ceva;
        return *this;
    }

    std::string getLine();

    std::string quizUser(std::string queryString, const queryOptions_t &queryOptions);


};


#endif //POO_2_CONSOLE_H

