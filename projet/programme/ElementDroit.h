#include "Element.h"

class ElementDroit: public Element
{
private:
    /* data */
public:
    ElementDroit(Vecteur3D, Vecteur3D, double, Element const&);
    ~ElementDroit();
    bool heurte_bord(Particule const&) const;
};


