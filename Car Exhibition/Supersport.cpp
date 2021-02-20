#include "Supersport.h"
#include <string.h>

Supersport::Supersport():Masina()
{
    this->CP=0;
}

Supersport::Supersport(int p, char m[], int cp):Masina(p,m)
{
    this->CP=cp;
}

Supersport::~Supersport()
{
    this->CP=0;
}

Supersport& Supersport::operator=(Supersport &object)
{
    this->CP=object.CP;
    this->pret=object.pret;
    strcpy(this->marca,object.marca);
    return *this;
}

istream& operator>>(istream& in, Supersport& object)
{
    in>>static_cast<Masina&>(object);
    cout<<"Introduceti numarul de cai putere:";
    in>>object.CP;
    cout<<"Introduceti '0' daca masina a fost vantuta, '1' daca e inca pe stoc: ";
    in>>object.vanduta;
    cin.get();
    return in;
}

ostream& operator<<(ostream& out, Supersport& object)
{
    out<<static_cast<Masina&>(object);
    cout<<"Numarul de cai putere este:";
    out<<object.CP;
    return out;
}

bool operator==(const Supersport &object1, const Supersport &object2)
{

    if(strcmp(object1.marca,object2.marca)==0 && object1.pret==object2.pret && object1.CP==object2.CP)
        return true;
    return false;
}

int Supersport::Get_vanduta() const
{
    return vanduta;
}
