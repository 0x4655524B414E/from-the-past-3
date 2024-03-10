#ifndef __Interval__
#define __Interval__
#include <iostream>
using namespace std;

class Interval {
   private:
     double upperBound,lowerBound ;
     bool   lowerBoundIncluded;
     bool   upperBoundIncluded;
     bool   empty;   
   public:
     // Constructor
     // Note that default interval is [0,1]
     Interval(bool=true,double=0.0,bool=true,double=1.0); 

     void print() const ; 
     // set/get methods
     double getLowerBound() const ;
     double getUpperBound() const ;
     bool isLowerBoundIncluded() const ;
     bool isUpperBoundIncluded() const ;
     void setLowerBound(bool,double);
     void setUpperBound(bool,double);
     void setBound(bool,double,bool,double);

     // Compares two interval
     // return true if they are equal
     // return false otherwise
     bool operator==(const Interval&) const ;

     // Tests whether the parameter resides in the interval
     // return true if the parameter resides in the interval
     // return false otherwise
     bool operator()(double) const ; 

     // Returns the intersection of two Intervals
     // Example #1: intersection of (0,5] and [1,7] is [1,5]
     // Example #2: intersection of (0,3] and [0,4] is (0,3]
     // Example #3: intersection of (0,3] and [0,3) is (0,3)
     // Example #4: intersection of (0,3] and (3,7) is empty set
     // Example #5: intersection of (0,3] and (5,7) is empty set
     // Example #6: intersection of empty set and any interval is empty set
     Interval operator&(const Interval &) const ; 

     // Returns the union of two Intervals
     // Example #1: union of (0,5] and [1,7] is (0,7]
     // Example #2: union of (0,3] and [0,4] is [0,4]
     // Example #3: union of empty and [0,3) is (0,3)
     Interval operator|(const Interval &) const ;
 
     // returns true if the interval fully contains the interval given by the parameter
     // returns false otherwise 
     // Example #1: [2,7] contains [4,5]
     // Example #2: [2,7] does not contain [1,5]     
     // Example #3: (2,7] does not contain [2,7]     
     // Example #3: [2,7] contains (2,7]     
     bool contains(const Interval &)const;
};
ostream& operator<<(ostream&,const Interval &);
#endif