#ifndef HOT_HATCH_H
#define HOT_HATCH_H
#include "Coupe.h"

class Hot_Hatch:public Coupe
{
    int cost_anual_combustibil;///fiindca aceasta masina nu are portbagaj, e asociata cu economia de combustibil
public:
    Hot_Hatch();///Constructor
    Hot_Hatch(int,char*,int,int);///Constructor parametrizat
    ~Hot_Hatch();
    Hot_Hatch& operator=(Hot_Hatch &);
    friend istream& operator>> (istream& in, Hot_Hatch &);
    friend ostream& operator<< (ostream& out, Hot_Hatch &);
};

#endif // HOT_HATCH_H
