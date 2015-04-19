//
// Created by xiodine on 4/15/15.
//

#include "ViewConsole.h"
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

