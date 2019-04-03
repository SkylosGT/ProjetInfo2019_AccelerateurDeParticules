#include <iostream>

#include "Vecteur3D.h"
#include "Accelerateur.h"
#include "Particule.h"
#include "Dipole.h"
#include "Quadrupole.h"
#include "SectionDroite.h"
#include "ConstantesPhysiques.h"

using namespace std;
using namespace ConstantesPhysiques;

//TEST de la classe Accelerateur, de ses méthode et de la surcharge des opérateurs pour les particules
int main() {

	//Un accélérateur par défauts (vide : aucun élément, aucune particule)
	Accelerateur _accelerateur;
	
	//Test du constructeur par défaut
	cout << "Après initialisation par défauts de l'accélérateur (vide) : " << endl; cout << endl;
	cout << _accelerateur << endl;
	
	/*Attributs physiques de deux particules P1 et P2*/
	//Positions de P1 et P2
    Vecteur3D _r1(1.00984, -0.191837, 0), _r2(0.99016, -0.191837, 0);

    //Vitesses de P1 et P2
    Vecteur3D _v1(-210200, -2.64754e+8, 0), _v2(210200, -2.64754e+8, 0);

    //Energie de P1 et P2
    double _E(2);

    //Masse de P1 et P2
    double _m(0.938272);

    //Charge de P1 et P2
    double _q(const_e);

    /*Deux particules P1 et P2*/
    Particule p1(_r1, _v1, _E, _m, _q), p2(_r2,_v2,_E,_m,_q);
    
    /*Attributs physiques des elements D, Q, S*/
    //Position d'entrée de D, Q et S
    Vecteur3D _re1(1,0,0), _re2(0,1,0), _re3(0,0,1);

    //Position de sortie de D, Q et S
    Vecteur3D _rs1(0,-1,0), _rs2(0,0,-1), _rs3(-1,0,0);
    
    //Rayon de la chambre à vide de D, Q et S
    double _Re1(0.1), _Re2(0.2), _Re3(0.3);

    //Rayon de courbure de D
    double _k(1);

    //Norme du champ magnetique de D et Q
    double _Bz(7);

    //Dipole D
    Dipole D(_re1, _rs1, _Re1, _k, _Bz);

    //Quadrupole Q
    Quadrupole Q(_re2, _rs2, _Re2, _Bz);

    //Section droite S
    SectionDroite S(_re3, _rs3, _Re3);

    //Test de l'ajout des éléments dans l'accélérateur
    _accelerateur.ajoutElement(&D);
    _accelerateur.ajoutElement(&Q);
    _accelerateur.ajoutElement(&S);

    //Test de l'ajout des deux particules dans l'accélérateur
    _accelerateur.ajoutParticule(p1);
    _accelerateur.ajoutParticule(p2);

    
    //Affichage de tout les éléments et particules que contient l'accélérateur
    cout <<"Après ajout d'un dipole, d'un quadrupole, d'une section droite et de deux particules dans l'accélérateur : " << endl;
    cout << _accelerateur << endl;
    
    //Test de la suppression des éléments et particules de l'accélérateur
    _accelerateur.supprCollectionParticule();
    _accelerateur.supprCollectionElement();

    //Réaffichage de l'accélérateur pour tester que l'accélérateur ne contient aucun élément ni aucune particule
    cout << "On supprime tous les éléments et toutes les particules de l'accélérateur:"<< endl; cout << endl;
    cout << _accelerateur << endl;
	
	return 0;
}
