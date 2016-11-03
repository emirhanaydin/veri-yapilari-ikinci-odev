#include "sayi.h"

Sayi::Sayi(int rakam) {
    _rakam = rakam;
}

int Sayi::rakam() const {
    return _rakam;
}

std::ostream &operator<<(std::ostream &os, const Sayi &sayi) {
    os << sayi._rakam;

    return os;
}

Sayi &Sayi::operator=(int rakam) {
    //    if(deger < 0 || deger > 9) throw exception;
    _rakam = rakam;
}