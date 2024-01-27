// Register.cpp

#include "Register.h"
#include <iostream>

using namespace std;

void Register::registerUser() {
    // Function to register a new user

    string username, password;

    // Prompt the user for information
    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    // Add the user to the database
    DataBase::addUser(username, password);

    // Print a message about successful registration
    cout << "\nUser registered successfully\n";
}

void Register::displayUsers() {
    // Function to display information about registered users
    DataBase::displayAllUsers();
}
