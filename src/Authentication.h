#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

#include <string>
#include <vector>
#include "User.h"  // To include the User class

using namespace std;

class Authentication {
public:
    // Function to sign up a new user (stores user info)
    static bool signUp(vector<User*>& users, const string& username, const string& password, const string& name, 
                        const string& address, const string& phone, const string& license, 
                        const string& aadhar, const string& photoID);
    
    // Function to sign in an existing user (checks credentials)
    static User* signIn(const vector<User*>& users, const string& username, const string& password);

private:
    // Helper function to validate the password
    static bool validatePassword(const string& password);

    // Helper function to hash passwords (for simplicity, this is not a real hash but you can add hashing like SHA-256)
    static string hashPassword(const string& password);
};

#endif
