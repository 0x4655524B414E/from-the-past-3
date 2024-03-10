#include "Interval.h"
#include <iostream>

using namespace std;

Interval::Interval(bool lowerBoundInc, double lowerBound, bool upperBoundInc, double upperBound) {
    if (lowerBound > upperBound) {
        empty = true;
        return;
    }
    this->upperBound = upperBound;
    this->lowerBound = lowerBound;
    this->upperBoundIncluded = upperBoundInc;
    this->lowerBoundIncluded = lowerBoundInc;
    empty = false;
}

bool Interval::operator==(const Interval &right) const {
    if ((empty) || (right.empty)) return true;
    if ((lowerBound != right.lowerBound)) return false;
    if ((upperBound != right.upperBound)) return false;
    if ((lowerBoundIncluded != right.lowerBoundIncluded)) return false;
    if ((upperBoundIncluded != right.upperBoundIncluded)) return false;
    return true;
}

bool Interval::operator()(double val) const {
    if (empty) return false;
    if ((val > lowerBound) && (val < upperBound))
        return true;
    if ((lowerBoundIncluded) && (lowerBound == val)) return true;
    if ((upperBoundIncluded) && (upperBound == val)) return true;
    return false;
}

double Interval::getLowerBound() const {
    return lowerBound;
}

double Interval::getUpperBound() const {
    return upperBound;
}

bool Interval::isLowerBoundIncluded() const {
    return lowerBoundIncluded;
}

bool Interval::isUpperBoundIncluded() const {
    return upperBoundIncluded;
}

void Interval::setLowerBound(bool lowerBoundIncluded, double lowerBound) {
    if (this->upperBound < lowerBound) return;
    this->lowerBoundIncluded = lowerBoundIncluded;
}

void Interval::setUpperBound(bool upperBoundIncluded, double upperBound) {
    if (this->lowerBound > lowerBound) return;
    this->upperBoundIncluded = upperBoundIncluded;
}

void Interval::setBound(bool lowerBoundInc, double lowerBound, bool upperBoundInc, double upperBound) {
    if (lowerBound > upperBound) {
        empty = true;
        return;
    }
    this->upperBound = upperBound;
    this->lowerBound = lowerBound;
    this->upperBoundIncluded = upperBoundInc;
    this->lowerBoundIncluded = lowerBoundInc;
    empty = false;
}

void Interval::print() const {
    char left = '(', right = ')';
    if (lowerBoundIncluded) left = '[';
    if (upperBoundIncluded) right = ']';
    cout << left << lowerBound << "," << upperBound << right << endl;
}

bool Interval::contains(const Interval &right) const {
    if ((*this)(right.lowerBound) && (*this)(right.upperBound))
        return true;
    return false;
}

Interval Interval::operator&(const Interval &right) const {
    double lowerBound;
    bool lowerBoundIncluded;
    if (this->lowerBound > right.lowerBound) {
        lowerBound = this->lowerBound;
        lowerBoundIncluded = this->lowerBoundIncluded;
    } else if (this->lowerBound == right.lowerBound) {
        lowerBound = this->lowerBound;
        lowerBoundIncluded = this->lowerBoundIncluded && right.lowerBoundIncluded;
    } else {
        lowerBound = right.lowerBound;
        lowerBoundIncluded = right.lowerBoundIncluded;
    }
    double upperBound;
    bool upperBoundIncluded;
    if (this->upperBound < right.upperBound) {
        upperBound = this->upperBound;
        upperBoundIncluded = this->upperBoundIncluded;
    } else if (this->upperBound == right.upperBound) {
        upperBound = this->upperBound;
        upperBoundIncluded = this->upperBoundIncluded && right.upperBoundIncluded;
    } else {
        upperBound = right.upperBound;
        upperBoundIncluded = right.upperBoundIncluded;
    }
    return Interval(lowerBoundIncluded, lowerBound, upperBoundIncluded, upperBound);
}

Interval Interval::operator|(const Interval &right) const {
    double lowerBound;
    bool lowerBoundIncluded;
    if (this->lowerBound < right.lowerBound) {
        lowerBound = this->lowerBound;
        lowerBoundIncluded = this->lowerBoundIncluded;
    } else if (this->lowerBound == right.lowerBound) {
        lowerBound = this->lowerBound;
        lowerBoundIncluded = this->lowerBoundIncluded || right.lowerBoundIncluded;
    } else {
        lowerBound = right.lowerBound;
        lowerBoundIncluded = right.lowerBoundIncluded;
    }
    double upperBound;
    bool upperBoundIncluded;
    if (this->upperBound > right.upperBound) {
        upperBound = this->upperBound;
        upperBoundIncluded = this->upperBoundIncluded;
    } else if (this->upperBound == right.upperBound) {
        upperBound = this->upperBound;
        upperBoundIncluded = this->upperBoundIncluded || right.upperBoundIncluded;
    } else {
        upperBound = right.upperBound;
        upperBoundIncluded = right.upperBoundIncluded;
    }
    return Interval(lowerBoundIncluded, lowerBound, upperBoundIncluded, upperBound);
}

ostream &operator<<(ostream &out, const Interval &ivl) {
    char left = '(', right = ')';
    if (ivl.isLowerBoundIncluded()) left = '[';
    if (ivl.isUpperBoundIncluded()) right = ']';
    out << left << ivl.getLowerBound() << "," << ivl.getUpperBound() << right;
    return out;
}    
