/**
* @file sayi.h
* @description Bir liste kullanarak sınırlandırılmamış boyutta bir sayıyı tutar. Her bir eleman bir rakamı temsil eder.
 * Başka bir sayı ile toplanabilecek şekilde tasarlanmıştır.
* @course 2A
* @assignment 2
* @date 5.11.2016
* @author Emirhan Aydın (g141210018@sakarya.edu.tr)
*/

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

    /**
     * Sayıyı verilen formatta konsol ekranına yazdırır.
     * @param bicim Yazdırılacak olan biçim.
     */
    void yazdir(Bicim bicim = ardisik);

    /**
     * Listenin son elemanını, yani tutulan son rakamı siler.
     */
    void rakamSil();

    void temizle();

    ~Sayi();
};

#endif