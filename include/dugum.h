#ifndef DUGUM_H
#define DUGUM_H

#include <cstddef>
#include <ostream>
#include "sayi.h"

class Dugum {
private:
    Sayi *_sayi;
    Dugum *_sonraki;
public:
    Dugum();

    Dugum(Sayi *sayi, Dugum *sonraki = NULL);

    friend std::ostream &operator<<(std::ostream &, const Dugum &);

    Sayi *sayi() const;

    Dugum *sonraki() const;

    ~Dugum();
};

#endif