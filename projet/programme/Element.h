#include "Vecteur3D.h"
#include "Particule.h"

class Element
{
protected:
    Vecteur3D vec_re;
    Vecteur3D vec_rs;
    double scal_Re;

private:
    Element* elem_suivant;

public:
    Element(Vecteur3D, Vecteur3D, double, Element* _suivant=nullptr);
    ~Element();

    virtual Vecteur3D champMagnetique(Vecteur3D const&) const=0;
    virtual bool heurte_bord(Particule const&) const=0;
   
    bool passe_au_suivant(Particule const&) const;
};

