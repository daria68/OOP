#include "Hot_Hatch.h"
#include <string.h>

Hot_Hatch::Hot_Hatch():Coupe()
{
    this->cost_anual_combustibil=0;
}

Hot_Hatch::Hot_Hatch(int p, char m[], int n_u, int c_a_c):Coupe(p,m,n_u)
{
    this->cost_anual_combustibil=c_a_c;
}

Hot_Hatch::~Hot_Hatch()
{
    this->cost_anual_combustibil=0;
}

Hot_Hatch& Hot_Hatch::operator=(Hot_Hatch &object)
{
    this->nr_usi=object.nr_usi;
    this->pret=object.pret;
    this->cost_anual_combustibil=object.cost_anual_combustibil;
    strcpy(this->marca,object.marca);

    return *this;
}

istream& operator>>(istream& in, Hot_Hatch& object)
{
    in>>static_cast<Coupe&>(object);
    cout<<"Introduceti costul consumului anual de combustibil:";
    in>>object.cost_anual_combustibil;
    cin.get();
    return in;
}

ostream& operator<<(ostream& out, Hot_Hatch& object)
{
    out<<static_cast<Masina&>(object);
    cout<<"Consumul anual de combustibil este:";
    out<<object.cost_anual_combustibil;
    return out;
}

