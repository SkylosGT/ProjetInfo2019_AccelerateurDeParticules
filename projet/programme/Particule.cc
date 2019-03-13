#include "Particule.h"
#include <cmath>

Particule::Particule(Vecteur3D _r, Vecteur3D _p, double _m, double _q)
:vec_r(_r), vec_p(_p), scal_m(_m), scal_q(_q) {}

Particule::~Particule()
{
}

double Particule::scalEnergy(){

}

double Particule::scalGammaFactor(){

}