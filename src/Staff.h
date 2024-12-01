#ifndef STAFF_H
#define STAFF_H

#include <iostream>
#include <string>
#include <vector>
#include "Car.h"      // Include Car class
#include "Rental.h"   // Include Rental class
#include "Customer.h" // Include Customer class
#include "User.h"     // Include User base class
using namespace std;

class Staff : public User {
public:
    // Constructor to initialize staff details
    Staff(const string& name, const string& address, const string& phone,
          const string& license, const string& aadhar, const string& photoID);

    // Getters
    string getName() const { return name; }
    int getRating() const { return rating; }
    void setRating(int r) { rating = r; }

    // Staff Dashboard
    void dashboard(vector<Car>& carList, vector<Rental>& rentalList, vector<Customer>& customerList);

private:
    // Helper functions for dashboard options
    void addCar(vector<Car>& carList);
    void updateTransaction(vector<Rental>& rentalList);
    void rateCustomer(vector<Customer>& customerList);

    string name;
    string address;
    string phone;
    string license;
    string aadhar;
    string photoID;
    int rating;  // Assuming a rating system from 0 to 5
};

#endif
