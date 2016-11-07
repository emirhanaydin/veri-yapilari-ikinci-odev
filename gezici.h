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