/* 
 * File:   TestVehicle.cpp
 * Author: binnur.kurt
 *
 * Created on November 6, 2008, 4:55 PM
 */
#include "Vehicle.h"
#include <iostream>
using namespace std;
/*
 * 
 */
int main() {

    // Create a vehicle that can handle 10,000 kilograms weight
    cout << endl << "Creating a vehicle with a 10,000kg maximum load.";
    Vehicle *vehicle = new Vehicle(10000.0);

    // Add a few boxes
    cout << endl << "Add box #1 (500kg) : " << ((vehicle->addBox(500.0))?"true":"false");

    cout << endl << "Add box #2 (250kg) : " << ((vehicle->addBox(250.0))?"true":"false");

    cout << endl << "Add box #3 (5000kg) : " << ((vehicle->addBox(5000.0))?"true":"false");

    cout << endl << "Add box #4 (4000kg) : " << ((vehicle->addBox(4000.0))?"true":"false");

    cout << endl << "Add box #5 (300kg) : " << ((vehicle->addBox(300.0))?"true":"false");

    // Print out the final vehicle load
    cout << endl << "Vehicle load is " << vehicle->getLoad() << " kg\n";

    return (EXIT_SUCCESS);
}


