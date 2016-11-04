#include <iostream>
#include <stdlib.h>
#include "bagilliste.h"

using namespace std;

int main() {
    system("CLS");

    BagilListe *liste = new BagilListe();
    liste->ekle('0');
    liste->ekle('1');
    liste->ekle('2');
    liste->ekle('3');
    liste->ekle('4');
    liste->ekle('5');
    liste->ekle('6');
    liste->ekle('7');
    liste->ekle('8');
    liste->ekle('9');
    liste->ekle('9', 5);
    liste->ekle('0', 5);

    cout << *liste;

    delete liste;
    return 0;
}
