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
                S7((*new Vecteur3D(1,3,0)), (*new Vecteur3D(2,3,0)), Re), S8((*new Vecteur3D(3,1,0)), (*new Vecteur3D(3,0,0)), Re);

    Dipole D1((*new Vecteur3D(3,-2,0)), (*new Vecteur3D(2,-3,0)), Re, Rc, Bz),  D2((*new Vecteur3D(-2,-3,0)), (*new Vecteur3D(-3,-2,0)), Re, Rc, Bz),
             D3((*new Vecteur3D(-3,2,0)), (*new Vecteur3D(-2,3,0)), Re, Rc, Bz),  D4((*new Vecteur3D(2,3,0)), (*new Vecteur3D(3,2,0)), Re, Rc, Bz);
    
    //Test de l'ajout des éléments dans l'accélérateur
    _accelerateur.ajoutElement(&Q1);
    _accelerateur.ajoutElement(&S1);
    _accelerateur.ajoutElement(&D1);
    _accelerateur.ajoutElement(&Q2);
    _accelerateur.ajoutElement(&S2);
    _accelerateur.ajoutElement(&Q3);
    _accelerateur.ajoutElement(&S3);
    _accelerateur.ajoutElement(&D2);
    _accelerateur.ajoutElement(&Q4);
    _accelerateur.ajoutElement(&S4);
    _accelerateur.ajoutElement(&Q5);
    _accelerateur.ajoutElement(&S5);
    _accelerateur.ajoutElement(&D3);
    _accelerateur.ajoutElement(&Q6);
    _accelerateur.ajoutElement(&S6);
    _accelerateur.ajoutElement(&Q7);
    _accelerateur.ajoutElement(&S7);
    _accelerateur.ajoutElement(&D4);
    _accelerateur.ajoutElement(&Q8);
    _accelerateur.ajoutElement(&S8);

    //Test de l'ajout des deux particules dans l'accélérateur
    _accelerateur.ajoutParticule(p1);
    _accelerateur.ajoutParticule(p2);

    //Affichage de tout les éléments et particules que contient l'accélérateur
    cout <<"Après ajout d'un dipole, d'un quadrupole, d'une section droite et de deux particules dans l'accélérateur : " << endl;
    _accelerateur.dessine();

    return 0;
}
