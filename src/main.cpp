#include <iostream>
#include <vector>
#include "Authentication.h"
#include "User.h"
#include "Staff.h"
#include "Admin.h"
#include "Authentication.cpp"
// #include "User.cpp"
using namespace std;

void showMainMenu() {
    cout << "Welcome to the Car Rental System!" << endl;
    cout << "Please select your role:" << endl;
    cout << "1. Customer" << endl;
    cout << "2. Staff" << endl;
    cout << "3. Admin" << endl;
    cout << "Enter your choice: ";
}

int main() {
    vector<User*> users;  // Vector to hold all users

    // Simulate a few users (for simplicity, we add a Customer and an Admin here)
    Admin* admin = new Admin("admin", "admin", "admin", "admin", "1234567890", "dl_of_admin", "AadharAdmin", "admin_id");
    users.push_back(admin);  // Add admin to the list

    int choice;
    string username, password;

    // Display main menu and get user role
    showMainMenu();
    cin >> choice;

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    // Check if user is existing or needs signup
    bool userExists = false;
    for (auto user : users) {
        if (user->getName() == username) {
            userExists = true;
            break;
        }
    }

    if (!userExists) {
        // User is new, let's sign them up
        cout << "User not found! Please sign up." << endl;

        string name, address, phone, license, aadhar, photoID;

        cout << "Enter full name: ";
        cin >> name;
        cout << "Enter address: ";
        cin >> address;
        cout << "Enter phone number: ";
        cin >> phone;
        cout << "Enter license number: ";
        cin >> license;
        cout << "Enter Aadhar number: ";
        cin >> aadhar;
        cout << "Enter photo ID: ";
        cin >> photoID;

        bool signupSuccess = Authentication::signUp(users, username, password, name, address, phone, license, aadhar, photoID);

        if (!signupSuccess) {
            return 0;  // Exit if signup failed
        }
    }

    // Simulate signin
    User* loggedInUser = Authentication::signIn(users, username, password);

    if (loggedInUser) {
        cout << "Logged in successfully!" << endl;
        loggedInUser->displayInfo();
    } else {
        cout << "Login failed. Incorrect username or password." << endl;
    }

    return 0;
}
