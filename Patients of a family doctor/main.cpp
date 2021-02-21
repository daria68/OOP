#include <iostream>
#include <utility>
#include <vector>
#include <typeinfo>
#include <stdlib.h>
using namespace std;

///clasa abstracta
class Pacient
{
protected:
    string nume;
    string prenume;
    int varsta;
    string adresa;
    pair<int,string> colesterol;
    pair<int,string> TA;
public:
    Pacient() {};
    virtual ~Pacient() {};
    virtual void citire(istream& in)=0;
    virtual void afisare(ostream& out)=0;
    friend istream& operator>>(istream& in, Pacient&);
    friend ostream& operator<<(ostream& out, Pacient&);
    string get_nume() const;
    int risc();
};


void Pacient::citire(istream& in)
{
    cout<<"Nume: ";
    getline(in,nume);
    cout<<"Prenume: ";
    getline(in,prenume);
    cout<<"Varsta: ";
    in>>varsta;
    cout<<"Adresa: ";
    cin.get();
    getline(in,adresa);
    cout<<"Colesterol: ";
    in>>colesterol.first;
    cin.get();
    cout<<"Valoare inregistrata la data de: ";
    getline(in,colesterol.second);
    cout<<"TA: ";
    in>>TA.first;
    cin.get();
    cout<<"Valoare inregistrata la data de: ";
    getline(in,TA.second);
}

void Pacient::afisare(ostream& out)
{
    out<<nume;
    cout<<" ";
    out<<prenume;
    cout<<": ";
    cout<<"Colesterol(";
    out<<colesterol.second;
    cout<<"): ";
    out<<colesterol.first;
    cout<<" mg/dl; ";
    cout<<"TA(";
    out<<TA.second;
    cout<<"): ";
    out<<TA.first;
    cout<<" mg/dl; ";
}

istream& operator>>(istream& in, Pacient& object)
{
    object.citire(in);
    return in;
}

ostream& operator<<(ostream& out, Pacient& object)
{
    object.afisare(out);
    return out;
}

string Pacient::get_nume() const
{
    return nume;
}

int Pacient::risc()
{
    int nr=0;
    if(colesterol.first>240)
        nr++;
    if(TA.first<130 || TA.first>139)
        nr++;
    return nr;
}
class Adult_sub_40:public Pacient
{
public:
    Adult_sub_40();
    ~Adult_sub_40() {};
    void citire(istream& in);
    void afisare(ostream& out);
    friend istream& operator>>(istream& in, Adult_sub_40&);
    friend ostream& operator<<(ostream& out, Adult_sub_40&);
};
Adult_sub_40::Adult_sub_40():Pacient() {}
void Adult_sub_40::citire(istream& in)
{
    Pacient::citire(in);
}

void Adult_sub_40::afisare(ostream& out)
{
    Pacient::afisare(out);
    int nr=0;
    if(colesterol.first>240)
        nr++;
    if(TA.first<130 || TA.first>139)
        nr++;
    cout<<"Risc cardiovascular: ";
    if(nr==1)
        cout<<"DA";
    else if(nr>=2)
        cout<<"RIDICAT";
    else
        cout<<"nu";
    cout<<"\n\n";
}

istream& operator>>(istream& in, Adult_sub_40& object)
{
    object.citire(in);
    return in;
}

ostream& operator<<(ostream& out, Adult_sub_40& object)
{
    object.afisare(out);
    return out;
}

class Adult_peste_40:public Pacient
{
    string fumator;
    string sedentarism;
public:
    Adult_peste_40();
    ~Adult_peste_40() {};
    void citire(istream& in);
    void afisare(ostream& out);
    friend istream& operator>>(istream& in, Adult_peste_40&);
    friend ostream& operator<<(ostream& out, Adult_peste_40&);
    int risc();
};
Adult_peste_40::Adult_peste_40():Pacient() {}
void Adult_peste_40::citire(istream& in)
{
    Pacient::citire(in);
    cout<<"Fumator: ";
    getline(in,fumator);
    cout<<"Sedentarism: ";
    getline(in,sedentarism);
}

void Adult_peste_40::afisare(ostream& out)
{
    Pacient::afisare(out);
    int nr=0;
    if(colesterol.first>240)
        nr++;
    if(TA.first<130 || TA.first>139)
        nr++;
    if(fumator=="da")
        nr++;
    if(sedentarism=="ridicat" || sedentarism=="mediu")
        nr++;
    cout<<"Risc cardiovascular: ";
    if(nr==1)
        cout<<"DA";
    else if(nr>=2)
        cout<<"RIDICAT";
    else
        cout<<"nu";
    cout<<"\n\n";
}

istream& operator>>(istream& in, Adult_peste_40& object)
{
    object.citire(in);
    return in;
}

ostream& operator<<(ostream& out, Adult_peste_40& object)
{
    object.afisare(out);
    return out;
}

int Adult_peste_40::risc()
{
    int nr=0;
    if(colesterol.first>240)
        nr++;
    if(TA.first<130 || TA.first>139)
        nr++;
    if(fumator=="da")
        nr++;
    if(sedentarism=="ridicat" || sedentarism=="mediu")
        nr++;
    return nr;
}
class Copil:public Pacient
{
    string nume_prenume_mama;
    string nume_prenume_tata;
    string antecedente;///da,nu
    pair<double,string> proteinaC;
public:
    Copil();
    ~Copil() {};
    void citire(istream& in);
    void afisare(ostream& out);
    friend istream& operator>>(istream& in, Copil&);
    friend ostream& operator<<(ostream& out, Copil&);
    int risc();
};

Copil::Copil():Pacient() {}
void Copil::citire(istream& in)
{
    Pacient::citire(in);
    cout<<"Proteina C reactiva: ";
    in>>proteinaC.first;
    cin.get();
    cout<<"Valoare inregistrata la data de: ";
    getline(in,proteinaC.second);
    cout<<"Antecedente familie: ";
    in>>antecedente;
}

void Copil::afisare(ostream& out)
{
    Pacient::afisare(out);
    cout<<" Proteina C reactiva(";
    out<<proteinaC.second;
    cout<<"): ";
    out<<proteinaC.first;
    cout<<" mg/dl; ";
    cout<<"Antecedente familie: ";
    out<<antecedente;
    cout<<"; ";
    int nr=0;
    if(colesterol.first>240)
        nr++;
    if(TA.first<130 || TA.first>139)
        nr++;
    if(proteinaC.first<60)
        nr++;
    if(antecedente=="da")
        nr++;
    cout<<"Risc cardiovascular: ";
    if(nr==1)
        cout<<"DA";
    else if(nr>=2)
        cout<<"RIDICAT";
    else
        cout<<"nu";
    cout<<"\n\n";
}

istream& operator>>(istream& in, Copil& object)
{
    object.citire(in);
    return in;
}

ostream& operator<<(ostream& out, Copil& object)
{
    object.afisare(out);
    return out;
}
int Copil::risc()
{
    int nr=0;
    if(colesterol.first>240)
        nr++;
    if(TA.first<130 || TA.first>139)
        nr++;
    if(proteinaC.first<60)
        nr++;
    if(antecedente=="da")
        nr++;
    return nr;
}

///clasa template
template <class Tip>
class Medic_familie
{
    vector<Tip*> t;
public:
    Medic_familie();
    ~Medic_familie();
    Medic_familie<Tip>& operator=(Medic_familie<Tip> &);
    void operator+=(const Tip &);
    void print();
    void print_nume(string);
    void print_risc();
};
template <class Tip> Medic_familie<Tip>::Medic_familie() {}
template <class Tip> Medic_familie<Tip>::~Medic_familie()
{
    this->t.clear();
}

template <class Tip>
Medic_familie<Tip>& Medic_familie<Tip>::operator=(Medic_familie<Tip> &object)
{
    this->t=object.t;
    return *this;
}

template <class Tip>
void Medic_familie<Tip>::operator +=(const Tip&object)
{
    Tip *aux=new Tip(object);
    t.push_back(aux);
}

template <class Tip>
void Medic_familie<Tip>::print()
{
    if(typeid(Tip)==typeid(Adult_sub_40))
        cout<<"Adulti sub 40 ani:\n";
    else if(typeid(Tip)==typeid(Adult_peste_40))
        cout<<"Adulti peste 40 ani:\n";
    else if(typeid(Tip)==typeid(Copil))
        cout<<"Copii:\n";
    for(unsigned int i=0; i<t.size(); i++)
    {
        cout<<*(t[i])<<"\n";
        cout<<"---------------------------------------------------------------\n";
    }
}

template <class Tip>
void Medic_familie<Tip>::print_nume(string nume)
{
    for(unsigned int i=0; i<t.size(); i++)
        if(t[i]->get_nume()==nume)
        {
            cout<<*(t[i])<<"\n";
            cout<<"---------------------------------------------------------------\n";
        }
}

template <class Tip>
void Medic_familie<Tip>::print_risc()
{
    for(unsigned int i=0; i<t.size(); i++)
        if(typeid(Tip)!=typeid(Copil) && t[i]->risc()>=2)
        {
            cout<<*(t[i])<<"\n";
            cout<<"---------------------------------------------------------------\n";
        }
         else if(typeid(Tip)==typeid(Copil) && t[i]->risc()>=1)
        {
           cout<<*(t[i])<<"\n";
           cout<<"---------------------------------------------------------------\n";
        }
}


void meniu()
{
    Medic_familie<Adult_sub_40> tip_1;
    Medic_familie<Adult_peste_40> tip_2;
    Medic_familie<Copil> tip_3;
    int opt=0;
    int n=0;
    Pacient **p;
    while(opt!=-1)
    {
        cout<<"\n1.Citirea a n pacienti.\n";
        cout<<"2.Afisare informatii pt toti pacientii.\n";
        cout<<"3.Afisarea informatiilor pt toti pacientii adulti cu factor de risc ridicat.\n";
        cout<<"4.Afisarea informatiilor pt toto copii cu factor de risc cardiovascular.\n";
        cout<<"5.Afisarea informatiilor pt toti pacientii cu nume de familie egal cu un nume dat.\n";
        cout<<"Dupa modelul anterior, introduceti optiunea dorita: ";
        cin>>opt;
        if(opt==1)
        {
            cout<<"Introduceti numarul de de pacienti: ";
            cin>>n;
            p=new Pacient*[n];
            string tip;
            for(int i=0; i<n; i++)
            {
                cout<<"\nIntroduceti tipul Pacientului(sub_40,peste_40,copil): ";
                cin>>tip;
                cin.get();
                try
                {
                    if(tip=="sub_40")
                    {
                        p[i]=new Adult_sub_40;
                        cin>>*(dynamic_cast<Adult_sub_40*>(p[i]));
                        tip_1+=*(dynamic_cast<Adult_sub_40*>(p[i]));
                        cout<<"---------------------------------------------------------------\n";
                    }
                    else if(tip=="peste_40")
                    {
                        p[i]=new Adult_peste_40;
                        cin>>*(dynamic_cast< Adult_peste_40*>(p[i]));
                        tip_2+=*(dynamic_cast< Adult_peste_40*>(p[i]));
                        cout<<"---------------------------------------------------------------\n";
                    }
                    else if(tip=="copil")
                    {
                        p[i]=new Copil;
                        cin>>*(dynamic_cast<Copil*>(p[i]));
                        tip_3+=*(dynamic_cast<Copil*>(p[i]));
                        cout<<"---------------------------------------------------------------\n";

                    }
                    else
                        throw tip;
                }
                catch(string ceva)
                {
                    cout<<"Tipul "<< ceva<< " nu exista!!!\n";
                    exit(EXIT_FAILURE);
                }
            }
        }
        else if(opt==2)
        {
            tip_1.print();
            tip_2.print();
            tip_3.print();
        }
        else if(opt==3)
        {
            tip_1.print_risc();
            tip_2.print_risc();
        }
        else if(opt==4)
        {
            tip_3.print_risc();
        }
        else if(opt==5)
        {
            string nume;
            cin.get();
            getline(cin,nume);
            tip_1.print_nume(nume);
            tip_2.print_nume(nume);
            tip_3.print_nume(nume);
        }
        else
        {
            cout<<"Ati iesit din meniu!";
            return ;
        }
    }
}
int main()
{
    meniu();
    return 0;
}
