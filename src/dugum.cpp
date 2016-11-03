#include "dugum.h"

Dugum::Dugum() {
    _sayi = new Sayi();
    _sonraki = NULL;
}

Dugum::Dugum(Sayi *sayi, Dugum *sonraki) {
    _sayi = sayi;
    _sonraki = sonraki;
}

std::ostream &operator<<(std::ostream &os, const Dugum &dugum) {
    os << *dugum._sayi;

    return os;
}

Sayi *Dugum::sayi() const {
    return _sayi;
}

Dugum *Dugum::sonraki() const {
    return _sonraki;
}

Dugum::~Dugum() {
    delete _sayi;
}