#ifndef SAYI_H
#define SAYI_H

#include <ostream>

class Sayi {
private:
    int _rakam;
public:
    Sayi(int = 0);

    int rakam() const;

    friend std::ostream &operator<<(std::ostream &, const Sayi &);

    Sayi &operator=(int);
};

#endif