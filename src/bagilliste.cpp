#include "bagilliste.h"

BagilListe::BagilListe() {
    _dugum = new Dugum();
    _gezici = new Gezici(_dugum);
}

BagilListe::~BagilListe() {
    delete dugum;
}