#include "Car.h"
#include <iostream>
using namespace std;

// Constructor to initialize car details
Car::Car(int carID, const std::string& make, const std::string& model, int year, double pricePerDay)
    : carID(carID), make(make), model(model), year(year), pricePerDay(pricePerDay), isAvailable(true) {}

// Method to display car details
void Car::displayCarInfo() const {
    cout << "Car ID: " << carID << "\n";
    cout << "Make: " << make << ", Model: " << model << ", Year: " << year << "\n";
    cout << "Price Per Day: $" << pricePerDay << "\n";
    cout << "Availability: " << (isAvailable ? "Available" : "Not Available") << "\n";
}

// Method to set the availability of the car
void Car::setAvailability(bool availability) {
    isAvailable = availability;
}

// Getters for the car details
int Car::getCarID() const {
    return carID;
}

const std::string& Car::getMake() const {
    return make;
}

const std::string& Car::getModel() const {
    return model;
}

int Car::getYear() const {
    return year;
}

double Car::getPricePerDay() const {
    return pricePerDay;
}

bool Car::getAvailability() const {
    return isAvailable;
}
