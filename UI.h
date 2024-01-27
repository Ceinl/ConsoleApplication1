/**
 * Project Untitled
 */


#include "Login.h"
#include "Register.h"
#include "MainScreen.h"
#include <iostream>

#ifndef _UI_H
#define _UI_

class UI {
public:
    static void Open();
    static void clearScreen();
    static void displayProjectMenu();
    static void pressEnterToContinue();
};

#endif //_UI_H