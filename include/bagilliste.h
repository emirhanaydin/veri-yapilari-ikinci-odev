#ifndef BAGILLISTE_H
#define BAGILLISTE_H

#include "dugum.h"
#include "gezici.h"

class BagilListe {
private:
    Dugum *_dugum;
    Gezici *_gezici;
public:
    BagilListe();
    ~BagilListe();
};

#endif