#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
public:
    // Constructor to initialize customer details
    Customer(const std::string& customerID, const std::string& name, const std::string& phone, double balance);

    // Method to display customer information
    void displayCustomerInfo() const;

    // Method to set the customer's rating
    void setRating(int rating);

    // Method to rent a car if the customer has enough balance
    bool rentCar(int carID, double pricePerDay);

    // Method to make payment and add funds to the customer balance
    bool makePayment(double amount);

    // Getter methods for customer data
    std::string getCustomerID() const;
    double getBalance() const;
    bool hasRentedCar() const;

private:
    std::string customerID;   // Unique identifier for the customer
    std::string name;         // Customer's name
    std::string phone;        // Customer's phone number
    double balance;           // Customer's current balance
    bool rentedCar;           // Whether the customer has rented a car
    int rating;               // Customer's rating (optional)
};

#endif
