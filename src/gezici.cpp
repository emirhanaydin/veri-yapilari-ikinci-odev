#include "gezici.h"

Gezici::Gezici(Dugum *dugum) {
    _dugum = dugum;
}

Dugum *Gezici::dugum() const {
    return _dugum;
}

Dugum *Gezici::ilerle() {
    _dugum = _dugum->sonraki();

    return _dugum;
}