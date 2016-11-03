#ifndef DUGUM_H
#define DUGUM_H

#include "sayi.h"

class Dugum {
private:
    Sayi *_sayi;
    Dugum *_sonraki;
public:
    Dugum();

    Sayi *sayi() const;

    Dugum *sonraki() const;
};

#endif