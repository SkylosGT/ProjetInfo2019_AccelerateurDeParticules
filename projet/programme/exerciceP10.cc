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

    /*Deux particules P1 et P2*/
    Particule p1(_r1, _v1, _E, _m, _q), p2(_r2,_v2,_E,_m,_q);
    
    //Test de l'ajout des éléments dans l'accélérateur
    _accelerateur.ajoutElement(&D);
    _accelerateur.ajoutElement(&S);
    _accelerateur.ajoutElement(&Q);

    //Test de l'ajout des deux particules dans l'accélérateur
    _accelerateur.ajoutParticule(p1);
    _accelerateur.ajoutParticule(p2);

    //Affichage de tout les éléments et particules que contient l'accélérateur
    cout <<"Après ajout d'un dipole, d'un quadrupole, d'une section droite et de deux particules dans l'accélérateur : " << endl;
    _accelerateur.dessine();
    
    //Test de la suppression des éléments et particules de l'accélérateur
    _accelerateur.supprCollectionParticule();
    _accelerateur.supprCollectionElement();

    //Réaffichage de l'accélérateur pour tester que l'accélérateur ne contient aucun élément ni aucune particule
    cout << "On supprime tous les éléments et toutes les particules de l'accélérateur:"<< endl; cout << endl;
    _accelerateur.dessine();


    return 0;
}
