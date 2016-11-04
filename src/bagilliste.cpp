#include "bagilliste.h"

BagilListe::BagilListe() {
    _boyut = 0;
    _ilk = NULL;
    _son = NULL;
    _gezici = NULL;
}

int BagilListe::konum(Dugum *dugum) const {
    *_gezici >> _ilk; // Gezici ilk düğüme götürülür.

    for (int i = 0; i < _boyut; i++) {
        if (_gezici->dugum() == dugum)
            return i;

        (*_gezici)++; // Gezici bir sonraki düğüme taşınır.
    }

//    throw new exception();
    return -1;
}

Dugum *BagilListe::konumdaki(int indeks) const {
    *_gezici >> _ilk;

    for (int i = 0; i < _boyut; i++) {
        if (i == indeks)
            return _gezici->dugum();

        (*_gezici)++; // Gezici bir sonraki düğüme taşınır.
    }

//    throw new exception();
    return NULL;
}

std::ostream &operator<<(std::ostream &os, const BagilListe &liste) {
    Dugum *simdiki = liste._gezici->dugum();
    *liste._gezici >> liste._ilk;

    for (int i = 0; i < liste._boyut; i++) {
        os << liste._gezici->dugum()->rakam();
        (*liste._gezici)++; // Gezici bir sonraki düğüme taşınır.
    }

    *liste._gezici >> simdiki;

    return os;
}

char BagilListe::getir(int indeks) const {
//    if (indeks >= boyut || indeks < 0) throw exception;

    if (indeks == _boyut - 1)
        return _son->rakam();

    Dugum *dugum = konumdaki(indeks);

//    if (dugum == NULL) throw new exception();
    return dugum->rakam();
}

void BagilListe::ekle(char rakam, int indeks) {
//    if (indeks >= _boyut) throw new exception();

    if (_boyut == 0) { // Listenin ilk elemanını ekleme işlemi.
        _ilk = new Dugum(rakam);
        _son = _ilk;
        if (_gezici == NULL)
            _gezici = new Gezici(_ilk);
        else
            *_gezici >> _ilk;
    } else if (indeks == 0) { // Liste başına eleman ekleme işlemi.
        Dugum *onceki = _ilk;
        _ilk = new Dugum(rakam);
        *_ilk >> onceki;
    } else if (indeks == _boyut - 1 || indeks < 0) { // Liste sonuna eleman ekleme işlemi.
        Dugum *onceki = _son;
        _son = new Dugum(rakam);
        *onceki >> _son;
    } else { // Araya eleman ekleme işlemi.
        Dugum *onceki = konumdaki(indeks - 1);
        Dugum *yeni = new Dugum(rakam);
        *yeni >> onceki->sonraki();
        *onceki >> yeni;
        (*_gezici)++; // Gezici bir sonraki düğüme taşınır.
    }

    _boyut++;
}

void BagilListe::temizle() {
    *_gezici >> _ilk; // Gezici liste başına alınır.

    Dugum *onceki;
//    Liste sonuna kadar tüm düğümler gezici ile gezilir ve tüm düğümler sırayla silinir.
    for (int i = 0; i < _boyut; i++) {
        onceki = _gezici->dugum(); // Gezicinin o an gösterdiği düğüm göstericide yedeklenir.
        (*_gezici)++; // Gezicinin gösterdiği düğüm bir ilerletilir.
        delete onceki; // Gezicinin gösterdiği düğümün bir öncesindeki düğüm silinir.
    }
}

BagilListe::~BagilListe() {
    temizle(); // Listedeki tüm düğümler silinir.
    delete _gezici;
}