#include "bagilliste.h"

BagilListe::BagilListe() {
    boyut = 0;
    _ilk = NULL;
    _son = NULL;
    _gezici = NULL;
}

void BagilListe::ekle(Sayi *sayi) {
    if (boyut = 0) {
        _ilk = new Dugum(sayi);
        _son = _ilk;
    }

    Dugum *gecici = _son;
    _son = new Dugum(sayi);
    gecici = _son;
    boyut++;
}

Sayi BagilListe::getir(int indeks) const {
//    if (indeks >= boyut || indeks < 0) throw exception;

    if (indeks == boyut - 1)
        return *_son->sayi();

    _gezici->dugumeGit(_ilk);

    for (int i = 0; i < indeks; i++) {
        _gezici->ilerle();
    }

    return *_gezici->dugum()->sayi();
}

BagilListe::~BagilListe() {
}