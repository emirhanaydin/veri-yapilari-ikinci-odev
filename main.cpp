#include <iostream>
#include "bagilliste.h"
#include "sayi.h"
#include "islem.h"

using namespace std;

int main() {
    Sayi *sayi = new Sayi();
    cout << "1. sayi: ";
    Islem::sayiGir(*sayi);

    Sayi *sayi1 = new Sayi();
    cout << "2. sayi: ";
    Islem::sayiGir(*sayi1);

    Sayi sayi2 = Islem::topla(*sayi, *sayi1);

    cout << endl << "Toplam:  " << sayi2;

    delete sayi, sayi1, sayi2;

    _getch();
    return 0;
}