#include <iostream>
#include "dugum.h"
#include "gezici.h"

using namespace std;

int main() {
    Dugum *dugum = new Dugum('1');
    Dugum *dugum1 = new Dugum('5');
    Dugum *dugum2 = new Dugum('9');

    *dugum >> dugum1;
    *dugum1 >> dugum2;

    cout << dugum->rakam() << endl;
    cout << dugum1->rakam() << endl;
    cout << dugum2->rakam();

    *dugum = '7';

    cout << endl << dugum->rakam() << endl;

    Gezici *gezici = new Gezici(dugum);
    cout << gezici->dugum()->rakam() << endl;
    cout << (*gezici)++->dugum()->rakam() << endl;
    cout << (*gezici)++->dugum()->rakam() << endl;

    delete dugum, dugum1, dugum2, gezici;
    return 0;
}
