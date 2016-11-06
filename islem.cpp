#include "islem.h"
#include "konsol.h"

void Islem::sayiGir(Sayi &sayi) {
    int boyut;

    for (char c = '\0';; c = (char) _getch()) {
        boyut = sayi.boyut();
        if (c == '\r' && boyut > 0) break; // ENTER basılmışsa ve boyut 0'dan fazlaysa döngüden çıkılır.
        else if (c >= '0' && c <= '9') { // Karakter bir rakam ise listeye eklenir.
            if (c == '0' && boyut < 1) continue; // Eğer girilecek olan ilk elemansa 0 olmasına izin verilmez.
            std::cout << c;
            sayi.rakamEkle(c);
        } else if (c == (char) 8 && boyut > 0) { // BACKSPACE basılmışsa ve boyut 0'dan fazlaysa karakter silinir.
            Konsol::sil(); // Karakter listeden silinmeden önce konsol ekranından silinir.
            sayi.rakamSil();
        }
    }

    std::cout << std::endl;
}

Sayi &Islem::topla(Sayi &sayi, Sayi &sayi1) {
    return sayi + sayi1;
}

void Islem::ayrikYazdir(Sayi &sayi) {
    for (int i = 0, j = sayi.boyut(); i < j; i++) {
        for (int k = 0; k < 2; k++) {
            if (k == 0)
                std::cout << sayi.getir(i);
            else if (i < j - 1)
                std::cout << '-';
        }
    }
}

void Islem::noktaliYazdir(Sayi &sayi) {
    int boyut = sayi.boyut();
    int noktaSayaci = 3 - (boyut % 3);
    if (noktaSayaci == 3) noktaSayaci = 0;

    for (int i = 0; i < boyut; i++) {
        std::cout << sayi.getir(i);
        noktaSayaci++;
        if (noktaSayaci == 3 && i < boyut - 1) {
            std::cout << '.';
            noktaSayaci = 0;
        }
    }
}