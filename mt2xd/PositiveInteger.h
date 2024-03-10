#include "Number.h"
#include <string>

using namespace std;
#ifndef __Positive_Integer__
#define __Positive_Integer__

class PositiveInteger : public Number {
private:
protected:
    int hold;
public:
    PositiveInteger(int= 0);

    int toInteger() const;

    Number *operator++(int);

    Number *operator--(int);
};

#endif
