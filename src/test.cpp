#include <iostream>
#include <stdlib.h>
#include "sayi.h"

using namespace std;

int main() {
    system("CLS");

    Sayi *sayi = new Sayi();

    cout << "Sayi: ";
    cin >> *sayi;

    cout << endl << *sayi;

    return 0;
}
