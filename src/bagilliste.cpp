/**
* @file bagilliste.cpp
* @description Açıklama ilgili başlık dosyasında yapılmıştır.
* @course 2A
* @assignment 2
* @date 3.11.2016
* @author Emirhan Aydın (g141210018@sakarya.edu.tr)
*/

#include "bagilliste.h"

BagilListe::BagilListe() {
    _boyut = 0;
    _ilk = NULL;
    _son = NULL;
    _gezici = NULL;
}

Dugum *BagilListe::konumdaki(int indeks) const {
    *_gezici >> _ilk;

    for (int i = 0; i < _boyut; i++) {
        if (i == indeks)
            return _gezici->dugum();

        (*_gezici)++; // Gezici bir sonraki düğüme taşınır.
    }

//    TODO throw Exception();
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

bool operator==(const BagilListe &liste, const BagilListe &liste1) {
    return &liste == &liste1;
}

char BagilListe::getir(int indeks) const {
//    TODO if (indeks >= boyut || indeks < 0) throw Exception();

    if (indeks == _boyut - 1)
        return _son->rakam();

    Dugum *dugum = konumdaki(indeks);

//    TODO if (dugum == NULL) throw Exception();
    return dugum->rakam();
}

void BagilListe::ekle(char rakam, int indeks) {
//    TODO if (indeks >= _boyut) throw Exception();

    if (_boyut == 0) { // Listenin ilk elemanını ekleme işlemi.
        _ilk = new Dugum(rakam);
        _son = _ilk;
        if (_gezici == NULL)
            _gezici = new Gezici(_ilk);
        else
            *_gezici >> _ilk;
    } else if (indeks == 0) { // Liste başına eleman ekleme işlemi.
        _ilk = new Dugum(rakam, _ilk);
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

void BagilListe::sil(int indeks) {
//    TODO if (indeks >= _boyut) throw Exception();
//    TODO if (_boyut <= 0) throw Exception();
    if (_boyut < 1) return;

    if (indeks < 0) indeks = _boyut - 1;

    Dugum *silinecek;

    if (indeks == 0) { // İlk elemanı silme işlemi
        silinecek = _ilk;
        _ilk = silinecek->sonraki();
        *_gezici >> _ilk;
    } else if (indeks == _boyut - 1) { // Son elemanı silme işlemi
        silinecek = _son;
        _son = (*konumdaki(indeks - 1) >> NULL);
        *_gezici >> _son;
    } else { // Aradan eleman silme işlemi
        Dugum *onceki = konumdaki(indeks - 1);
        silinecek = onceki->sonraki();
        *onceki >> silinecek->sonraki();
        *_gezici >> onceki;
    }

    delete silinecek;
    _boyut--;
}

int BagilListe::boyut() const {
    return _boyut;
}

void BagilListe::temizle() {
    if (_boyut < 1) return;

    *_gezici >> _ilk; // Gezici liste başına alınır.

    Dugum *onceki;

//    Liste sonuna kadar tüm düğümler gezici ile gezilir ve tüm düğümler sırayla silinir.
    for (int i = 0; i < _boyut; i++) {
        onceki = _gezici->dugum(); // Gezicinin o an gösterdiği düğüm göstericide yedeklenir.
        (*_gezici)++; // Gezicinin gösterdiği düğüm bir ilerletilir.
        delete onceki; // Gezicinin gösterdiği düğümün bir öncesindeki düğüm silinir.
    }

    _ilk = _son = NULL;
    _boyut = 0;
}

BagilListe::~BagilListe() {
    temizle(); // Listedeki tüm düğümler silinir.
    delete _gezici;
}