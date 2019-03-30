#include <iostream>

#include "Element.h"
#include "ConstantesPhysiques.h"

using namespace ConstantesPhysiques;
using namespace std;

//DEFINITION DES METHODES DE LA CLASSE ELEMENT ET SURCHARGE DE SES OPERATEURS

Element::Element(Vecteur3D _re, Vecteur3D _rs, double _Re, Element* _suivant)
:vec_re(_re), vec_rs(_rs), scal_Re(_Re), elem_suivant(_suivant)
{}

Element::~Element()
{}

bool Element::passe_au_suivant(Particule const& _p) const{
    if (vec_e3*(_p.position()^vec_rs)>0) {return true;}
    else{false;}}
