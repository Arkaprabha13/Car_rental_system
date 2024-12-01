#include "Admin.h"
#include <iostream>
#include "Staff.h" // Include the Staff class header

using namespace std;

void Admin::dashboard(vector<Staff>& staffList) {
    cout << "Welcome, Admin " << getName() << endl;
    cout << "Choose an option:" << endl;
    cout << "1. Add Staff" << endl;
    cout << "2. Remove Staff" << endl;
    cout << "3. View Ratings" << endl;
    cout << "4. Exit" << endl;
    int choice;
    cin >> choice;
    switch (choice) {
        case 1:
            addStaff(staffList);
            break;
        case 2:
            removeStaff(staffList);
            break;
        case 3:
            viewRatings(staffList);
            break;
        case 4:
            cout << "Exiting the dashboard." << endl;
            break;
        default:
            cout << "Invalid option. Try again." << endl;
    }
}

void Admin::addStaff(vector<Staff>& staffList) {
    string name, address, phone, license, aadhar, photoID;
    cout << "Enter Staff Details:" << endl;
    cout << "Name: ";
    cin >> name;
    cout << "Address: ";
    cin >> address;
    cout << "Phone: ";
    cin >> phone;
    cout << "License: ";
    cin >> license;
    cout << "Aadhar: ";
    cin >> aadhar;
    cout << "Photo ID: ";
    cin >> photoID;

    // Create a new Staff object and add it to the list
    Staff newStaff(name, address, phone, license, aadhar, photoID);
    staffList.push_back(newStaff);
    cout << "Staff added successfully!" << endl;
}

void Admin::removeStaff(vector<Staff>& staffList) {
    string staffName;
    cout << "Enter the name of the staff member to remove: ";
    cin >> staffName;

    // Search for the staff member in the list and remove them
    bool found = false;
    for (auto it = staffList.begin(); it != staffList.end(); ++it) {
        if (it->getName() == staffName) {
            staffList.erase(it);
            found = true;
            break;
        }
    }

    if (found) {
        cout << "Staff member " << staffName << " removed successfully." << endl;
    } else {
        cout << "Staff member not found!" << endl;
    }
}

void Admin::viewRatings(const vector<Staff>& staffList) {
    cout << "Staff Ratings:" << endl;
    for (const auto& staff : staffList) {
        cout << staff.getName() << ": " << staff.getRating() << endl;
    }
}
