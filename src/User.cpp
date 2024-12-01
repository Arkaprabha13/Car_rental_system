#include "User.h"
#include <iostream>

using namespace std;

User::User(const string& name, const string& address, const string& phone, const string& license, const string& aadhar, const string& photoID)
    : name(name), address(address), phone(phone), license(license), aadhar(aadhar), photoID(photoID) {}

void User::displayInfo() const {
    cout << "Name: " << name << endl;
    cout << "Address: " << address << endl;
    cout << "Phone: " << phone << endl;
    cout << "License: " << license << endl;
    cout << "Aadhar: " << aadhar << endl;
    cout << "Photo ID: " << photoID << endl;
}

string User::getName() const {
    return name;
}
