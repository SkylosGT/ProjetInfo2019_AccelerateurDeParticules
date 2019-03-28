#include "Element.h"
#include "ConstantesPhysiques.h"
#include <iostream>

using namespace ConstantesPhysiques;
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
    if (vec_e3*(_p.position()^vec_rs)>0) {return true;}
    else{return false;}}

Vecteur3D Element::champMagnetique(Vecteur3D const&) const{
    return vec_e1;
}

ostream& Element::affiche(ostream& sortie) const {
	return sortie<<"Test Element"<<endl;}

ostream& operator<<(ostream& sortie, Element const& e){
	return e.affiche(sortie);}
	
	
	
	
