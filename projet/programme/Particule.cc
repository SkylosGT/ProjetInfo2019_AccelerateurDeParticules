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
    vec_v=_p*(const_c/sqrt((_m*_m)+_p.norme2()));
    vec_f=*new Vecteur3D();
}

//Constructeur par energie en GeV et direction vectorielle
Particule::Particule(Vecteur3D _r, Vecteur3D _vitessedirective, double _energie, double _m, double _q)
:vec_r(_r), scal_m(_m), scal_q(_q) 
{
    vec_v=_vitessedirective.unitaire()*(const_c*sqrt(1-(scal_m*scal_m)/(_energie*_energie)));
    vec_f=*new Vecteur3D();
}

//
double Particule::Energie()
{
    return FacteurGamma()*scal_m;
}

double Particule::FacteurGamma()
{
    return 1/sqrt(1-(vec_v.norme()/const_c)*(vec_v.norme()/const_c));
}

void Particule::ajouteForceMagnetique(Vecteur3D _B, double _dt){
    vec_f=(_B^(vec_v*scal_m));
    vec_f=vec_f.rotation(vec_f^vec_v, asin(_dt*vec_f.norme()/(2*FacteurGamma()*scal_m*vec_v.norme())));
}

void Particule::bouger(double _dt){
    vec_v=vec_v+(vec_f*(_dt/(FacteurGamma()*scal_m)));
    vec_r=vec_r+(vec_v*(_dt));
    vec_f=*new Vecteur3D();
}

ostream& Particule :: affiche(ostream& sortie){
    return sortie<<"Une particule :"<<endl<<
    "   position :"<<vec_r<<endl<<
    "   vitesse :"<<vec_v<<endl<<
    "   gamma :"<<FacteurGamma()<<endl<<
    "   enregie (GeV) :"<<Energie()<<endl<<
    "   masse (Gev)/c^2 :"<<scal_m<<endl<<
    "   charge :"<<scal_q<<endl<<
    "   force :"<<vec_f<<endl;
}

Particule::~Particule(){}

//Attention passage d'un objet de manière non constante non constant à changer
ostream& operator<<(std::ostream& sortie, Particule& P){
   return P.affiche(sortie);}