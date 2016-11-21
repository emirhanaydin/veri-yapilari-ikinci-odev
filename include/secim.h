/**
* @file secim.h
* @description Kullanıcıya görsel olarak geliştirilmiş bir seçim menüsü sunar ve buna bağlı metotları içerir.
* @course 2A
* @assignment 2
* @date 19.11.2016
* @author Emirhan Aydın (g141210018@sakarya.edu.tr)
*/

#ifndef SECIM_H
#define SECIM_H

#include <iostream>
#include <conio.h>
#include "konsol.h"

using namespace std;

class Secim {
private:
    /**
     * Kullanıcı tarafından girilen tuşun karakter değerine göre seçime uygulanacak olan indeks farkını belirler.
     * @param secenek Mevcut indeksi belirtir. Sınır denetimi yapmak için kullanılır.
     * @param secenekSayisi Maksimum seçenek indeksini belirtir.  Sınır denetimi yapmak için kullanılır.
     * @param geriye [OPSİYONEL] İndeksi bir birim azaltacak olan tuşun karakterini belirtir. Varsayılan olarak aşağı ok
     * tuşu kabul edilir.
     * @param ileriye [OPSİYONEL] İndeksi bir birim artıracak olan tuşun karakterini belirtir. Varsayılan olarak yukarı
     * ok tuşu kabul edilir.
     * @param onay [OPSİYONEL] Seçimi sonlandıracak olan tuşun, yani onay tuşununun karakterini belirtir. Varsayılan
     * olarak CR (Carriage Return) yani satır sonu karakterini kabul eder. Bu sayede ENTER tuşu yakalanmış olur.
     * @return Bir birim geriye için -1, ileriye için 1, onay için ise 2 değerini döndürürür.
     */
    static short yonTuslariSecimi(int secenek, int secenekSayisi, char geriye = 72, char ileriye = 80, char onay = 13);

public:
    /**
     * Dikeyde ok tuşları ile seçenekler arasında seçim yapılmasını sağlayan fonksiyon.
     * @param secenekler Seçenekleri barındıran metin dizisi.
     * @param secenekSayisi Toplam seçenek sayısı.
     * @param secenek Seçilmiş olan seçeneği döndürmek için kullanılan referans.
     */
    static void dikeySecim(std::string secenekler[], short secenekSayisi, int &secenek);

    /**
     * Ana menüde seçilmiş olan seçeneğin konumuna bağlı olarak kullanıcıya Evet - Hayır seçenekli onay menüsünü sunar.
     * @param imleciGizle [OPSİYONEL] Seçim yapıldığı esnada imlecin gösterilip gösterilmeyeceğini belirler.
     * @return Evet yanıtı alınırsa true, Hayır alınırsa false döndürülür.
     */
    static bool onayMenusu(bool imleciGizle = true);
};

#endif //SECIM_H
