#include "Element.h"

class ElementCourbe : public Element
{
protected:
    double scal_k;
    Vecteur3D centreDeCourbure() const;
public:
    ElementCourbe(Vecteur3D, Vecteur3D, double, Element const&, double);
    ~ElementCourbe();
    virtual bool heurte_bord(Particule const&) const override;
};

