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

int Konsol::alKonsolGenisligi() {
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

void Konsol::imleciTasi(int x, int y) {
    int konumX = x < 0 ? Konsol::alImlecX() : x;
    int konumY = y < 0 ? Konsol::alImlecY() : y;

    COORD coord;
    coord.X = (short) konumX;
    coord.Y = (short) konumY;
    SetConsoleCursorPosition(konsol, coord);
}

int Konsol::alImlecX() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (!GetConsoleScreenBufferInfo(konsol, &csbi))
        return -1;
    return csbi.dwCursorPosition.X;
}

int Konsol::alImlecY() {
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
    Konsol::yaziRengi(renk);
    std::cout << yazi;
    Konsol::yaziRengi(mevcutRenk);
}

void Konsol::satiriDoldur(char karakter, int x, int y, bool geriyeDon, int uzunluk) {
    int konumX = x < 0 ? Konsol::alImlecX() : x;
    int konumY = y < 0 ? Konsol::alImlecY() : y;

    Konsol::imleciTasi(konumX, konumY);

    int karAdedi = Konsol::alKonsolGenisligi() - konumX;
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