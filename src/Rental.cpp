#include "Rental.h"
#include <iostream>
using namespace std;
Rental::Rental(int rentalID, User* customer, Car* car, int rentalDays) : rentalID(rentalID), customer(customer), car(car), rentalDays(rentalDays) {
    calculateTotalCost();
}

void Rental::calculateTotalCost() {
    totalCost = rentalDays * car->getPricePerDay();  // Use the getter for pricePerDay
}

void Rental::rentCar() {
    if (car->getAvailability()) {  // Use the getter for isAvailable
        car->setAvailability(false); // Mark as rented
        std::cout << "Car rented successfully!" << std::endl;
    } else {
        std::cout << "Car is not available for rent." << std::endl;
    }
}


void Rental::returnCar() {
    car->setAvailability(true); // Mark as available
    std::cout << "Car returned successfully!\n";
}

void Rental::displayRentalInfo() {
    std::cout << "Rental ID: " << rentalID << "\n";
    customer->displayInfo();
    car->displayCarInfo();
    std::cout << "Rental Days: " << rentalDays << "\n";
    std::cout << "Total Cost: $" << totalCost << "\n";
}
