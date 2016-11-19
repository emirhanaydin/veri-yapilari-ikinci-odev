#ifndef BAGILLISTE_H
#define BAGILLISTE_H

#include <ostream>
#include "gezici.h"

class BagilListe {
private:
    int _boyut;
    Dugum *_ilk; // Mevcut düğümü belirtir.
    Dugum *_son; // Son düğümü belirtir.
    Gezici *_gezici;

    Dugum *konumdaki(int) const;

public:
    BagilListe();

    /**
     * Listenin tüm düğümlerinin rakam karakterlerini ard arda yazdırır.
     * @return Çıktıyı barındıran çıkış akışını döndürür.
     */
    friend std::ostream &operator<<(std::ostream &, const BagilListe &);

    /**
     * Listelerin adreslerini karşılaştırır.
     * @return Adresleri aynı ise true, değilse false döndürür.
     */
    friend bool operator==(const BagilListe &, const BagilListe &);

    char getir(int) const;

    /**
     * Belirtilen indekse verilen rakam karakterini içeren düğümü ekler.
     * @param rakam Eklenecek olan rakam karakteri.
     * @param indeks [OPSİYONEL] Eğer belirtilmemişse liste sonuna eklenir.
     */
    void ekle(char rakam, int indeks = -1);

    /**
     * Belirtilen indeksteki düğümü siler.
     * @param indeks [OPSİYONEL] Eğer belirtilmemişse son karakter silinir.
     */
    void sil(int indeks = -1);

    int boyut() const;

    void temizle();

    ~BagilListe();
};

#endif