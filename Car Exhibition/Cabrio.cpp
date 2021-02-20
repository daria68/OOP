#include "Cabrio.h"
#include <string.h>
Cabrio::Cabrio():Masina()
{
    this->material_acoperis[0]='\0';
}

Cabrio::Cabrio(int p, char m[], char m_a[]):Masina(p,m)
{
    strcpy(this->material_acoperis,m_a);
}

Cabrio::~Cabrio()
{
    delete[]this->material_acoperis;
    this->material_acoperis[0]='\0';
}

Cabrio& Cabrio::operator=(Cabrio &object)
{
    strcpy(this->material_acoperis,object.material_acoperis);
    this->pret=object.pret;
    strcpy(this->marca,object.marca);

    return *this;
}

istream& operator>>(istream& in, Cabrio& object)
{
    in>>static_cast<Masina&>(object);
    cout<<"Introduceti materialul acoperisului:";
    in.getline(object.material_acoperis,50);
    return in;
}

ostream& operator<<(ostream& out, Cabrio& object)
{
    out<<static_cast<Masina&>(object);
    cout<<"Materialul acoperisului este:";
    out<<object.material_acoperis;
    return out;
}

