#include <iostream>
#include "SupportConsole.h"
#include "Particule.h"
#include "Dipole.h"
#include "Accelerateur.h"
#include "ConstantesPhysiques.h"
#include "Quadrupole.h"
#include "SectionDroite.h"

using namespace std;
using namespace ConstantesPhysiques;

int main()
{
    SupportConsole ecran(cout);

	//Un accélérateur par défauts (vide : aucun élément, aucune particule)
	Accelerateur _accelerateur(&ecran);

    /*Deux particules P1 et P2*/
    Particule p1((*new Vecteur3D(3.01,0,0)), (*new Vecteur3D(0,-2.64754e+08,0)), 2, 0.938272, const_e);
    Particule p2((*new Vecteur3D(2.99,0,0)), (*new Vecteur3D(0,-2.64754e+08,0)), 2, 0.938272, const_e);

    

    return 0;
}
