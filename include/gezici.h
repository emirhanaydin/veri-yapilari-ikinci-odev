#ifndef GEZICI_H
#define GEZICI_H

#include "dugum.h"

class Gezici {
private:
    Dugum *_dugum;
public:
    Gezici(Dugum *dugum);

    const Sayi &alSayi() const;

    void ileri();
};

#endif