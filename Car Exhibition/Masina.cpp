#include "Masina.h"
#include <string.h>

Masina::Masina()
{
    this->pret=0;
    this->marca[0]='\0';
}

Masina::Masina(int p, char m[])
{
    this->pret=p;
    strcpy(this->marca,m);
}

Masina::~Masina()
{
    this->pret=0;
    delete[]this->marca;
    this->marca[0]='\0';
}

Masina& Masina::operator=(Masina &object)
{
    this->pret=object.pret;
    strcpy(this->marca,object.marca);
    return *this;
}

void Masina::citire(istream &in)
{
    cout<<"Introduceti marca masinii:";
    in.getline(marca,50);
    cout<<"Introduceti pretul masinii:";
    in>>pret;
    cin.get();
}

void Masina::afisare(ostream &out)
{
    cout<<"Pretul masinii este: ";
    out<<pret;
    cout<<"\nMarca masinii este: ";
    out<<marca;
    cout<<"\n";
}

istream& operator>>(istream& in, Masina& object)
{
    object.citire(in);
    return in;
}

ostream& operator<<(ostream& out, Masina& object)
{
    object.afisare(out);
    return out;
}

char* Masina::Get_marca()
{
    return marca;
}

int Masina::Get_pret() const
{
    return pret;
}

