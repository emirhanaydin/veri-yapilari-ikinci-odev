#include "dugum.h"

Dugum::Dugum() {
    _sayi = 0;
    _sonraki = 0;
}

Sayi *Dugum::sayi() {
    return _sayi;
}

Dugum *Dugum::sonraki() {
    return _sonraki;
}