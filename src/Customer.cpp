#include "Customer.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Constructor to initialize customer details
Customer::Customer(const std::string& customerID, const std::string& name, const std::string& phone, double balance)
    : customerID(customerID), name(name), phone(phone), balance(balance), rentedCar(false) {}

// Method to display customer information
void Customer::displayCustomerInfo() const {
    cout << "Customer ID: " << customerID << "\n";
    cout << "Name: " << name << "\n";
    cout << "Phone: " << phone << "\n";
    cout << "Balance: $" << balance << "\n";
    cout << "Rental Status: " << (rentedCar ? "Rented a car" : "No rented car") << "\n";
}
void Customer::setRating(int rating) {
    this->rating = rating;
}
// Method to rent a car if the customer has enough balance
bool Customer::rentCar(int carID, double pricePerDay) {
    if (balance >= pricePerDay) {
        rentedCar = true;
        balance -= pricePerDay;  // Deduct the payment from balance
        cout << "Successfully rented Car ID: " << carID << " for $" << pricePerDay << "\n";
        return true;
    } else {
        cout << "Insufficient balance to rent Car ID: " << carID << "\n";
        return false;
    }
}

// Method to make payment and add funds to the customer balance
bool Customer::makePayment(double amount) {
    if (amount <= 0) {
        cout << "Invalid payment amount." << endl;
        return false;
    }

    balance += amount;
    cout << "Payment of $" << amount << " received. New balance: $" << balance << "\n";
    return true;
}

// Getter methods for customer data
std::string Customer::getCustomerID() const {
    return customerID;
}

double Customer::getBalance() const {
    return balance;
}

bool Customer::hasRentedCar() const {
    return rentedCar;
}
