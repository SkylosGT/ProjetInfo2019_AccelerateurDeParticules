#include "Element.h"
#include "ConstantesPhysiques.h"
#include <iostream>

using namespace ConstantesPhysiques;
using namespace std;

Element::Element(Vecteur3D _re, Vecteur3D _rs, double _Re, Element* _suivant)
:vec_re(_re), vec_rs(_rs), scal_Re(_Re), elem_suivant(_suivant)
{}

Element::~Element()
{}

Element* Element::passe_au_suivant(Particule const& _p) const{
    if (vec_e3*(_p.position()^vec_rs)>0) {return elem_suivant;}
    else{this;}}
