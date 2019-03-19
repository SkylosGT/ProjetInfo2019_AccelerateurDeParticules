#include "Particule.h"
#include "ConstantesPhysiques.h"
#include <iostream>
#include <cmath>
using  namespace ConstantesPhysiques;
using namespace std;

//Constructeur par vecteur quantité de mouvement en Gev
Particule::Particule(Vecteur3D _r, Vecteur3D _p, double _m, double _q)
:vec_r(_r), scal_m(_m), scal_q(_q) 
{
    vec_v=_p*(scal_c/sqrt((_m*_m)+_p.norme2()));
}

//Constructeur par energie en GeV et direction vectorielle
Particule::Particule(Vecteur3D _r, Vecteur3D _vitesseUnitaire, double _energie, double _m, double _q)
:vec_r(_r), scal_m(_m), scal_q(_q) 
{
    vec_v=_vitesseUnitaire*(scal_c*sqrt(1-(scal_m*scal_m)/(_energie*_energie)));
}

//
double Particule::Energie()
{
    return FacteurGamma()*scal_m*scal_c*scal_c;
}

double Particule::FacteurGamma()
{
    return 1/sqrt(1-(vec_v.norme()/scal_c)*(vec_v.norme()/scal_c));
}

void Particule::ajouteForceMagnetique(Vecteur3D _B, double _dt){
    vec_f=_B^(vec_v*scal_m); //Manque rotation
}

void Particule::bouger(double _dt){
    vec_v=vec_v+(vec_f*(_dt/(FacteurGamma()*scal_m)));
    vec_r=vec_r+(vec_v*(_dt));
    vec_f=*new Vecteur3D();
}

/*void Particule::affiche(){
    vec_r.affiche();
    vec_v.affiche();
    vec_f.affiche();
}*/

Particule::~Particule(){}

//ostream& operator<<(std::ostream& sortie, Particule const& P){
    //sortie=P.affiche();
    //return sortie;
//}