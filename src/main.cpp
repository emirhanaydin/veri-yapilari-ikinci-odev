/**
* @file main.cpp
* @description Kullanıcıdan iki farklı sayı alınır ve toplama işlemi uygulanarak sonuç ekrana yazdırılır.
* @course 2A
* @assignment 2
* @date 3.11.2016
* @author Emirhan Aydın (g141210018@sakarya.edu.tr)
*/

#include <iostream>
#include <secim.h>
#include "sayi.h"

using namespace std;

int main() {
    Sayi *sayi1 = new Sayi();
    Sayi *sayi2 = new Sayi();

    do {
        system("CLS");
        cout << "Toplamlari hesaplanacak olan uzunlugu sinirlandirilmamis iki sayi giriniz." << endl << endl;

//        Konsol::imleciGoster();

        sayi1->temizle();
        Konsol::renkliYazdir("1. sayi : ", 14);
        sayi1->sayiGir();

        sayi2->temizle();
        Konsol::renkliYazdir("2. sayi : ", 11);
//        cout << "2. sayi : ";
        sayi2->sayiGir();

        cout << endl;
        Konsol::renkliYazdir("1. liste: ", 14);
        sayi1->yazdir(Sayi::liste);

        cout << endl;
        Konsol::renkliYazdir("2. liste: ", 11);
        sayi2->yazdir(Sayi::liste);

        Sayi toplam = *sayi1 + *sayi2;

        cout << endl << endl;
        Konsol::renkliYazdir("Toplam  : ", 10);
        cout << toplam << endl;

        Konsol::renkliYazdir("Liste   : ", 10);
        toplam.yazdir(Sayi::liste);

        if (toplam.boyut() > 3) {
            cout << endl;
            Konsol::renkliYazdir("Noktali : ", 10);
            toplam.yazdir(Sayi::noktali);
        }

        cout << endl << endl;
        cout << "Yeni bir toplama islemi yapmak istiyor musunuz?" << endl << endl << endl;
//        Konsol::imleciGoster(false);
    } while (Secim::onayMenusu());

    delete sayi1;
    delete sayi2;

//    Konsol::imleciGoster();
    return 0;
}