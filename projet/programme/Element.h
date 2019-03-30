#include "Vecteur3D.h"
#include "Particule.h"

class Element {
protected:
    Vecteur3D vec_re;
    Vecteur3D vec_rs;
    double scal_Re;

private:
    Element const& elem_suivant;

public:
    Element(Vecteur3D, Vecteur3D, double, Element const&);
    ~Element();
    Vecteur3D champMagnetique(Vecteur3D const&) const;
    bool heurte_bord(Particule const&) const;
    bool passe_au_suivant(Particule const&) const;
    std::ostream& affiche(std::ostream& ) const;
};

std::ostream& operator<<(std::ostream&, Element const&);
