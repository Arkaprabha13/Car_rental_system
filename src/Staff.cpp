#include "Staff.h"
#include <iostream>
#include <vector>
#include "Car.h"
#include "Rental.h"
#include "Customer.h"
using namespace std;

void Staff::dashboard(std::vector<Car>& carList, std::vector<Rental>& rentalList, std::vector<Customer>& customerList) {
    cout << "Welcome, Staff " << getName() << endl;
    bool running = true;

    while (running) {
        cout << "\nChoose an option:" << endl;
        cout << "1. Add Car" << endl;
        cout << "2. Update Transaction" << endl;
        cout << "3. Rate Customer" << endl;
        cout << "4. Exit" << endl;
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                addCar(carList);
                break;
            case 2:
                updateTransaction(rentalList);
                break;
            case 3:
                rateCustomer(customerList);
                break;
            case 4:
                cout << "Exiting the dashboard." << endl;
                running = false;
                break;
            default:
                cout << "Invalid option. Try again." << endl;
        }
    }
}

void Staff::addCar(std::vector<Car>& carList) {
    int carID;
    string make, model;
    int year;
    double pricePerDay;

    cout << "Enter Car Details:" << endl;
    cout << "Car ID: ";
    cin >> carID;
    cout << "Make: ";
    cin >> make;
    cout << "Model: ";
    cin >> model;
    cout << "Year: ";
    cin >> year;
    cout << "Price per day: ";
    cin >> pricePerDay;

    Car newCar(carID, make, model, year, pricePerDay);
    carList.push_back(newCar);

    cout << "Car added successfully!" << endl;
}

void Staff::updateTransaction(std::vector<Rental>& rentalList) {
    int rentalID;
    std::string status;

    std::cout << "Enter Rental ID to update: ";
    std::cin >> rentalID;

    bool found = false;
    for (auto& rental : rentalList) {
        if (rental.getRentalID() == rentalID) {
            found = true;
            std::cout << "Enter new status (Returned / Ongoing): ";
            std::cin >> status;

            rental.setStatus(status);  // Update the rental status

            if (status == "Returned") {
                rental.returnCar();  // If returned, make the car available again
            }

            std::cout << "Rental status updated successfully!" << std::endl;
            break;
        }
    }

    if (!found) {
        std::cout << "Rental ID not found!" << std::endl;
    }
}


void Staff::rateCustomer(std::vector<Customer>& customerList) {
    string customerID;
    int rating;

    cout << "Enter Customer ID to rate: ";
    cin >> customerID;

    bool found = false;
    for (auto& customer : customerList) {
        if (customer.getCustomerID() == customerID) {
            found = true;
            cout << "Enter rating (1 to 5): ";
            cin >> rating;

            if (rating < 1 || rating > 5) {
                cout << "Invalid rating! Please enter a rating between 1 and 5." << endl;
                return;
            }

            customer.setRating(rating);
            cout << "Customer rated successfully!" << endl;
            break;
        }
    }

    if (!found) {
        cout << "Customer ID not found!" << endl;
    }
}
