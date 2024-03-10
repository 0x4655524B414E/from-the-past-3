#include <string>

using namespace std;

#ifndef __Number__
#define __Number__

class Number {
private:
protected:
public:
    virtual int toInteger() const = 0;

    virtual Number *operator++(int) = 0;

    virtual Number *operator--(int) = 0;
};

#endif
