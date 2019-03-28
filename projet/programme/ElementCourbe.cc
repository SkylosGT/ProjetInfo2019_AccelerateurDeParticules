#include <cmath>

#include "ElementCourbe.h"
#include "ConstantesPhysiques.h"

using namespace ConstantesPhysiques;

ElementCourbe::ElementCourbe(Vecteur3D _re, Vecteur3D _rs, double _Re, Element const& _suivant, double _k)
:Element(_re,_rs,_Re,_suivant), scal_k(_k) {}

ElementCourbe::~ElementCourbe()
{}

bool ElementCourbe::heurte_bord(Particule const& _particule) const{
    Vecteur3D vec_X(_particule.position()-centreDeCourbure());
    Vecteur3D vec_u(~(vec_X-(vec_X.getz()*vec_e3)));
    if ((vec_X-(1/abs(scal_k))*vec_u).norme()>scal_Re) {return true;}
    else{return false;}}

Vecteur3D ElementCourbe::centreDeCourbure() const {
    return 0.5*(vec_re+vec_rs)+((1/scal_k)*sqrt(1-(scal_k*scal_k/4)*(vec_rs-vec_re).norme2()))*((~(vec_rs-vec_re))^vec_e3);}