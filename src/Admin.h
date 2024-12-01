#ifndef ADMIN_H
#define ADMIN_H
#include <iostream>
#include <string>
using namespace std;
#include "User.h"

class Admin : public User {
public:
    Admin(const string& username, const string& password, const string& name, const string& address, const string& phone,
          const string& license, const string& aadhar, const string& photoID)
        : User(name, address, phone, license, aadhar, photoID), username(username), password(password) {}

    void displayInfo() const override {
        User::displayInfo();
        cout << "Role: Admin" << endl;
    }

private:
    string username;
    string password;
};

#endif
