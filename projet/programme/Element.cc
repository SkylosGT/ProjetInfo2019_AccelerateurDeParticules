#include "Element.h"

Element::Element(Vecteur3D _re, Vecteur3D _rs, double _Re, Element const& _suivant, Vecteur3D _B)
:vec_re(_re), vec_rs(_rs), scal_Re(_Re), elem_suivant(_suivant), vect_B(_B)
{}

Element::~Element()
{}

bool Element::heurte_bord(Particule const& _p) const{
    return false;
}

bool Element::passe_au_suivant(Particule const& _p) const{
    return false;
}