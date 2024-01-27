// Register.h

#ifndef _REGISTER_H
#define _REGISTER_H

#include <string>
#include "DataBase.h"

class Register {
public:
    // Function to register a new user
    static void registerUser();

    // Function to display information about registered users
    static void displayUsers();
};

#endif // _REGISTER_H
