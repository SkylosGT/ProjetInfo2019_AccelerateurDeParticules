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
  //Support à dessin type console
  SupportConsole ecran(cout);

	//Un accélérateur par défauts (vide : aucun élément, aucune particule)
	Accelerateur _accelerateur(&ecran);
	
	//Test du constructeur par défaut
	cout << "Après initialisation par défauts de l'accélérateur (vide) : " << endl; cout << endl;
	_accelerateur.dessine();
	
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
    Particule p1(_r1, _v1, _E, _m, _q, &ecran), p2(_r2,_v2,_E,_m,_q, &ecran);
    
    /*Attributs physiques des elements D, S, Q*/
    //Position d'entrée de D, S et Q
    Vecteur3D _re1(1,0,0), _re2(0,-1,0), _re3(-1,-1,0);

    //Position de sortie de D, S et Q
    Vecteur3D _rs1(0,-1,0), _rs2(-1, -1, 0), _rs3(-2,-1,0);
    
    //Rayon de la chambre à vide de D, S et Q
    double _Re1(0.1), _Re2(0.1), _Re3(0.1);

    //Rayon de courbure de D
    double _k(1);

    //Norme du champ magnetique de D et Q
    double _Bz1(7), _Bz3(1.2);

    //Dipole D
    Dipole D(_re1, _rs1, _Re1, _k, _Bz1, &ecran);

    //Section droite S
    SectionDroite S(_re2, _rs2, _Re2, &ecran);

    //Quadrupole Q
    Quadrupole Q(_re3, _rs3, _Re3, _Bz3, &ecran);

    //Test de l'ajout des éléments dans l'accélérateur
    _accelerateur.ajoutElement(&D);
    _accelerateur.ajoutElement(&S);
    _accelerateur.ajoutElement(&Q);

    //Test de l'ajout des deux particules dans l'accélérateur
    _accelerateur.ajoutParticule(&p1);
    _accelerateur.ajoutParticule(&p2);

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
