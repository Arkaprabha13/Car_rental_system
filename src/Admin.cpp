#include "Admin.h"
#include <iostream>

Admin::Admin(std::string name, std::string address, std::string phoneNumber, std::string licenseNumber,
             std::string aadharNumber, std::string photoID)
        : Staff(name, address, phoneNumber, licenseNumber, aadharNumber, photoID) {}

void Admin::dashboard() {
    std::cout << "Welcome, Admin " << name << std::endl;
    // Admin operations like adding/removing staff, viewing ratings, etc.
}

void Admin::addStaff(std::vector<Staff>& staffList) {
    // Add a new staff member
}

void Admin::removeStaff(std::vector<Staff>& staffList) {
    // Remove a staff member
}

void Admin::viewRatings() {
    // View ratings for staff and customers
}
