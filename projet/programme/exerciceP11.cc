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

using namespace std;
using namespace ConstantesPhysiques;

int main () {
	
    //Support à dessin type console
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

    /*Attributs physiques des Elements Q, S, D*/
    double Re(0.1), b(1.2), Rc(1), Bz(5.89158);
    
    //Ajout des quadrupoles
    Quadrupole Q1((*new Vecteur3D(3,0,0)), (*new Vecteur3D(3,-1,0)), Re, -b, &ecran), Q2((*new Vecteur3D(2,-3,0)), (*new Vecteur3D(1,-3,0)), Re, b, &ecran),
                Q3((*new Vecteur3D(0,-3,0)), (*new Vecteur3D(-1,-3,0)), Re, -b, &ecran), Q4((*new Vecteur3D(-3,-2,0)), (*new Vecteur3D(-3,-1,0)), Re, b, &ecran),
                Q5((*new Vecteur3D(-3,0,0)), (*new Vecteur3D(-3,1,0)), Re, -b, &ecran), Q6((*new Vecteur3D(-2,3,0)), (*new Vecteur3D(-1,3,0)), Re, b, &ecran),
                Q7((*new Vecteur3D(0,3,0)), (*new Vecteur3D(-1,3,0)), Re, -b, &ecran), Q8((*new Vecteur3D(3,2,0)), (*new Vecteur3D(3,1,0)), Re, b, &ecran);
    
    //Ajouts des sections drotes
    SectionDroite S1((*new Vecteur3D(3,-1,0)), (*new Vecteur3D(3,-2,0)), Re, &ecran), S2((*new Vecteur3D(1,-3,0)), (*new Vecteur3D(0,-3,0)), Re, &ecran),
                S3((*new Vecteur3D(-1,-3,0)), (*new Vecteur3D(-2,-3,0)), Re, &ecran), S4((*new Vecteur3D(-3,-1,0)), (*new Vecteur3D(-3,0,0)), Re, &ecran),
                S5((*new Vecteur3D(-3,1,0)), (*new Vecteur3D(-3,2,0)), Re, &ecran), S6((*new Vecteur3D(-1,3,0)), (*new Vecteur3D(0,3,0)), Re, &ecran),
                S7((*new Vecteur3D(1,3,0)), (*new Vecteur3D(2,3,0)), Re, &ecran), S8((*new Vecteur3D(3,1,0)), (*new Vecteur3D(3,0,0)), Re, &ecran);
    
    //Ajout des Dipoles
    Dipole D1((*new Vecteur3D(3,-2,0)), (*new Vecteur3D(2,-3,0)), Re, Rc, Bz, &ecran),  D2((*new Vecteur3D(-2,-3,0)), (*new Vecteur3D(-3,-2,0)), Re, Rc, Bz, &ecran),
             D3((*new Vecteur3D(-3,2,0)), (*new Vecteur3D(-2,3,0)), Re, Rc, Bz, &ecran),  D4((*new Vecteur3D(2,3,0)), (*new Vecteur3D(3,2,0)), Re, Rc, Bz, &ecran);
    
    //Ajout des éléments dans l'accélérateur
    _accelerateur.ajoutElement(&D1);
    _accelerateur.ajoutElement(&Q2);
    _accelerateur.ajoutElement(&S2);
    _accelerateur.ajoutElement(&Q3);
    _accelerateur.ajoutElement(&Q1);
    _accelerateur.ajoutElement(&S1);
    _accelerateur.ajoutElement(&S3);
    _accelerateur.ajoutElement(&D2);
    _accelerateur.ajoutElement(&S6);
    _accelerateur.ajoutElement(&Q7);
    _accelerateur.ajoutElement(&S7);
    _accelerateur.ajoutElement(&D4);
    _accelerateur.ajoutElement(&S4);
    _accelerateur.ajoutElement(&Q8);
    _accelerateur.ajoutElement(&S8);
    _accelerateur.ajoutElement(&Q5);
    _accelerateur.ajoutElement(&Q4);
    _accelerateur.ajoutElement(&S5);
    _accelerateur.ajoutElement(&D3);
    _accelerateur.ajoutElement(&Q6);
    
	//Test des ajouts d'élements dans l'accélérateur avant ajout de faisceau
	cout <<"AVANT AJOUT DE FAISCEAUX"<< endl;
	_accelerateur.dessine();
	
	//Deux particules P1 et P2
    Particule p1(_r1, _v1, _E, _m, _q, &ecran), p2(_r2,_v2,_E,_m,_q, &ecran);
    
    //Deux faisceaux circulaires avec comme particules de référence p1 et p2
	FaisceauCirculaire faisceau1(p1, 10, 2, &ecran);
	FaisceauCirculaire faisceau2(p2, 6, 3, &ecran);
	
	//Ajout des faisceaux dans l'accélérateur
	_accelerateur.ajoutFaisceau(&faisceau1);
	_accelerateur.ajoutFaisceau(&faisceau2);
	
	//Test de l'ajout des faisceaux dans l'accélérateur
	cout << "AVANT EVOLUTION DU SYSTEME"<< endl;
	_accelerateur.dessine();
	
	//Test de l'évolution du système
	for(size_t i = 0; i < 20; i++)
    {
        _accelerateur.evolue(1e-11);
    }
    
    //Dessin de l'accélérateur après évolution du système
	_accelerateur.dessine();
	
    return 0;

}
