#include <iostream>
#include "Particule.h"
#include "Vecteur3D.h"
#include "ConstantesPhysiques.h"

using namespace std;
using namespace ConstantesPhysiques;

int main()
{
    Vecteur3D _r1(3.00984, -0.391837, 0), _r2(2.99016, -0.391837, 0);
    Vecteur3D _v1(-210200, -2.64754e+8, 0), _v2(210200, -2.64754e+8, 0);
    double _E(2);
    double _m(0.938272);
    double _q(const_e);
    Particule p1(_r1,_v1,_E,_m,_q), p2(_r2,_v2,_E,_m,_q);
    cout<<"Création de deux particules :";
    cout<<p1<<endl<<p2<<endl;  
    Vecteur3D _B(0,0,7);
    double _dt (1e-11);
    cout<<"Ajout d'une force Magnetique B="<<_B<<"(dt="<<_dt<<") :"<<endl;
    cout<<" à P1 :"<<endl;
    p1.ajouteForceMagnetique(_B, _dt);
    cout<<" à P2 :"<<endl;
    p2.ajouteForceMagnetique(_B,_dt);
    cout<<"Les particules bougent 1 fois :"<<endl;
    p1.bouger(_dt);
    p2.bouger(_dt);
    cout<<p1<<endl<<p2<<endl;
    return 0;
}
