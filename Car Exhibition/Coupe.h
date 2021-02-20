#ifndef COUPE_H
#define COUPE_H
#include <iostream>
#include "Masina.h"
#include "Coupe.h"
using namespace std;

class Coupe:public Masina
{
protected:
    int nr_usi;///2 sau 4 usi
public:
    Coupe();///Constructor
    Coupe(int,char*,int);///Constructor parametrizat
    virtual ~Coupe();
    Coupe& operator=(Coupe &);
    friend istream& operator>> (istream& in, Coupe &);
    friend ostream& operator<< (ostream& out, Coupe &);

};

#endif // COUPE_H
