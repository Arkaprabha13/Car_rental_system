#ifndef ADMIN_H
#define ADMIN_H
#include <iostream>
#include <vector>
#include <string>
#include "User.h"  // Include User base class
#include "Staff.h" // Include Staff class (you'll need to define this)
using namespace std;

class Admin : public User {
public:
    Admin(const string& username, const string& password, const string& name, const string& address, const string& phone,
          const string& license, const string& aadhar, const string& photoID)
        : User(name, address, phone, license, aadhar, photoID), username(username), password(password) {}

    void dashboard(vector<Staff>& staffList);
    void addStaff(vector<Staff>& staffList);
    void removeStaff(vector<Staff>& staffList);
    void viewRatings(const vector<Staff>& staffList);

private:
    string username;
    string password;
};

#endif
