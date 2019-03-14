#include "Particule.h"
#include "ConstantesPhysiques.h"
#include <cmath>
using  namespace ConstantesPhysiques;

//Constructeur par vecteur quantité de mouvement en Gev
Particule::Particule(Vecteur3D _r, Vecteur3D _p, double _m, double _q)
:vec_r(_r), scal_m(_m), scal_q(_q) 
{
    vec_v=_p.mult(scal_c/sqrt((_m*_m)+_p.norme2()));
}

//Constructeur par energie en GeV et direction vectorielle
Particule::Particule(Vecteur3D _r, Vecteur3D _vitesseUnitaire, double _energie, double _m, double _q)
:vec_r(_r), scal_m(_m), scal_q(_q) 
{
    vec_v=_vitesseUnitaire.mult(scal_c*sqrt(1-(scal_m*scal_m)/(_energie*_energie)));
}

double Particule::Energie()
{
    return FacteurGamma()*scal_m*scal_c*scal_c;
}

double Particule::FacteurGamma()
{
    return 1/sqrt(1-(vec_v.norme()/scal_c)*(vec_v.norme()/scal_c));
}

Particule::~Particule(){}

