#include "Particule.h"
#include <cmath>
/*!!Changer de place */ 
const double c(1);
Particule::Particule(Vecteur3D _r, Vecteur3D _p, double _m, double _q)
:vec_r(_r), vec_p(_p), scal_m(_m), scal_q(_q) {}

Particule::~Particule()
{
}

double Particule::scalNormeVitesse(){
    double scal_normeP= vec_p.norme();
    return (scal_normeP)/(sqrt(pow(scal_m, 2)+pow((scal_normeP/ c),2))); //!!c temporaire
}

double Particule::scalEnergie(){

}

double Particule::scalFacteurGamma(){

}