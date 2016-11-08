#include "gezici.h"

Gezici::Gezici(Dugum *dugum) {
    _dugum = dugum;
}

Gezici *Gezici::operator++(int) {
    _dugum = _dugum->sonraki();

    return this;
}

Gezici *Gezici::operator>>(Dugum *dugum) {
    _dugum = dugum;

    return this;
}

Dugum *Gezici::dugum() const {
    return _dugum;
}