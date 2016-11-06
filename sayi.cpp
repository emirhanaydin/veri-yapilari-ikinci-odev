#include "sayi.h"

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

Sayi &operator+(const Sayi &sayi, const Sayi &sayi1) {
    Sayi *yeni = new Sayi(&(*sayi._liste + *sayi1._liste));

    return *yeni;
}

int Sayi::boyut() const {
    return _boyut;
}

char Sayi::getir(int indeks) const {
    return _liste->getir(indeks);
}

void Sayi::rakamEkle(char rakam) {
    _liste->ekle(rakam);
    _boyut++;
}

void Sayi::rakamSil() {
    if (_boyut <= 0) return; // Hata durumu

    _liste->sil();
    _boyut--;
}

Sayi::~Sayi() {
    delete _liste;
}