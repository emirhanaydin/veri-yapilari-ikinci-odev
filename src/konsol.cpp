/**
* @file konsol.cpp
* @description Açıklama ilgili başlık dosyasında yapılmıştır.
* @course 2A
* @assignment 2
* @date 7.10.2016
* @author Emirhan Aydın (g141210018@sakarya.edu.tr)
*/

#include <iostream>
#include <windows.h>
#include "konsol.h"

HANDLE Konsol::konsol = GetStdHandle(STD_OUTPUT_HANDLE);

short Konsol::alKonsolGenisligi() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if (!GetConsoleScreenBufferInfo(konsol, &csbi)) {
        return -1;
    } else {
//        Konsol penceresinin sol ve sağ karakterleri arasındaki fark, karakter sayısı olarak genişliği verir.
        return csbi.srWindow.Right - csbi.srWindow.Left;
    }
}

void Konsol::imleciGoster(bool gorunur) {
    CONSOLE_CURSOR_INFO cci;
    cci.bVisible = gorunur;
//    Varsayılan imleç boyutu değeri, 10.
    cci.dwSize = 10;
    SetConsoleCursorInfo(konsol, &cci);
}

bool Konsol::imlecGorunurMu() {
    CONSOLE_CURSOR_INFO cci;
    GetConsoleCursorInfo(konsol, &cci);

    return (const bool) cci.bVisible;
}

void Konsol::imleciTasi(short x, short y) {
    short konumX = x < 0 ? Konsol::alImlecX() : x;
    short konumY = y < 0 ? Konsol::alImlecY() : y;

    COORD coord;
    coord.X = konumX;
    coord.Y = konumY;
    SetConsoleCursorPosition(konsol, coord);
}

short Konsol::alImlecX() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (!GetConsoleScreenBufferInfo(konsol, &csbi))
        return -1;

    return csbi.dwCursorPosition.X;
}

short Konsol::alImlecY() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (!GetConsoleScreenBufferInfo(konsol, &csbi))
        return -1;

    return csbi.dwCursorPosition.Y;
}

bool Konsol::alYaziRengi(short &renk) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (!GetConsoleScreenBufferInfo(konsol, &csbi))
        return false;

    renk = csbi.wAttributes;
    return true;
}

void Konsol::yaziRengi(int renk) {
    SetConsoleTextAttribute(konsol, (WORD) renk);
}

void Konsol::renkliYazdir(const char *yazi, int renk) {
    short mevcutRenk;
    Konsol::alYaziRengi(mevcutRenk);
    bool renkFarkliMi = mevcutRenk != renk;

    if (renkFarkliMi)
        Konsol::yaziRengi(renk);

    std::cout << yazi;

    if (renkFarkliMi)
        Konsol::yaziRengi(mevcutRenk);
}

void Konsol::satiriDoldur(char karakter, short x, short y, bool geriyeDon, short uzunluk) {
    short konumX = x < 0 ? Konsol::alImlecX() : x; // Yatay konum değeri verilmemişse şu anki konum kabul edilir.
    short konumY = y < 0 ? Konsol::alImlecY() : y; // Dikey konum değeri verilmemişse şu anki konum kabul edilir.

    if (x >= 0 || y >= 0) // Eğer x veya y değeri parametre olarak verilmişse imleç taşınır.
        Konsol::imleciTasi(konumX, konumY); // İmleç alınan konuma taşınır.

    int karAdedi = Konsol::alKonsolGenisligi() - konumX; // Kaç adet karakter basılacağı hesaplanır.
//    Eğer geçerli bir uzunluk değeri verilmişse basılacak olan karakter adedi olarak alınır.
    if (uzunluk >= 0 && uzunluk < karAdedi)
        karAdedi = uzunluk;
    for (int i = 0; i < karAdedi; i++)
        std::cout << karakter;
    if (geriyeDon) {
        Konsol::imleciTasi(konumX, konumY);
    }
}

void Konsol::sil() {
    std::cout << (char) 8; // BACKSPACE karakteri basılarak bir birim sola gidilir.
    std::cout << ' '; // Boşluk karakteri basılarak önceki değerin üzerine yazılır.
    std::cout << (char) 8; // Tekrar BACKSPACE karakteri basılarak bir birim geri gidilir.
}