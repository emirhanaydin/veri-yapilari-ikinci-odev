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

    Sayi(BagilListe *);

    friend std::ostream &operator<<(std::ostream &, const Sayi &);

    friend bool operator==(const Sayi &, const Sayi &);

    friend Sayi operator+(const Sayi &, const Sayi &);

    enum Bicim {
        ardisik,
        liste,
        noktali
    };

    int boyut() const;

    char getir(int) const;

    void sayiGir();

    void ekle(char rakam, int indeks = -1);

    void yazdir(Bicim bicim = ardisik);

    void rakamSil();

    ~Sayi();
};

#endif