/**
* @file dugum.h
* @description Listede tutulan elemandır. Her bir düğüm bir veri ve sonraki düğümün adresini tutar. Bu zincirleme yapı
 * sayesinde baştan sona kadar düğümler kullanılarak tüm elemanlara erişmek mümkün olur.
* @course 2A
* @assignment 2
* @date 3.11.2016
* @author Emirhan Aydın (g141210018@sakarya.edu.tr)
*/

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
     * @param karakter Tutulacak olan rakam karakteri.
     * @return Bu düğümden sonra gelen düğümün adresi.
     */
    Dugum(char karakter, Dugum * = NULL);

    /**
     * Uygulanan karakteri kendi rakam değeri olarak kopyalar.
     * @param karakter Atanacak olan karakter değeri.
     * @return Tutulan rakam karakteri değiştirildikten sonra kendini döndürür.
     */
    Dugum &operator=(char karakter);

    /**
     * Stream extraction operator (akış çıkarma operatörü) mevcut düğümün sonraki
     * göstericisine belirtilen düğümü atamak için aşırı yüklenmiştir.
     * @param dugum Sonraki göstericisine atanacak olan düğümün adresi.
     * @return Mevcut düğümün adresini döndürür.
     */
    Dugum *operator>>(Dugum *dugum);

    char rakam() const;

    Dugum *sonraki() const;

    ~Dugum();
};

#endif