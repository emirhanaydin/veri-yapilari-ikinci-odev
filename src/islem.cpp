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
            sayi.ekle(c);
        } else if (c == (char) 8 && boyut > 0) { // BACKSPACE basılmışsa ve boyut 0'dan fazlaysa karakter silinir.
            Konsol::sil(); // Karakter listeden silinmeden önce konsol ekranından silinir.
            sayi.rakamSil();
        }
    }

    std::cout << std::endl;
}

Sayi Islem::topla(const Sayi &sayi, const Sayi &sayi1) {
//    Her iki listenin de boyutları karşılaştırılır ve küçük boyutlu olan göstericiye atanır.
    const Sayi *kucuk = sayi.boyut() > sayi1.boyut() ? &sayi1 : &sayi;
//    İlk liste küçük boyutlu olanla karşılaştırılır ve buna göre büyük olan belirlenir.
    const Sayi *buyuk = sayi == *kucuk ? &sayi1 : &sayi;
    Sayi sonuc; // Listelerin toplamını tutmak için yeni bir liste oluşturulur.
    int kucukBoyut = kucuk->boyut(), buyukBoyut = buyuk->boyut();
    int rakam, rakam1, toplam = 0;
    bool elde = false;

    for (int i = kucukBoyut - 1, j = buyukBoyut - 1; i >= 0; i--, j--) {
        rakam = kucuk->getir(i) - '0'; // Küçük boyutlu Sayı'nın şu anki karakterinin rakamsal değeri
        rakam1 = buyuk->getir(j) - '0'; // Büyük boyutlu Sayı'nın şu anki karakterinin rakamsal değeri
        toplam = rakam + rakam1;
        if (elde) toplam++; // Daha önceki toplamdan elde değeri varsa toplam bir artırılır.
        elde = toplam >= 10;

//        Yeni toplamdan elde değeri elde edilmişse toplamın 10 eksiği, yoksa kendisi sonuca eklenir.
        sonuc.ekle((char) (elde ? toplam - 10 : toplam) + '0', 0);
    }

    if (kucukBoyut == buyukBoyut && elde) { // Eğer iki Sayi'nın boyutları eşitse ve elde değeri varsa başa 1 eklenir.
        sonuc.ekle('1', 0);
    } else { // Eğer bir Sayi diğerinden daha büyük boyutlu ise rakamları sonuca dahil edilir.
        for (int i = buyukBoyut - kucukBoyut - 1; i >= 0; i--) {
            toplam = buyuk->getir(i) - '0'; // Büyük boyutlu Sayi'nın şu anki karakterinin rakamsal değeri
            if (elde) toplam++; // Daha önceki toplamdan elde değeri varsa toplam bir artırılır.
            elde = toplam == 10; // Elde değeri 1 veya 0 olacağından değer 10'a eşitse tekrar elde vardır.

//            Yeni toplamdan elde değeri elde edilmişse 0, yoksa kendisi sonuca eklenir.
            sonuc.ekle((elde ? '0' : (char) toplam + '0'), 0);
        }

//        Tüm rakamlar eklendikten sonra elde değeri elde edilmişse başa 1 eklenir.
        if (elde) sonuc.ekle('1', 0);
    }

    return sonuc;
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