#ifndef CAR_H
#define CAR_H

#include <string>
#include <iostream>

class Car {
public:
    int carID;
    std::string make, model;
    int year;
    double pricePerDay;
    bool isAvailable;

    Car(int carID, std::string make, std::string model, int year, double pricePerDay);

    void displayCarInfo();
    void setAvailability(bool availability);
};

#endif
