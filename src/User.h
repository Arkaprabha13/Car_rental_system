#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
using namespace std;

class User {
public:
    // Constructor to initialize user details
    User(const string& name, const string& address, const string& phone, const string& license, const string& aadhar, const string& photoID)
        : name(name), address(address), phone(phone), license(license), aadhar(aadhar), photoID(photoID) {}

    // Virtual function that can be overridden in derived classes
    virtual void displayInfo() const {
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Phone: " << phone << endl;
        cout << "License: " << license << endl;
        cout << "Aadhar: " << aadhar << endl;
        cout << "Photo ID: " << photoID << endl;
    }

    string getName() const {
        return name;
    }

private:
    string name;
    string address;
    string phone;
    string license;
    string aadhar;
    string photoID;
};

#endif
