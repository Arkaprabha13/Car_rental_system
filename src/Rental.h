#ifndef RENTAL_H
#define RENTAL_H

#include "Car.h"
#include "User.h"
#include <iostream>

class Rental {
public:
    Rental(int rentalID, User* customer, Car* car, int rentalDays)
        : rentalID(rentalID), customer(customer), car(car), rentalDays(rentalDays),status("Ongoing")  {
        calculateTotalCost();
    }

    void calculateTotalCost() {
        totalCost = rentalDays * car->getPricePerDay();
    }

    void rentCar() {
        if (car->getAvailability()) {
            car->setAvailability(false);  // Mark as rented
            std::cout << "Car rented successfully!" << std::endl;
        } else {
            std::cout << "Car is not available for rent." << std::endl;
        }
    }

    void returnCar() {
        car->setAvailability(true);  // Mark as available
        std::cout << "Car returned successfully!" << std::endl;
    }

    void displayRentalInfo() {
        std::cout << "Rental ID: " << rentalID << std::endl;
        customer->displayInfo();
        car->displayCarInfo();
        std::cout << "Rental Days: " << rentalDays << std::endl;
        std::cout << "Total Cost: $" << totalCost << std::endl;
    }

     // Getter for rentalID
    int getRentalID() const { return rentalID; }

    // Getter for status
    std::string getStatus() const { return status; }

    // Setter for status
    void setStatus(const std::string& newStatus) { status = newStatus; }    

private:
    int rentalID;
    User* customer;
    Car* car;
    int rentalDays;
    double totalCost;
    std::string status;  // Status of the rental (Ongoing, Returned, etc.)
};

#endif
