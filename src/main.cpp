#include <iostream>
#include <secim.h>
#include "sayi.h"

using namespace std;

int main() {
    bool tekrar;

    do {
        system("CLS");
        cout << "Toplamlarini hesaplamak uzere, uzunlugu sinirlandirilmamis iki sayi giriniz." << endl << endl;

        Konsol::imleciGoster();

        Sayi *sayi = new Sayi();
        cout << "1. sayi : ";
        sayi->sayiGir();

        Sayi *sayi1 = new Sayi();
        cout << "2. sayi : ";
        sayi1->sayiGir();

        cout << endl << "1. liste: ";
        sayi->yazdir(Sayi::liste);

        cout << endl << "2. liste: ";
        sayi1->yazdir(Sayi::liste);

        Sayi sayi2 = *sayi + *sayi1;

        cout << endl << endl << "Toplam  : " << sayi2 << endl;

        cout << "Liste   : ";
        sayi2.yazdir(Sayi::liste);

        if (sayi2.boyut() > 3) {
            cout << endl << "Noktali : ";
            sayi2.yazdir(Sayi::noktali);
        }

        delete sayi;
        delete sayi1;

        cout << endl << endl;
        cout << "Yeni bir toplama islemi yapmak istiyor musunuz?" << endl << endl << endl;
        Konsol::imleciGoster(false);

        tekrar = Secim::onayMenusu();
    } while (tekrar);

    Konsol::imleciGoster();
    return 0;
}