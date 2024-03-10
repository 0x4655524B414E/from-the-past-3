#include "Interval.h"
#include <iostream>

using namespace std;

Interval::Interval(bool lowerBoundInc, double lowerBound, bool upperBoundInc, double upperBound) {
// fill codes here
this->lowerBoundIncluded = lowerBoundInc;
this->upperBoundIncluded =  upperBoundInc;
this->lowerBound = lowerBound;
this->upperBound = upperBound;
if (lowerBound == upperBound && lowerBoundIncluded == false && upperBoundIncluded == false)
{
    this->empty = true;
}
else
{
    this->empty = false;
}
}

bool Interval::operator==(const Interval &right) const {
// fill codes here
if (this->lowerBound == right.lowerBound && 
    this->upperBound == right.upperBound &&
    this->upperBoundIncluded == right.upperBoundIncluded &&
    this->lowerBoundIncluded == right.lowerBoundIncluded)
{
    return true;
}
return false;
}

bool Interval::operator()(double val) const {
// fill codes here 
if (this->lowerBound < val && this->upperBound > val) return true;
if (val == this->lowerBound) return this->lowerBoundIncluded;
if (val == this->upperBound) return this->upperBoundIncluded;
return false;
}
    double Interval::getLowerBound() const {
// fill codes here
return this->lowerBound;
    }

    double Interval::getUpperBound() const {
// fill codes here
return this->upperBound;
    }

    bool Interval::isLowerBoundIncluded() const {
// fill codes here
return this->lowerBoundIncluded;
    }

    bool Interval::isUpperBoundIncluded() const {
// fill codes here
return this->upperBoundIncluded;
    }

    void Interval::setLowerBound(bool lowerBoundIncluded, double lowerBound) {
// fill codes here
this->lowerBoundIncluded = lowerBoundIncluded;
this->lowerBound = lowerBound;
    }

    void Interval::setUpperBound(bool upperBoundIncluded, double upperBound) {
// fill codes here
this->upperBoundIncluded = upperBoundIncluded;
this->upperBound = upperBound;
    }

    void Interval::setBound(bool lowerBoundInc, double lowerBound, bool upperBoundInc, double upperBound) {
// fill codes here
this->lowerBoundIncluded = lowerBoundInc;
this->upperBoundIncluded =  upperBoundInc;
this->lowerBound = lowerBound;
this->upperBound = upperBound;
    }

    void Interval::print() const {
// fill codes here
char left = '(', right = ')';
if (this->lowerBoundIncluded) left = '[';
if (this->upperBoundIncluded) right = ']';
cout << left << this->lowerBound << "," << this->upperBound << right << endl;
    }

    bool Interval::contains(const Interval &right) const {
// fill codes here 
if (this->lowerBound < right.lowerBound && this->upperBound > right.upperBound) return true;
if (this->lowerBound == right.lowerBound && this->upperBound == right.upperBound)
{
    if (this->lowerBoundIncluded == false && right.lowerBoundIncluded == true) return false;
    if (this->upperBoundIncluded == false && right.upperBoundIncluded == true) return false;
    return true;
}
return false;
    }

    Interval Interval::operator&(const Interval &right) const {
// fill codes here
bool lowerBound = this->lowerBoundIncluded * right.lowerBoundIncluded;
bool upperBound = this->upperBoundIncluded * right.upperBoundIncluded;
double lower;
double upper;
this->lowerBound <= right.lowerBound ? lower = right.lowerBound : lower = this->lowerBound;
this->upperBound >= right.upperBound ? upper = right.upperBound : upper = this->upperBound;
return Interval(lowerBound, lower, upperBound, upper);
    }

    Interval Interval::operator|(const Interval &right) const {
// fill codes here
bool lowerBound = this->lowerBoundIncluded + right.lowerBoundIncluded;
bool upperBound = this->upperBoundIncluded + right.upperBoundIncluded;
double lower;
double upper;
this->lowerBound >= right.lowerBound ? lower = right.lowerBound : lower = this->lowerBound;
this->upperBound <= right.upperBound ? upper = right.upperBound : upper = this->upperBound;
return Interval(lowerBound, lower, upperBound, upper);
    }
    ostream &operator<<(ostream &out, const Interval &ivl) {
        char left = '(', right = ')';
        if (ivl.isLowerBoundIncluded()) left = '[';
        if (ivl.isUpperBoundIncluded()) right = ']';
        out << left << ivl.getLowerBound() << "," << ivl.getUpperBound() << right;
        return out;
    }