#ifndef GEZICI_H
#define GEZICI_H

#include "dugum.h"

class Gezici {
private:
    Dugum *_dugum;
public:
    Gezici(Dugum *dugum);

    Gezici *operator++(int);

    Dugum *dugum() const;
};

#endif