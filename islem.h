#ifndef ISLEM_H
#define ISLEM_H

#include <iostream>
#include "sayi.h"

class Islem {
public:
    static void sayiGir(Sayi &sayi);

    static Sayi &topla(Sayi &sayi, Sayi &sayi1);

    static void ayrikYazdir(Sayi &);

    static void noktaliYazdir(Sayi &);
};

#endif