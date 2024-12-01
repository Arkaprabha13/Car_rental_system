#ifndef STAFF_H
#define STAFF_H

#include "User.h"
#include <iostream>
using namespace std;
class Staff : public User {
public:
    Staff(const string& username, const string& password, const string& name, const string& address, const string& phone,
          const string& license, const string& aadhar, const string& photoID)
        : User(name, address, phone, license, aadhar, photoID), username(username), password(password) {}

    void displayInfo() const override {
        User::displayInfo();
        cout << "Role: Staff" << endl;
    }

private:
    string username;
    string password;
};

#endif
