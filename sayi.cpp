#include "sayi.h"
#include "konsol.h"

Sayi::Sayi() {
    _liste = new BagilListe();
    _boyut = 0;
}

std::ostream &operator<<(std::ostream &os, const Sayi &sayi) {
    os << *sayi._liste;

    return os;
}

void Sayi::sayiGir() {
    for (char c = '\0'; c != '\r'; c = (char) _getch()) {
        if (c >= '0' && c <= '9') {
            std::cout << c;
            _liste->ekle(c);
            _boyut++;
        } else if (c == (char)8 && _boyut > 0) {
            Konsol::sil();
            _liste->sil();
            _boyut--;
        }
    }
}

Sayi::~Sayi() {
    delete _liste;
}