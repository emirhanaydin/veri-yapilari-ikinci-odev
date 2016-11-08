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
    return _liste->getir(indeks);
}

void Sayi::ekle(char rakam, int indeks) {
    _liste->ekle(rakam, indeks);
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