#include "gezici.h"

Gezici::Gezici(Dugum *dugum) {
    _dugum = dugum;
}

Gezici *Gezici::operator++(int) {
    _dugum = _dugum->sonraki();

    return this;
}

Dugum *Gezici::dugum() const {
    return _dugum;
}