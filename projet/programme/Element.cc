#include "Element.h"
#include <iostream>

using namespace std;

Element::Element(Vecteur3D _re, Vecteur3D _rs, double _Re, Element const& _suivant)
:vec_re(_re), vec_rs(_rs), scal_Re(_Re), elem_suivant(_suivant)
{}

Element::~Element()
{}

bool Element::heurte_bord(Particule const& _p) const{
    cout<<"Heurte_bord"<<endl;
    return false;
}

bool Element::passe_au_suivant(Particule const& _p) const{
    cout<<"Heurte_bord"<<endl;
    return false;
}