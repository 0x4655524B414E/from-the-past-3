#include "Interval.h"
#include <iostream>
using namespace std;

int main() {
   Interval ivl1(true,0.0,false,1.0); // [0.,1.)
   Interval ivl2(false,0.0,false,1.0); // (0.0,1.0)
   Interval ivl3 = ivl1 & ivl2;
   Interval ivl4 = ivl1 | ivl2;
   ivl1.print();
   ivl2.print();
   ivl3.print();
   ivl4.print();
   double testValues[]={0.,.5,1.};
   for (int i=0;i<sizeof(testValues)/sizeof(double);i++) 
       if (ivl4(testValues[i]))
          cout << testValues[i] << " resides in the interval" << endl ;
       else
          cout << testValues[i] << " does NOT reside in the interval" << endl ;
   if (ivl1==ivl2) 
          cout << ivl1 << " is equal to " << ivl2 << endl ;
       else
          cout << ivl1 << " is NOT equal to " << ivl2 << endl ;

   if (ivl1==ivl3) 
          cout << ivl1 << " is equal to " << ivl3 << endl ;
       else
          cout << ivl1 << " is NOT equal to " << ivl3 << endl ;

   if (ivl1==ivl4) 
          cout << ivl1 << " is equal to " << ivl4 << endl ;
       else
          cout << ivl1 << " is NOT equal to " << ivl4 << endl ;

   if (ivl2==ivl3) 
          cout << ivl2 << " is equal to " << ivl3 << endl ;
       else
          cout << ivl2 << " is NOT equal to " << ivl3 << endl ;

   if (ivl2==ivl4) 
          cout << ivl2 << " is equal to " << ivl4 << endl ;
       else
          cout << ivl2 << " is NOT equal to " << ivl4 << endl ;

   if (ivl3==ivl4) 
          cout << ivl3 << " is equal to " << ivl4 << endl ;
       else
          cout << ivl3 << " is NOT equal to " << ivl4 << endl ;
   return 0;
}
