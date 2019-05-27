#include "Element.h"
#include "ConstantesPhysiques.h"

using namespace ConstantesPhysiques;
using namespace std;

//DEFINITION DES METHODES DE LA CLASSE ELEMENT ET SURCHARGE DE SES OPERATEURS

//METHODES PUBLIQUES DE LA CLASSE ELEMENT
Element::Element(Vecteur3D _re, Vecteur3D _rs, double _Re, SupportADessin* _support, Element* _suivant)
:Dessinable(_support), vec_re(_re), vec_rs(_rs), scal_Re(_Re), elem_suivant(_suivant) {}

Element::~Element() {}

bool Element::passe_au_suivant(Particule const& _p) const{
    if (vec_e3*(_p.position()^vec_rs)>0) {return true;}
    else{return false;}}

void Element::attacheElementSuivant(Element * suivant){
    elem_suivant=suivant;}

bool Element::particuleCollider(Vecteur3D const& position) const{
    if((position^vec_re).getz()>=0 and (position^vec_rs).getz()<=0){
        return true;
    }else {
    return false;}}

std::ostream& operator<<(std::ostream& sortie, Element const& E){
    return E.affiche(sortie);}
