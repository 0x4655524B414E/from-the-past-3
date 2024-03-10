#include <iostream>

using namespace std;

#include "CMatrix.h"

int main(int argc, char *argv[]) {
    CMatrix m(2, 3);
    m(0, 0) = 4;
    m(0, 1) = 3;
    m(0, 2) = 7;
    m(1, 0) = 2;
    m(1, 1) = 1;
    m(1, 2) = 6;
    cout << m;
    CMatrix &n = ~m;
    cout << n;
    CMatrix &r = n / 2.0;
    cout << r;
    CMatrix &s = n * m;
    cout << s;
    cout << endl << "max=" << s.max();
    cout << endl << "min=" << s.min();
    return 0;
}




