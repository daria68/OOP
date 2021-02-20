#ifndef CABRIO_H
#define CABRIO_H

#include "Masina.h"
class Cabrio:public Masina
{
    char material_acoperis[50];///metalic sau material textil
public:
    Cabrio();
    Cabrio(int, char*, char*);
    ~Cabrio();
    Cabrio& operator=(Cabrio &);
    friend istream& operator>> (istream& in, Cabrio &);
    friend ostream& operator<< (ostream& out, Cabrio &);
};

#endif // CABRIO_H
