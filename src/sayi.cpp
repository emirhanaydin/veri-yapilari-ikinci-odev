/**
* @file sayi.cpp
* @description Açıklama ilgili başlık dosyasında yapılmıştır.
* @course 2A
* @assignment 2
* @date 5.11.2016
* @author Emirhan Aydın (g141210018@sakarya.edu.tr)
*/

#include "sayi.h"
#include "islem.h"

Sayi::Sayi() {
    _liste = new BagilListe();
    _boyut = 0;
}

Sayi::Sayi(BagilListe *liste) {
    _liste = liste;
    _boyut = liste->boyut();
}

std::ostream &operator<<(std::ostream &os, const Sayi &sayi) {
    os << *sayi._liste;

    return os;
}

bool operator==(const Sayi &sayi, const Sayi &sayi1) {
    return &sayi == &sayi1;
}

Sayi operator+(const Sayi &sayi, const Sayi &sayi1) {
    return Islem::topla(sayi, sayi1);
}

int Sayi::boyut() const {
    return _boyut;
}

char Sayi::getir(int indeks) const {
//    TODO if (indeks >= _boyut || indeks < 0) throw Exception();

    return _liste->getir(indeks);
}

void Sayi::sayiGir() {
    Islem::sayiGir(*this); // Islem sınıfının, konsoldan alınan değerleri Sayi'nın listesine uygun biçimde aktaracak
//    olan ilgili metot çağrılır.
}

void Sayi::ekle(char rakam, int indeks) {
    _liste->ekle(rakam, indeks);
    _boyut++;
}

void Sayi::yazdir(Sayi::Bicim bicim) {
    switch (bicim) {
        case ardisik:
            std::cout << *this;
            break;
        case liste:
            Islem::ayrikYazdir(*this);
            break;
        case noktali:
            Islem::noktaliYazdir(*this);
            break;
    }
}

void Sayi::rakamSil() {
//    TODO if (_boyut <= 0) throw Exception();

    _liste->sil(); // En son eleman diziden silinir.
    _boyut--;
}

void Sayi::temizle() {
    if (_boyut < 1)
        return;

    _liste->temizle();
    _boyut = 0;
}

Sayi::~Sayi() {
    delete _liste;
}