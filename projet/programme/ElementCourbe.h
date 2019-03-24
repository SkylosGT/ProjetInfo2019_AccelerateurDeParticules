#include "Element.h"

class ElementCourbe : public Element
{
private:
    double scal_k;

    Vecteur3D centreDeCourbure() const;
public:
    ElementCourbe(Vecteur3D, Vecteur3D, double, Element const&, double);
    ~ElementCourbe();
    bool heurte_bord(Particule const&) const;
};

