// Login.h

#ifndef _LOGIN_H
#define _LOGIN_H

#include <string>

class Login {
public:  // ����� � private �� public
    static bool isLoggedIn;

    // ������� ��� ��������� �����
    static void performLogin();
    static bool loginUser(const std::string& username, const std::string& password);
};

#endif // _LOGIN_H
