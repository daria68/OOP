#include <iostream>
#include <string.h>
#include "Expozitie.h"
#include "Coupe.h"
#include "Hot_Hatch.h"
#include "Cabrio.h"
#include "Supersport.h"
int main()
{

    Expozitie<Coupe> tip_1;
    Expozitie<Hot_Hatch> tip_2;
    Expozitie<Cabrio> tip_3;
    Expozitie<Supersport> tip_4;/// apel la constructorul clasei specializate pt tipul Supersport
    int n;
    cout<<"Introduceti numarul de masini:";
    cin>>n;
    int tip_masina;
    Masina **M=new Masina *[n];
    vector< pair <char*,int> > m; ///in acest vector vor fi doar masini supersport, deoarece doar in cazul lor se pune problema vanzarii
                                  ///iar pt fiecare masina supersport se va retine doar marca si pretul/-1
    pair<char*,int> pereche;
    try{
    for(int i=0; i<n; i++)
    {
        cout<<"TASTA 1 pt COUPE\n";
        cout<<"TASTA 2 pt HOT-HATCH\n";
        cout<<"TASTA 3 pt CABRIO\n";
        cout<<"TASTA 4 pt SUPERSPORT\n";
        cout<<"Introduceti tipul dorit, dupa modelul anterior:";
        cin>>tip_masina;
        if(tip_masina<=4)
        switch(tip_masina)
        {
        case 1:
        {
            M[i]=new Coupe;
            cin.get();///pentru a putea introduce marca
            cin>>*(dynamic_cast<Coupe*>(M[i]));
            tip_1+=*(dynamic_cast<Coupe*>(M[i]));
            cout<<"--------------------------------------------------------------------------------------\n";
            break;
        }

        case 2:
            {
            M[i]=new Hot_Hatch;
            cin.get();
            cin>>*(dynamic_cast<Hot_Hatch*>(M[i]));
            tip_2+=*(dynamic_cast<Hot_Hatch*>(M[i]));
            cout<<"--------------------------------------------------------------------------------------\n";
            break;
            }
        case 3:
            {
            M[i]=new Cabrio;
            cin.get();
            cin>>*(dynamic_cast<Cabrio*>(M[i]));
            tip_3+=*(dynamic_cast<Cabrio*>(M[i]));
            cout<<"--------------------------------------------------------------------------------------\n";
            break;
            }
        case 4:
            {
            M[i]=new Supersport;
            cin.get();
            cin>>*(dynamic_cast<Supersport*>(M[i]));
            tip_4+=*(dynamic_cast<Supersport*>(M[i]));
            pereche.first=M[i]->Get_marca();
            if((dynamic_cast<Supersport*>(M[i]))->Get_vanduta()==0)
                pereche.second=M[i]->Get_pret();
            else
                pereche.second=-1;
            m.push_back(pereche);
            cout<<"--------------------------------------------------------------------------------------\n";
            break;
            }
        }
             else
            throw tip_masina;
        }
    }
    catch(int x)
    {
        cout<<"Nu poate exista o masina de tip "<<x<<"!!!";
        exit(EXIT_FAILURE);
    }

    ///vom parcurge vectorul M de obiecte
    ///iar atunci cand intalnim un obiect de tip Supersport vom verifica daca a fost sau nu vandut
    ///daca este , vom apela -=
    ///nu am putut face acest lucru odata cu citirea deoarece avem nevoie ca
    ///vectorul de obiecte in_stoc sa aiba elemente ca sa le putem sterge cu -=

    for(int i=0;i<n;i++)
        if(strstr(typeid(*M[i]).name(),"Supersport"))
            if((dynamic_cast<Supersport*>(M[i]))->Get_vanduta()==0)
                tip_4-=*(dynamic_cast<Supersport*>(M[i]));

    tip_1.print();
    tip_2.print();
    tip_3.print();
    tip_4.print();
    cout<<"Pentru masinile Supersport:\n";
    for(unsigned int i=0;i<m.size();i++)
        cout<<m[i].first<<" "<<m[i].second<<endl;
    return 0;
}
