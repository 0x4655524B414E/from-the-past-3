#include "Number.h"
#include "Integer.h"
#include "PositiveInteger.h"
#include "Bool.h"
#include <iostream>

using namespace std;

int main() {
    Number *birthYear = new Integer(1973);
    int year = birthYear->toInteger(); // year holds 1973
    cout << "year == 1973                 : " << ((year == 1973) ? "OK" : "FAILED") << endl;
    Number *younger = (*birthYear)++;
    cout << "younger->toInteger() == 1974 : " << ((younger->toInteger() == 1974) ? "OK" : "FAILED") << endl;
    //Number counter; // should cause a compile error
    PositiveInteger numberOfStudent(0); // holds 0
    cout << "numberOfStudent holds 0      : " << ((numberOfStudent.toInteger() == 0) ? "OK" : "FAILED") << endl;
    numberOfStudent--; // still holds 0
    cout << "numberOfStudent still holds 0: " << ((numberOfStudent.toInteger() == 0) ? "OK" : "FAILED") << endl;
    Number *pos = &numberOfStudent;
    (*pos)++; // now numberOfStudent holds 1
    cout << "numberOfStudent now holds 1  : " << ((numberOfStudent.toInteger() == 1) ? "OK" : "FAILED") << endl;
    Bool isFull = True; // True is a constant Bool object and holds 1
    isFull++; // holds 0
    cout << "isFull holds 0               : " << ((isFull.toInteger() == 0) ? "OK" : "FAILED") << endl;
    isFull++; // holds 1
    cout << "isFull holds 1               : " << ((isFull.toInteger() == 1) ? "OK" : "FAILED") << endl;
    delete birthYear;
    delete younger;
    return 0;
}