#include <iostream>
#include "Accelerateur.h"
#include "Particule.h"
#include "Vecteur3D.h"
#include "ConstantesPhysiques.h"

using namespace ConstantesPhysiques;
using namespace std;


int main() {
	cout<<"Test"<<endl;
	//Un accélérateur
	Accelerateur _A;
	
	//Positions de P1 et P2
    Vecteur3D _r1(3.00984, -0.391837, 0), _r2(2.99016, -0.391837, 0);

    //Vitesses de P1 et P2
    Vecteur3D _v1(-210200, -2.64754e+8, 0), _v2(210200, -2.64754e+8, 0);

    //Energie de P1 et P2
    double _E(2);

    //Masse de P1 et P2
    double _m(0.938272);

    //Charge de P1 et P2
    double _q(const_e);

    //Deux particules P1 et P2
    Particule p1(_r1, _v1, _E, _m, _q), p2(_r2,_v2,_E,_m,_q);
    
    _A.ajoutParticule(p1);
    _A.ajoutParticule(p2);
    
    cout << _A << endl;
    
    _A.supprCollectionParticule();
	
	return 0;
}
