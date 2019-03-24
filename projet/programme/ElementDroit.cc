#include "ElementDroit.h"

ElementDroit::ElementDroit(Vecteur3D _re, Vecteur3D _rs, double _Re, Element const& _suivant)
:Element(_re,_rs,_Re,_suivant) {}

ElementDroit::~ElementDroit()
{}

bool ElementDroit::heurte_bord(Particule const& _particule) const{
    Vecteur3D vec_X(_particule.position()-vec_re);
    Vecteur3D vec_d(~(vec_rs-vec_re));
    if ((vec_X-(vec_X*vec_d)*vec_d).norme()>scal_Re) {return true;}
    else{return false;}}