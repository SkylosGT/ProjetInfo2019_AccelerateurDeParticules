#include "Vecteur3D.h"
#include "Particule.h"

class Element
{
private:
    Vecteur3D vec_re;
    Vecteur3D vec_rs;
    double scal_Re;
    Element const& elem_suivant;

public:
    Element(Vecteur3D, Vecteur3D, double, Element const&);
    ~Element();
    void champsMagnetique(Vecteur3D) const;
    bool heurte_bord(Particule const&) const;
    bool passe_au_suivant(Particule const&) const;
};

