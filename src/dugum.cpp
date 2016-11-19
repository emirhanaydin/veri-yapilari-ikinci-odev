/**
* @file dugum.cpp
* @description Açıklama ilgili başlık dosyasında yapılmıştır.
* @course 2A
* @assignment 2
* @date 3.11.2016
* @author Emirhan Aydın (g141210018@sakarya.edu.tr)
*/

#include "dugum.h"

Dugum::Dugum() {
    _rakam = NULL;
    _sonraki = NULL;
}

Dugum::Dugum(char karakter, Dugum *sonraki) {
    _rakam = new char(karakter);
    _sonraki = sonraki;
}

Dugum &Dugum::operator=(char karakter) {
    if (_rakam == NULL) _rakam = new char(karakter);
    else *_rakam = karakter;

    return *this;
}

Dugum *Dugum::operator>>(Dugum *dugum) {
    _sonraki = dugum;

    return this;
}

char Dugum::rakam() const {
    return *_rakam;
}

Dugum *Dugum::sonraki() const {
    return _sonraki;
}

Dugum::~Dugum() {
    delete _rakam;
}