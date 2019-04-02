#include <iostream>
#include "Accelerateur.h"
#include "Particule.h"
#include "Vecteur3D.h"
#include "ConstantesPhysiques.h"

using namespace ConstantesPhysiques;
using namespace std;


int main() {
	//Un accélérateur par défauts (vide : aucun élément, aucune particule)
	Accelerateur _A;
	
	//Test du constructeur par défaut
	cout << "Après initialisation par défauts de l'accélérateur : " << endl; cout << endl;
	cout << _A << endl;
	
	//Constructions des attributs de deux particules P1 et P2
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
    
    //Ajout des deux particules dans l'accélérateur
    _A.ajoutParticule(p1);
    _A.ajoutParticule(p2);
    
    //Affichage de tout les éléments et particules que contient l'accélérateur
    cout <<"Après ajout de deux particules dans l'accélérateur : " << endl; cout << endl;
    cout << _A << endl;
    
    //Suppression des particules de l'accélérateur
    _A.supprCollectionParticule();
    
    //Réaffichage de l'accélérateur pour tester que l'accélérateur ne contient aucune particule
    cout << "On supprime toutes les particules de l'accélérateur:"<< endl; cout << endl;
    cout << _A << endl;
	
	return 0;
}
