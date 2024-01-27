// DataBase.h

#ifndef _DATABASE_H
#define _DATABASE_H

#include <string>

class DataBase {
public:
    // Function to add a new user to the database
    static void addUser(const std::string& username, const std::string& password);

    // Function to display information about all users in the database
    static void displayAllUsers();

    // Arrays to store usernames and passwords
    static const int maxSize = 100; // Maximum size of arrays (you can change it as needed)
    static std::string usernames[maxSize];
    static std::string passwords[maxSize];
    static int size; // Current size of arrays
};

#endif // _DATABASE_H
