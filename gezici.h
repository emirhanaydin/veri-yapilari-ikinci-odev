#ifndef GEZICI_H
#define GEZICI_H

#include "dugum.h"

class Gezici {
private:
    Dugum *_dugum;
public:
    Gezici(Dugum *);

    Gezici *operator++(int);

    Gezici *operator>>(Dugum *);

    Dugum *dugum() const;
};

#endif