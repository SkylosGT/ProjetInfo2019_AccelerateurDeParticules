#include "ElementDroit.h"
#include "ConstantesPhysiques.h"

using namespace ConstantesPhysiques;

//DEFINITION DES METHODES DE LA CLASSE ELEMENT DROIT ET SURCHARGE DE SES OPERATEURS

//METHODES PUBLIQUES DE LA CLASSE ELEMENT DROIT
ElementDroit::ElementDroit(Vecteur3D _re, Vecteur3D _rs, double _Re, SupportADessin* _support)
:Element(_re,_rs,_Re, _support) {}

ElementDroit::~ElementDroit() {}

bool ElementDroit::heurte_bord(Particule const& _p) const{
    Vecteur3D vec_X(_p.position()-vec_re);
    Vecteur3D vec_d(~(vec_rs-vec_re));
    if ((vec_X-(vec_X*vec_d)*vec_d).norme()>scal_Re) {return true;}
    else{return false;}}
    
Vecteur3D ElementDroit::u() const {
	return vec_e3^(~(vec_rs-vec_re));	}
