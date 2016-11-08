#ifndef DUGUM_H
#define DUGUM_H

#include <cstddef>

class Dugum {
private:
    char *_rakam;
    Dugum *_sonraki;
public:
    Dugum();

    /**
     * @param rakam Tutulacak olan rakam karakteri.
     * @return Bu düğümden sonra gelen düğümün adresi.
     */
    Dugum(char rakam, Dugum * = NULL);

    /**
     * Uygulanan karakteri kendi rakam değeri olarak kopyalar.
     * @param rakam Atanacak olan karakter değeri.
     * @return Tutulan rakam karakteri değiştirildikten sonra kendini döndürür.
     */
    Dugum &operator=(char rakam);

    /**
     * Stream extraction operator (akış çıkarma operatörü) mevcut düğümün sonraki
     * göstericisine belirtilen düğümü atamak için aşırı yüklenmiştir.
     * @param dugum Sonraki göstericisine atanacak olan düğümün adresi.
     * @return Mevcut düğümün adresini döndürür.
     */
    Dugum *operator>>(Dugum *dugum);

    /**
     * Gönderilen karakterin sayısal değerinin bir rakam olup olmadığını denetler.
     * @return Rakam ise true, değil ise false döndürür.
     */
    bool rakamiDenetle(char &) const;

    char rakam() const;

    Dugum *sonraki() const;

    ~Dugum();
};

#endif