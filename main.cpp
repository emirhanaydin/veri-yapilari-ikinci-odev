#include <iostream>
#include "bagilliste.h"
#include "sayi.h"

using namespace std;

int main() {
    Sayi *sayi = new Sayi();

    sayi->sayiGir();

    cout << endl << *sayi;

    delete sayi;

    _getch();
    return 0;
}