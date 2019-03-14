#include "Particule.h"
#include "ConstantesPhysiques.h"
#include <cmath>
 
using  namespace ConstantesPhysiques;
//Constructeur par vecteur quantité de mouvement en Gev
Particule::Particule(Vecteur3D _r, Vecteur3D _p, double _m, double _q)
:vec_r(_r), scal_m(_m), scal_q(_q) 
{

}

//Constructeur par energie en GeV et direction vectorielle
Particule::Particule(Vecteur3D _r, Vecteur3D _vitesseUnitaire, double _energie, double _m, double _q)
:vec_r(_r), scal_m(_m), scal_q(_q) {}

Particule::~Particule(){}

Vecteur3D Particule::toVec_pSI(Vecteur3D _p){
    return _p.mult()
}

//utilisation de pow() pour une meilleure compréhension
double Particule::scalNormeVitesse(){
    double scal_normeP= vec_p.norme();
    return (scal_normeP)/(sqrt(pow(scal_m, 2)+pow((scal_normeP/ scal_c),2)));
}

double Particule::scalEnergie(){
    return scalFacteurGamma()*scal_m*pow(scal_c, 2); 
}

double Particule::scalFacteurGamma(){
    return 1/sqrt(1-pow(scalNormeVitesse()/scal_c,2));
}
