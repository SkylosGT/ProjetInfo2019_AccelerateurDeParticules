#include "Vecteur3D.h"

class Element
{
private:
    Vecteur3D vec_re;
    Vecteur3D vec_rs;
    double scal_Re;
    Element& elem_suivant;
public:
    Element(/* args */);
    ~Element();
};

