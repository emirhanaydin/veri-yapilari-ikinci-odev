#ifndef SAYI_H
#define SAYI_H

#include <iostream>
#include <conio.h>
#include "bagilliste.h"

class Sayi {
private:
    BagilListe *_liste;
    int _boyut;
public:
    Sayi();

    friend std::ostream &operator<<(std::ostream &, const Sayi &);

    void sayiGir();

    ~Sayi();
};

#endif