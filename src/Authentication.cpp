#include "Authentication.h"
#include <iostream>
#include <unordered_map>
#include <sstream>
#include "User.h"
using namespace std;
#include <bits/stdc++.h>  // For unordered_map

// Store users as key-value pairs where the username is the key
static unordered_map<string, string> userCredentials;
static unordered_map<string, User*> userObjects;  // Maps username to user object

bool Authentication::signUp(vector<User*>& users, const string& username, const string& password, 
                            const string& name, const string& address, const string& phone, 
                            const string& license, const string& aadhar, const string& photoID) {
    // Check if the username already exists
    if (userCredentials.find(username) != userCredentials.end()) {
        cout << "Username already exists. Try a different one." << endl;
        return false;
    }

    // Validate password strength (you can add more sophisticated checks)
    if (!validatePassword(password)) {
        cout << "Password does not meet the security requirements." << endl;
        return false;
    }

    // Hash the password before storing it (for security purposes)
    string hashedPassword = hashPassword(password);

    // Create a new user object based on input data
    User* newUser = new User(name, address, phone, license, aadhar, photoID);
    users.push_back(newUser);  // Add the new user object to the list of users
    userCredentials[username] = hashedPassword;  // Store the username and hashed password
    userObjects[username] = newUser;  // Store the username and user object

    cout << "Sign-up successful!" << endl;
    return true;
}

User* Authentication::signIn(const vector<User*>& users, const string& username, const string& password) {
    // Check if the username exists in the system
    if (userCredentials.find(username) == userCredentials.end()) {
        cout << "Username not found." << endl;
        return nullptr;
    }

    // Get the hashed password for the entered username
    string storedHashedPassword = userCredentials[username];
    // Hash the entered password to compare
    string enteredHashedPassword = hashPassword(password);

    // Check if the entered password matches the stored password
    if (storedHashedPassword == enteredHashedPassword) {
        cout << "Sign-in successful!" << endl;
        return userObjects[username];  // Return the corresponding user object
    } else {
        cout << "Incorrect password." << endl;
        return nullptr;
    }
}

// Helper function to validate the password (just checks length and contains digits/letters)
bool Authentication::validatePassword(const string& password) {
    if (password.length() < 6) {
        cout << "Password must be at least 6 characters long." << endl;
        return false;
    }

    bool hasDigit = false;
    bool hasLetter = false;
    for (char ch : password) {
        if (isdigit(ch)) hasDigit = true;
        if (isalpha(ch)) hasLetter = true;
    }

    return hasDigit && hasLetter;
}

// Simple hashing function (You should replace this with a real hashing algorithm like SHA-256 for security)
string Authentication::hashPassword(const string& password) {
    stringstream hashed;
    for (char ch : password) {
        hashed << hex << (int)ch;
    }
    return hashed.str();  // Returns a simple hex-based hashed string (not secure, but okay for illustration)
}
