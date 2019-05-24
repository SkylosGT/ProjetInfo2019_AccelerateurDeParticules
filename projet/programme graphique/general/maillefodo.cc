#include "maillefodo.h"
#include "Quadrupole.h"
#include "SectionDroite.h"

#include<iostream>

using namespace std;

MailleFODO::MailleFODO(Vecteur3D _re, Vecteur3D _rs, double _Re, double _b, double _L, SupportADessin* _support)
    :ElementDroit (_re, _rs,_Re, _support),scal_L(_L), scal_b(_b), vec_d(~(vec_rs-vec_re)){
        elements.push_back(new Quadrupole(vec_re, vec_re+longueurQuadrupole()*vec_d, scal_Re, scal_b));
        elements.push_back(new SectionDroite(vec_re+longueurQuadrupole()*vec_d, vec_re+(longueurQuadrupole()+scal_L)*vec_d, scal_Re));
        elements.push_back(new Quadrupole(vec_re+(longueurQuadrupole()+scal_L)*vec_d, vec_re+(2*longueurQuadrupole()+scal_L)*vec_d, scal_Re, -scal_b));
        elements.push_back(new SectionDroite(vec_re+(2*longueurQuadrupole()+scal_L)*vec_d, vec_rs, scal_Re));}

double MailleFODO::longueurQuadrupole(){
    return ((vec_rs-vec_re).norme()/2-scal_L);}

Vecteur3D MailleFODO::champMagnetique(const Vecteur3D& position) const{
    return trouveElementDeLaMaille(position)->champMagnetique(position);}

Element* MailleFODO::trouveElementDeLaMaille(const Vecteur3D& position) const{
    for (auto element :elements) {
        if(element_particule(position)){return element;}
        else{return nullptr;}}}

ostream& MailleFODO::affiche(ostream& sortie) const {
    for (auto element : elements) {
        element->affiche(sortie);}}

void MailleFODO::change_support(SupportADessin *nouveau){
    support=nouveau;
    for (auto element:elements) {
        element->change_support(nouveau);}}
