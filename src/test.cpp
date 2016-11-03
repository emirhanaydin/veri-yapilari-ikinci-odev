#include <iostream>
#include "sayi.h"
#include "dugum.h"
#include "gezici.h"

using namespace std;

int main() {
    Dugum *dugum = new Dugum(10);
    Dugum *dugum1 = new Dugum(25, dugum);
    Dugum *dugum2 = new Dugum(35, dugum1);

    Gezici *gezici = new Gezici(dugum2);
    cout << *gezici->dugum() << endl;
    cout << *gezici->ilerle() << endl;
    cout << *gezici->ilerle() << endl;

    delete dugum, dugum1, dugum2, gezici;
    return 0;
}
