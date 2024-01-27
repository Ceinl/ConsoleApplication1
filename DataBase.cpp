// DataBase.cpp

#include "DataBase.h"
#include <iostream>

using namespace std;

// Initialize static members of DataBase class
int DataBase::size = 0;
string DataBase::usernames[DataBase::maxSize];
string DataBase::passwords[DataBase::maxSize];

void DataBase::addUser(const string& username, const string& password) {
    // Function to add a new user to the database
    if (size < maxSize) {
        usernames[size] = username;
        passwords[size] = password;
        size++;
    }
    else {
        cerr << "Error: Maximum number of users reached.\n";
    }
}

void DataBase::displayAllUsers() {
    // Function to display information about all users in the database
    cout << "\nAll registered users:\n";
    for (int i = 0; i < size; ++i) {
        cout << "Username: " << usernames[i] << endl;
    }
}
