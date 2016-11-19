/**
* @file islem.h
* @description Sayı sınıfı üzerinden yapılacak işlemleri gerçekleştirir. Bir listenin istenilen formatta bir sayı olarak
 * dışarıdan alınması ve aynı şekilde üzerinde toplama işlemi yapılması burada gerçekleştirilir.
* @course 2A
* @assignment 2
* @date 3.11.2016
* @author Emirhan Aydın (g141210018@sakarya.edu.tr)
*/

#ifndef ISLEM_H
#define ISLEM_H

#include <iostream>
#include "sayi.h"

class Islem {
public:
    static void sayiGir(Sayi &sayi);

    /**
     * İki Sayi'yi tüm rakamlarını tek tek karşılaştırarak toplama işlemine tabi tutar.
     * @return İki sayının toplamını tutan yeni bir Sayi nesnesi döndürür.
     */
    static Sayi topla(const Sayi &, const Sayi &);

    /**
     * Sayi'yi her rakamının arasına kısa çizgi koyarak yazdırır.
     */
    static void ayrikYazdir(Sayi &);

    /**
     * Sayi'yi, sağdan sola doğru her üç rakamda bir nokta olacak şekilde yazdırır.
     */
    static void noktaliYazdir(Sayi &);
};

#endif