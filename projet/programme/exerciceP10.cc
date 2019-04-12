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

    double Re(0.1);
    double b(1.2);
    double Rc(1);
    double Bz(5.89158);

    Quadrupole Q1((*new Vecteur3D(3,0,0)), (*new Vecteur3D(3,-1,0)), Re, -b), Q2((*new Vecteur3D(2,-3,0)), (*new Vecteur3D(1,-3,0)), Re, b),
                Q3((*new Vecteur3D(0,-3,0)), (*new Vecteur3D(-1,-3,0)), Re, -b), Q4((*new Vecteur3D(-3,-2,0)), (*new Vecteur3D(-3,-1,0)), Re, b),
                Q5((*new Vecteur3D(-3,0,0)), (*new Vecteur3D(-3,1,0)), Re, -b), Q6((*new Vecteur3D(-2,3,0)), (*new Vecteur3D(-1,3,0)), Re, b),
                Q7((*new Vecteur3D(0,3,0)), (*new Vecteur3D(-1,3,0)), Re, -b), Q8((*new Vecteur3D(3,2,0)), (*new Vecteur3D(3,1,0)), Re, b);
    
    SectionDroite S1((*new Vecteur3D(3,-1,0)), (*new Vecteur3D(3,-2,0)), Re), S2((*new Vecteur3D(1,-3,0)), (*new Vecteur3D(0,-3,0)), Re),
                S3((*new Vecteur3D(-1,-3,0)), (*new Vecteur3D(-2,-3,0)), Re), S4((*new Vecteur3D(-3,-1,0)), (*new Vecteur3D(-3,0,0)), Re),
                S5((*new Vecteur3D(-3,1,0)), (*new Vecteur3D(-3,2,0)), Re), S6((*new Vecteur3D(-1,3,0)), (*new Vecteur3D(0,3,0)), Re),
                S7((*new Vecteur3D(1,3,0)), (*new Vecteur3D(2,3,0)), Re), S1((*new Vecteur3D(3,1,0)), (*new Vecteur3D(3,0,0)), Re);

    Dipole D1((*new Vecteur3D(3,-2,0)), (*new Vecteur3D(2,-3,0)), Re, Rc, Bz),  D2((*new Vecteur3D(-2,-3,0)), (*new Vecteur3D(-3,-2,0)), Re, Rc, Bz),
             D3((*new Vecteur3D(-3,2,0)), (*new Vecteur3D(-2,3,0)), Re, Rc, Bz),  D1((*new Vecteur3D(2,3,0)), (*new Vecteur3D(3,2,0)), Re, Rc, Bz);
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
