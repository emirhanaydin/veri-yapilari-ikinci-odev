#include "sayi.h"

Sayi::Sayi() {
    _liste = new BagilListe();
    _sayiKatari = new std::string();
}

std::istream &operator>>(std::istream &is, Sayi &sayi) {
    for (char c = 255; c != '\r'; c = _getch()) {
        if (c >= '0' && c <= '9') {
            std::cout << c;
            *sayi._sayiKatari += c;
        }
    }
//    is >> *sayi._sayiKatari;
    std::cout << *sayi._sayiKatari;

    return is;
}

std::ostream &operator<<(std::ostream &os, const Sayi &sayi) {
    os << *sayi._liste;

    return os;
}

Sayi::~Sayi() {
    delete _liste, _sayiKatari;
}