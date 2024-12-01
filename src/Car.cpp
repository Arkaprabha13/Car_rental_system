#include "Car.h"
#include <iostream>
using namespace std;

Car::Car(int carID, std::string make, std::string model, int year, double pricePerDay) {
    this->carID = carID;
    this->make = make;
    this->model = model;
    this->year = year;
    this->pricePerDay = pricePerDay;
    this->isAvailable = true; // Initially, the car is available
}

void Car::displayCarInfo() {
    cout << "Car ID: " << carID << "\n";
    cout << "Make: " << make << ", Model: " << model << ", Year: " << year << "\n";
    cout << "Price Per Day: $" << pricePerDay << "\n";
    cout << "Availability: " << (isAvailable ? "Available" : "Not Available") << "\n";
}

void Car::setAvailability(bool availability) {
    isAvailable = availability;
}
