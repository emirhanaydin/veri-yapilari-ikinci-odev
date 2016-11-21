/**
* @file gezici.h
* @description İlişkili düğümler arasında ileriye doğru taramayı kolaylaştırmak için kullanılır.
* @course 2A
* @assignment 2
* @date 3.11.2016
* @author Emirhan Aydın (g141210018@sakarya.edu.tr)
*/

#ifndef GEZICI_H
#define GEZICI_H

#include "dugum.h"

class Gezici {
private:
    Dugum *_dugum;
public:
    Gezici(Dugum *);

    /**
     * Bir sonraki düğümü gösterir.
     * @return Gösterilen düğüm değiştirildikten sonra kendini döndürür.
     */
    Gezici *operator++(int);

    /**
     * Belirtilen düğümü gösterir.
     * @return Gösterilen düğüm değiştirildikten sonra kendini döndürür.
     */
    Gezici *operator>>(Dugum *);

    Dugum *dugum() const;
};

#endif