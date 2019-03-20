#include <iostream>
#include "Particule.h"
#include "Vecteur3D.h"
#include "ConstantesPhysiques.h"

using namespace std;
using namespace ConstantesPhysiques;

int main()
{
    Vecteur3D _r1(3.00984, -0.391837, 0), _r2(2.99016, -0.391837, 0);
    Vecteur3D _v1(-1,-1,0);
    double _E(2);
    double _m(0.938272);
    double _q(const_e);
    Particule p1(_r1,_v1,_E,_m,_q), p2(_r2,_v1,_E,_m,_q);
    cout<<"Création de deux particules :";
    cout<<p1<<endl<<p2<<endl;  
    Vecteur3D _B(0,0,7);
    double _dt (pow(10,-11));
    p1.ajouteForceMagnetique(_B, _dt);
    return 0;
}
