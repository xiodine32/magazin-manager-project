//
// Created by xiodine on 4/15/15.
//

#include "ViewConsole.h"
#include "../stringR.h"
#include <fstream>

ViewConsole::ViewConsole() {

}

ViewConsole::~ViewConsole() {

}

ViewConsole &ViewConsole::getSingleton() {
    if (ViewConsole::singleton_ == NULL)
        ViewConsole::singleton_ = new ViewConsole();
    return *ViewConsole::singleton_;
}

ViewConsole *ViewConsole::singleton_ = NULL;

std::string ViewConsole::getLine() {
    std::string ceva;
    do {
        getline(std::cin, ceva);
    } while (!ceva.length());
    return ceva;
}

std::string ViewConsole::quizUser(std::string queryString, const std::vector<std::string> &queryOptions) {

    typedef std::vector<std::string> vect;
    typedef vect::const_iterator vi;


    ViewConsole &me = *this;

    stringR query;
    bool trying = true;

    do {
        // display: "Query? ('stoc', 'ceva'): "
        me << queryString << " (";
        for (vi i = queryOptions.begin(); i != queryOptions.end(); ++i) {
            if (i != queryOptions.begin())
                me << ", ";
            me << '\'' << *i << '\'';
        }
        me << "): ";

        // read input
        query = me.getLine();
        // lowercase
        query.toLowerCase();

        // check for match
        for (vi i = queryOptions.begin(); trying && i != queryOptions.end(); ++i) {
            if (*i == query) {
                trying = false;
            }
        }

        // show if undefined response
        if (trying)
            me << "Scuze, nu am inteles!\n";
    } while (trying);
    return query;
}
