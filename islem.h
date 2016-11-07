#ifndef ISLEM_H
#define ISLEM_H

#include <iostream>
#include "sayi.h"

class Islem {
public:
    static void sayiGir(Sayi &sayi);

    static Sayi topla(const Sayi &sayi, const Sayi &sayi1);

    static void ayrikYazdir(Sayi &);

    static void noktaliYazdir(Sayi &);
};

#endif