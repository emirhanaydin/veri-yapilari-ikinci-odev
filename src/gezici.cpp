#include "gezici.h"

Gezici::Gezici(Dugum *dugum) {
    _dugum = dugum;
}

const Sayi& Gezici::alSayi() const {
    return *_dugum->sayi();
}

void Gezici::ileri() {
    _dugum = _dugum->sonraki();
}