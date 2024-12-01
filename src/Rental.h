#ifndef RENTAL_H
#define RENTAL_H

#include "Car.h"
#include "User.h"
#include <iostream>

class Rental {
public:
    int rentalID;
    User* customer;
    Car* car;
    int rentalDays;
    double totalCost;

    Rental(int rentalID, User* customer, Car* car, int rentalDays);

    void calculateTotalCost();
    void rentCar();
    void returnCar();
    void displayRentalInfo();
};

#endif
