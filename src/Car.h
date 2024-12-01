#ifndef CAR_H
#define CAR_H

#include <string>
#include <iostream>

class Car {
public:
    // Constructor to initialize car details
    Car(int carID, const std::string& make, const std::string& model, int year, double pricePerDay);

    // Method to display car details
    void displayCarInfo() const;

    // Method to set the availability of the car
    void setAvailability(bool availability);

    // Getters for the car details
    int getCarID() const;
    const std::string& getMake() const;
    const std::string& getModel() const;
    int getYear() const;
    double getPricePerDay() const;
    bool getAvailability() const;

private:
    int carID;
    std::string make, model;
    int year;
    double pricePerDay;
    bool isAvailable;
};

#endif
