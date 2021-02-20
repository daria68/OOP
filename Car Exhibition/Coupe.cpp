#include "Coupe.h"
#include <string.h>
Coupe::Coupe():Masina()
{
    this->nr_usi=0;
}

Coupe::Coupe(int p, char m[], int n_u):Masina(p,m)
{
    this->nr_usi=n_u;
}

Coupe::~Coupe()
{
    this->nr_usi=0;
}

Coupe& Coupe::operator=(Coupe &object)
{
    this->nr_usi=object.nr_usi;
    this->pret=object.pret;
    strcpy(this->marca,object.marca);

    return *this;
}

istream& operator>>(istream& in, Coupe& object)
{
    in>>static_cast<Masina&>(object); ///referire la operatorul >> din clasa de baza
    cout<<"Introduceti numarul de usi(2 sau 4!):";
    in>>object.nr_usi;
    while(object.nr_usi!=2&&object.nr_usi!=4)
    {
        cout<<"Introduceti numarul de usi(2 sau 4!):";
        in>>object.nr_usi;
    }
    cin.get();
    return in;
}

ostream& operator<<(ostream& out, Coupe& object)
{
    out<<static_cast<Masina&>(object);
    cout<<"Numarul de usi este:";
    out<<object.nr_usi;
    return out;
}
