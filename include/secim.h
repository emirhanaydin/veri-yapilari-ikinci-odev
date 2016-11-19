#ifndef SECIM_H
#define SECIM_H

#include <iostream>
#include <conio.h>
#include "konsol.h"

using namespace std;

class Secim {
private:
    static int yonTuslariSecimi(int secenek, int secenekSayisi, char geriye = 72, char ileriye = 80, char onay = 13);

public:
    /**
    * Dikeyde ok tuşları ile seçenekler arasında seçim yapılmasını sağlayan fonksiyon.
    * @param secenekler Seçenekleri barındıran metin dizisi.
    * @param secenekSayisi Toplam seçenek sayısı.
    * @param secenek Seçilmiş olan seçeneği döndürmek için kullanılan referans.
    */
    static void dikeySecim(std::string secenekler[], int secenekSayisi, int &secenek);

    /**
    * Ana menüde seçilmiş olan seçeneğin konumuna bağlı olarak kullanıcıya Evet - Hayır seçenekli onay menüsünü sunar.
    * @return Evet yanıtı alınırsa true, Hayır alınırsa false döndürülür.
    */
    static bool onayMenusu();
};

#endif //SECIM_H
