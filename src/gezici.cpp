/**
* @file gezici.cpp
* @description Açıklama ilgili başlık dosyasında yapılmıştır.
* @course 2A
* @assignment 2
* @date 3.11.2016
* @author Emirhan Aydın (g141210018@sakarya.edu.tr)
*/

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