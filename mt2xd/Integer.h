#include "Number.h"
#include <string>

using namespace std;
#ifndef __Integer__
#define __Integer__

class Integer : public Number {
private:
protected:
    int hold;
public:
    Integer(int= 0);

    int toInteger() const;

    Number *operator++(int);

    Number *operator--(int);
};

#endif
