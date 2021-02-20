#ifndef SUPERSPORT_H
#define SUPERSPORT_H

#include "Masina.h"
class Supersport:public Masina
{
    int CP;///numar cai putere
    int vanduta;
public:
    Supersport();
    Supersport(int,char*,int);
    ~Supersport();
    Supersport& operator=(Supersport &);
    friend istream& operator>> (istream& in, Supersport &);
    friend ostream& operator<< (ostream& out, Supersport &);
    friend bool operator==(const Supersport &,const Supersport &);
    int Get_vanduta() const;

};


#endif // SUPERSPORT_H
