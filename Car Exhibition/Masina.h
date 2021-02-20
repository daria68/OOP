#ifndef MASINA_H
#define MASINA_H
#include <iostream>
using namespace std;
class Masina
{
protected:
    int pret;
    char marca[50];
public:
    Masina();///Constructor
    Masina(int,char*);///Constructor parametrizat
    virtual ~Masina();
    Masina& operator=(Masina &);
    void citire(istream &in);
    virtual void afisare(ostream &out);
    friend istream& operator>> (istream& in, Masina &);
    friend ostream& operator<< (ostream& out, Masina &);
    int Get_pret() const;
    char *Get_marca();
};
#endif // MASINA_H
