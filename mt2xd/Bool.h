#include "Number.h"
#include <string>

using namespace std;

#ifndef __Bool__
#define __Bool__

class Bool : public Number {
private:
protected:
    int hold;
public:
    Bool(int= 0);

    int toInteger() const;

    Number *operator++(int);

    Number *operator--(int);
};

const Bool True(1);
const Bool False(0);
#endif
