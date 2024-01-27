// Login.h

#ifndef _LOGIN_H
#define _LOGIN_H

#include <string>

class Login {
public:  // Змініть з private на public
    static bool isLoggedIn;

    // Функції для виконання входу
    static void performLogin();
    static bool loginUser(const std::string& username, const std::string& password);
};

#endif // _LOGIN_H
