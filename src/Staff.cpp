#include "Staff.h"
#include "Car.h"
#include "Rental.h"
#include <iostream>

Staff::Staff(std::string name, std::string address, std::string phoneNumber, std::string licenseNumber,
             std::string aadharNumber, std::string photoID)
        : User(name, address, phoneNumber, licenseNumber, aadharNumber, photoID) {}

void Staff::dashboard() {
    std::cout << "Welcome, Staff " << name << std::endl;
    // Add options for adding cars, managing transactions, etc.
}

void Staff::addCar(std::vector<Car>& carList) {
    // Implement the function to add a new car to the system
}

void Staff::updateTransaction(std::vector<Rental>& rentalList) {
    // Update rental status, manage rental return
}

void Staff::rateCustomer(int rating, std::string customerID) {
    // Allow staff to rate the customer
}
