#ifndef SAYI_H
#define SAYI_H

#include <iostream>
#include <string>
#include <conio.h>
#include "bagilliste.h"

class Sayi {
private:
    BagilListe *_liste;
    std::string *_sayiKatari;
public:
    Sayi();

    friend std::istream &operator>>(std::istream &, Sayi &);

    friend std::ostream &operator<<(std::ostream &, const Sayi &);

    ~Sayi();
};

#endif