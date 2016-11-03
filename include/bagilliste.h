#ifndef BAGILLISTE_H
#define BAGILLISTE_H

#include "dugum.h"
#include "gezici.h"

class BagilListe {
private:
    int boyut;
    Dugum *_ilk; // Mevcut düğümü belirtir.
    Dugum *_son; // Son düğümü belirtir.
    Gezici *_gezici;
public:
    BagilListe();

    void ekle(Sayi);

    Sayi getir(int) const;

    ~BagilListe();
};

#endif