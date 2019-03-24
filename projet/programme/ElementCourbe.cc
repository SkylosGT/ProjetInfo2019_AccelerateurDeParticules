#include "ElementCourbe.h"

ElementCourbe::ElementCourbe(Vecteur3D _re, Vecteur3D _rs, double _Re, Element const& _suivant, double _k)
:Element(_re,_rs,_Re,_suivant), scal_k(_k) {}

ElementCourbe::~ElementCourbe()
{}

bool Element::heurte_bord(Particule const& _particule) const {

}