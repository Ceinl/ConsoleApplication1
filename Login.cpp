// Login.cpp

#include "Login.h"
#include "DataBase.h" // �������� ��������� ���� �����

#include <iostream>

using namespace std;

bool Login::isLoggedIn = false; // ��������� ���������� ���, �� ������� ��������� ������

void Login::performLogin() {
    cout << "\nEnter login credentials:\n";
    string username, password;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    if (loginUser(username, password)) {
        isLoggedIn = true;
        // ������� �������� 䳿 ���� �������� �����, ���� �������
    }
}

bool Login::loginUser(const string& username, const string& password) {
    // ������� ��� ��������� �����
    for (int i = 0; i < DataBase::size; ++i) {
        if (DataBase::usernames[i] == username && DataBase::passwords[i] == password) {
            cout << "Login successful. Welcome, " << username << "!\n";
            return true; // ������� ����
        }
    }

    cout << "Login failed. Invalid username or password.\n";
    return false; // �������� ����
}
