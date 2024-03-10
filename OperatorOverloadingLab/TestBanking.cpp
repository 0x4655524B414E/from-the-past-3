/* 
 * File:   TestBanking.cpp
 * Author: binnur.kurt
 *
 * Created on November 9, 2008, 7:39 PM
 */

#include <iostream>
using namespace std;
#include "Bank.h"
#include "Customer.h"
/*
 * 
 */
int main(int argc, char** argv) {
    Bank denizBank;

    denizBank.addCustomer("Jane", "Simms");
    denizBank.addCustomer("Owen", "Bryant");
    denizBank.addCustomer("Tim", "Soley");
    denizBank.addCustomer("Maria", "Soley");

    for ( int i = 0; i < denizBank.getNumberOfCustomers(); i++ ) {
      Customer *customer = denizBank.getCustomer(i);

      cout << "Customer [" 
           << (i+1) << "] is "
	   << customer->getLastName()
	   << ", " 
           << customer->getFirstName() 
           << endl  ;     
    }

    //Bank garantiBank(denizBank);

    return (EXIT_SUCCESS);
}

