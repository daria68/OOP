#ifndef EXPOZITIE_H
#define EXPOZITIE_H

#include "Masina.h"
#include "Cabrio.h"
#include "Coupe.h"
#include "Hot_Hatch.h"
#include "Supersport.h"

#include <iostream>
#include <vector>
#include <typeinfo>

template <class TipMasina>
class Expozitie
{
    static int nr_tot; ///nr total de masini expuse, incrementat automat
    vector <TipMasina*> v; ///vector de obiecte de tipul unei masini
public:
    Expozitie(); ///Constructor
    ~Expozitie(); ///Destructor
    Expozitie<TipMasina>& operator=(Expozitie<TipMasina> &);
    void operator+=(const TipMasina &);///Overload +=
    void print();
};
template <class TipMasina> int Expozitie<TipMasina>::nr_tot=0;

template <class TipMasina>
Expozitie<TipMasina>::Expozitie(){}

template <class TipMasina>
Expozitie<TipMasina>::~Expozitie()
{
    this->v.clear();
    nr_tot=0;
}

template <class TipMasina>
Expozitie<TipMasina>& Expozitie<TipMasina>::operator=(Expozitie<TipMasina> &object)
{
    this->nr_tot=object.nr_tot;
    this->v=object.v;
    return *this;
}

template <class TipMasina>
void Expozitie<TipMasina>::operator +=(const TipMasina &object)
{
    TipMasina *aux=new TipMasina(object);
    v.push_back(aux);
    nr_tot++;
}

template <class TipMasina>
void Expozitie<TipMasina>::print()
{
    if(typeid(TipMasina)==typeid(Coupe))
        cout<<"Masini Coupe:\n";
    else if(typeid(TipMasina)==typeid(Hot_Hatch))
        cout<<"Masini Hot-Hatch:\n";
    else if(typeid(TipMasina)==typeid(Cabrio))
        cout<<"Masini Cabrio:\n";
    for(unsigned int i=0; i<v.size();i++)
        cout<<*(v[i])<<"\n\n";
    cout<<"--------------------------------------------------------------------------------------\n";
}

///SPECIALIZARE
template<>
class Expozitie<Supersport>
{
    static int nr_expuse;
    static int nr_vandute;
    vector <Supersport*> vandute;
    vector <Supersport*> in_stoc;
public:
    Expozitie() {}
    ~Expozitie()
    {
        this->vandute.clear();
        this->in_stoc.clear();
        nr_expuse=0;
        nr_vandute=0;
    }

    Expozitie<Supersport>& operator=(Expozitie<Supersport> &object) ///Overload =
    {
        this->nr_expuse=object.nr_expuse;
        this->nr_vandute=object.nr_vandute;
        this->vandute=object.vandute;
        this->in_stoc=object.in_stoc;
        return *this;
    }

    void operator+=(const Supersport &object)///Overload +=
    {
        Supersport *aux=new Supersport(object);
        in_stoc.push_back(aux);
        nr_expuse++;

    }
    void operator-=(const Supersport &object) ///Operator-=
    {

        Supersport *aux=new Supersport(object);
        vandute.push_back(aux);
        nr_vandute++;
        int poz;
        for(unsigned int i=0;i<in_stoc.size();i++)
            if(*in_stoc[i]==*aux)
                poz=i;
         in_stoc.erase (in_stoc.begin()+poz);
         nr_expuse--;

    }

    void print()
    {
        cout<<"Masini Supersport:\n";
        cout<<"Mai sunt inca "<<nr_expuse<<" pe stoc:\n";
        for(unsigned int i=0; i<in_stoc.size();i++)
            cout<<*(in_stoc[i])<<"\n\n";
        cout<<"\n";
        cout<<"S-au vandut: "<<nr_vandute<<"\n";
        for(unsigned int i=0; i<vandute.size();i++)
            cout<<*(vandute[i])<<"\n\n";
        cout<<"\n";
        cout<<"--------------------------------------------------------------------------------------\n";
    }

};
int Expozitie<Supersport>::nr_expuse=0;
int Expozitie<Supersport>::nr_vandute=0;

#endif // EXPOZITIE_H
