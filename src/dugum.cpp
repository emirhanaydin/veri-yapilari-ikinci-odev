#include "dugum.h"

Dugum::Dugum() {
    _rakam = NULL;
    _sonraki = NULL;
}

Dugum::Dugum(char rakam, Dugum *sonraki) {
//    if (!rakamiDenetle(rakam)) throw new exception();
    _rakam = new char(rakam);
    _sonraki = sonraki;
}

Dugum &Dugum::operator=(char rakam) {
//    if (!rakamiDenetle(rakam)) throw new exception();
    if (_rakam == NULL) _rakam = new char(rakam);
    else *_rakam = rakam;

    return *this;
}

Dugum *Dugum::operator>>(Dugum *dugum) {
    _sonraki = dugum;

    return this;
}

bool Dugum::rakamiDenetle(char &rakam) const {
    char sayisalDeger = rakam - '0';
    return sayisalDeger >= 0 && sayisalDeger <= 9;
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