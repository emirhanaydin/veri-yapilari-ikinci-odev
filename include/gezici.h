#ifndef GEZICI_H
#define GEZICI_H

#include "dugum.h"

class Gezici {
private:
    Dugum *_dugum;
public:
    Gezici(Dugum *dugum);

    Dugum *dugum() const;

    Dugum *ilerle();
};

#endif