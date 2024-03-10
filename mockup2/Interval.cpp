#include "Interval.h"
#include <iostream>

using namespace std;

Interval::Interval(bool lowerBoundInc, double lowerBound, bool upperBoundInc, double upperBound) 
 : lowerBoundIncluded(lowerBoundInc), lowerBound(lowerBound), upperBoundIncluded(upperBoundInc), upperBound(upperBound) 
{
// fill codes here
if (this->lowerBound == this->upperBound && !(this->lowerBoundIncluded == this->upperBoundIncluded == true))
{
    this->empty = true;
}
this->empty = false;
}

bool Interval::operator==(const Interval &right) const {
// fill codes here
if (
    this->lowerBound == right.lowerBound &&
    this->upperBound == right.upperBound &&
    this->lowerBoundIncluded == right.lowerBoundIncluded &&
    this->upperBoundIncluded == right.upperBoundIncluded
   )
{
    return true;
}
return false;
}

bool Interval::operator()(double val) const {
// fill codes here
if (this->lowerBound > val || val > this->upperBound) return false;
if (this->lowerBound == val && !this->lowerBoundIncluded) return false;
if (this->upperBound == val && !this->upperBoundIncluded) return false;
return true;
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
if (this->upperBound < lowerBound) return;
this->lowerBoundIncluded = lowerBoundIncluded;
this->lowerBound = lowerBound;
    }

    void Interval::setUpperBound(bool upperBoundIncluded, double upperBound) {
// fill codes here
if (upperBound < this->lowerBound) return;
this->upperBoundIncluded = upperBoundIncluded;
this->upperBound = upperBound;
    }

    void Interval::setBound(bool lowerBoundInc, double lowerBound, bool upperBoundInc, double upperBound) {
// fill codes here
if (upperBound < lowerBound) return;
this->lowerBoundIncluded = lowerBoundInc;
this->lowerBound = lowerBound;
this->upperBoundIncluded = upperBoundInc;
this->upperBound = upperBound;
    }

    void Interval::print() const {
// fill codes here
char left = '(', right = ')';
if (this->isLowerBoundIncluded()) left = '[';
if (this->isUpperBoundIncluded()) right = ']';
cout << left << this->getLowerBound() << "," << this->getUpperBound() << right;
    }

    bool Interval::contains(const Interval &right) const {
// fill codes here 
if (right.empty) return true;
if (this->lowerBound > right.lowerBound || this->upperBound < right.upperBound) return false;
if (this->lowerBound == right.lowerBound && !this->lowerBoundIncluded && right.lowerBoundIncluded) return false;
if (this->upperBound == right.upperBound && !this->upperBoundIncluded && right.upperBoundIncluded) return false;
return true;
    }

    Interval Interval::operator&(const Interval &right) const {
// fill codes here
double upperBound, lowerBound;
bool lowerBoundIncluded;
bool upperBoundIncluded;
if (this->upperBound >= right.upperBound)
{
    upperBound = right.upperBound;
}
else
{
    upperBound = this->upperBound;
}
if (this->lowerBound <= right.lowerBound)
{
    lowerBound = right.lowerBound;
}
else
{
    lowerBound = this->lowerBound;
}
lowerBoundIncluded = this->lowerBoundIncluded * right.lowerBoundIncluded;
upperBoundIncluded = this->upperBoundIncluded * right.upperBoundIncluded;
return Interval(lowerBoundIncluded, lowerBound, upperBoundIncluded, upperBound);
    }

    Interval Interval::operator|(const Interval &right) const {
// fill codes here
double upperBound, lowerBound;
bool lowerBoundIncluded;
bool upperBoundIncluded;
if (!(this->upperBound >= right.upperBound))
{
    upperBound = right.upperBound;
}
else
{
    upperBound = this->upperBound;
}
if (!(this->lowerBound <= right.lowerBound))
{
    lowerBound = right.lowerBound;
}
else
{
    lowerBound = this->lowerBound;
}
lowerBoundIncluded = this->lowerBoundIncluded + right.lowerBoundIncluded;
upperBoundIncluded = this->upperBoundIncluded + right.upperBoundIncluded;
return Interval(lowerBoundIncluded, lowerBound, upperBoundIncluded, upperBound);
    }

    ostream &operator<<(ostream &out, const Interval &ivl) {
        char left = '(', right = ')';
        if (ivl.isLowerBoundIncluded()) left = '[';
        if (ivl.isUpperBoundIncluded()) right = ']';
        out << left << ivl.getLowerBound() << "," << ivl.getUpperBound() << right;
        return out;
    }