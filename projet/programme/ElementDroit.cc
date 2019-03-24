#include "ElementDroit.h"

ElementDroit::ElementDroit(Vecteur3D _re, Vecteur3D _rs, double _Re, Element const& _suivant)
:Element(_re,_rs,_Re,_suivant)
{
}

ElementDroit::~ElementDroit()
{
}

bool Element::heurte_bord(Particule const& _particule) const{
    
}