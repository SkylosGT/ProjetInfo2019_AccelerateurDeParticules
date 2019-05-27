#include <iostream>

#include "SupportConsole.h"
#include "Particule.h"
#include "Dipole.h"
#include "Accelerateur.h"
#include "ConstantesPhysiques.h"
#include "Quadrupole.h"
#include "SectionDroite.h"
#include "Vecteur3D.h"
#include "ElementDroit.h"
#include "ElementCourbe.h"
#include "Faisceau.h"
#include "FaisceauCirculaire.h"
#include "MailleFODO.h"

using namespace std;
using namespace ConstantesPhysiques;

int main () {
	
    //Support à dessin type console
    SupportConsole ecran(cout);

	//Un accélérateur par défauts (vide : aucun élément, aucune particule)
	Accelerateur _accelerateur(&ecran);

    //On construit l'accelerateur
    _accelerateur.construireAccelerateur(1);

	/*Attributs physiques de deux particules P1 et P2*/

	//Positions de P1 et P2
    Vecteur3D _r1(3.01, 0, 0), _r2(2.99, 0, 0);

    //Vitesses de P1 et P2
    Vecteur3D _v1(0, -2.64754e+8, 0), _v2(0, -2.64754e+8, 0);

    //Energie de P1 et P2
    double _E(2);

    //Masse de P1 et P2
    double _m(0.938272);

    //Charge de P1 et P2
    double _q(const_e);
    
	cout <<"AVANT AJOUT DE FAISCEAUX"<< endl;
	_accelerateur.dessine();

    //Deux particules P1 et P2
    Particule p1(_r1, _v1, _E, _m, _q), p2(_r2,_v2,_E,_m,_q);
    
    //Deux faisceaux circulaires avec comme particules de référence p1 et p2
    FaisceauCirculaire faisceau1(p1, 10, 1), faisceau2(p2, 20, 1);

    _accelerateur.ajoutFaisceau(&faisceau1);
    _accelerateur.ajoutFaisceau(&faisceau2);

	//Test de l'ajout des faisceaux dans l'accélérateur
	cout << "AVANT EVOLUTION DU SYSTEME ET APRES AJOUT DE FAISCEAU"<< endl;
	_accelerateur.dessine();

    int pas(2);

    //Le système evolue
    for(size_t i = 0; i < pas; i++)
    {
        _accelerateur.evolue(1e-11);
    }
    
    //Dessin de l'accélérateur après évolution du système
    cout << "APRES EVOLUTION DU SYSTEME "<<pas<<" PAS"<<endl;
    _accelerateur.dessine();

    return 0;
}
