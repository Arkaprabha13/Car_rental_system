#include <iostream>
#include <vector>
#include "Authentication.h"
#include "User.h"
#include "Staff.h"
#include "Admin.h"

using namespace std;

// Function to show main menu for role selection
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

    bool userExists = false;
    User* loggedInUser = nullptr;

    switch (choice) {
        case 1:  // Customer
            cout << "You selected Customer!" << endl;
            break;
        case 2:  // Staff
            cout << "You selected Staff!" << endl;
            break;
        case 3:  // Admin
            cout << "You selected Admin!" << endl;
            break;
        default:
            cout << "Invalid role selection!" << endl;
            return 0;
    }

    // Ask whether to Sign In or Sign Up
    cout << "Do you want to Sign In or Sign Up?" << endl;
    cout << "1. Sign In" << endl;
    cout << "2. Sign Up" << endl;
    int actionChoice;
    cin >> actionChoice;

    if (actionChoice == 1) {
        // Sign In
        loggedInUser = Authentication::signIn(users, username, password);
        if (loggedInUser) {
            cout << "Logged in successfully!" << endl;
            loggedInUser->displayInfo();
        } else {
            cout << "Login failed. Incorrect username or password." << endl;
        }
    } else if (actionChoice == 2) {
        // Sign Up
        bool userExists = false;

        // Check if user already exists
        for (auto user : users) {
            if (user->getName() == username) {
                userExists = true;
                break;
            }
        }

        if (userExists) {
            cout << "User already exists. Please sign in instead." << endl;
            return 0;
        }

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
            cout << "Signup failed. Please try again." << endl;
            return 0;
        }

        // Now the user is signed up, let's log them in
        loggedInUser = Authentication::signIn(users, username, password);
        if (loggedInUser) {
            cout << "Logged in successfully!" << endl;
            loggedInUser->displayInfo();
        } else {
            cout << "Login failed after signup. Something went wrong." << endl;
        }
    } else {
        cout << "Invalid action selection!" << endl;
    }

    return 0;
}
