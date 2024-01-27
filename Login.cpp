// Login.cpp

#include "Login.h"
#include "DataBase.h" // Включіть заголовок бази даних

#include <iostream>

using namespace std;

bool Login::isLoggedIn = false; // Определіть визначення тут, не змінюючи приватний статус

void Login::performLogin() {
    cout << "\nEnter login credentials:\n";
    string username, password;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    if (loginUser(username, password)) {
        isLoggedIn = true;
        // Додайте додаткові дії після успішного входу, якщо потрібно
    }
}

bool Login::loginUser(const string& username, const string& password) {
    // Функція для виконання входу
    for (int i = 0; i < DataBase::size; ++i) {
        if (DataBase::usernames[i] == username && DataBase::passwords[i] == password) {
            cout << "Login successful. Welcome, " << username << "!\n";
            return true; // Успішний вхід
        }
    }

    cout << "Login failed. Invalid username or password.\n";
    return false; // Невдалий вхід
}
