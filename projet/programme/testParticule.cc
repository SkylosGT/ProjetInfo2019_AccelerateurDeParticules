#include <iostream>
#include "Particule.h"
#include "Vecteur3D.h"
#include "ConstantesPhysiques.h"

using namespace std;
using namespace ConstantesPhysiques;

void afficheParticule(Particule&);
int main()
{
    Vecteur3D _r1(3.00984, -0.391837, 0), _r2(2.99016, -0.391837, 0);
    Vecteur3D _v1(-1,-1,0), _v2(1,-1,0);
    double _E(2);
    double _m(0.938272);
    double _q(const_e);
    Particule p1(_r1,_v1,_E,_m,_q), p2(_r2,_v2,_E,_m,_q);
    afficheParticule(p1);
    afficheParticule(p2);
    
    return 0;
}

void afficheParticule(Particule& p){
    cout<<"Une particule :"<<endl;
    cout<<p<<endl;

}