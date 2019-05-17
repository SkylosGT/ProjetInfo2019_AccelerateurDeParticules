#include <QApplication>
#include "glwidget.h"
#include "Particule.h"
#include "Dipole.h"
#include "Quadrupole.h"
#include "SectionDroite.h"
#include "ConstantesPhysiques.h"
#include "FaisceauCirculaire.h"

using namespace ConstantesPhysiques;

int main(int argc, char* argv[])
{

  QApplication a(argc, argv);
  GLWidget w;

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

  /*Attributs physiques des Elements Q, S, D*/
  double Re(0.1), b(1.2), Rc(1), Bz(5.89158);

  //Ajout des quadrupoles
  Quadrupole Q1((*new Vecteur3D(3,0,0)), (*new Vecteur3D(3,-1,0)), Re, -b), Q2((*new Vecteur3D(2,-3,0)), (*new Vecteur3D(1,-3,0)), Re, b),
              Q3((*new Vecteur3D(0,-3,0)), (*new Vecteur3D(-1,-3,0)), Re, -b), Q4((*new Vecteur3D(-3,-2,0)), (*new Vecteur3D(-3,-1,0)), Re, b),
              Q5((*new Vecteur3D(-3,0,0)), (*new Vecteur3D(-3,1,0)), Re, -b), Q6((*new Vecteur3D(-2,3,0)), (*new Vecteur3D(-1,3,0)), Re, b),
              Q7((*new Vecteur3D(0,3,0)), (*new Vecteur3D(1,3,0)), Re, -b), Q8((*new Vecteur3D(3,2,0)), (*new Vecteur3D(3,1,0)), Re, b);

  //Ajouts des sections drotes
  SectionDroite S1((*new Vecteur3D(3,-1,0)), (*new Vecteur3D(3,-2,0)), Re), S2((*new Vecteur3D(1,-3,0)), (*new Vecteur3D(0,-3,0)), Re),
              S3((*new Vecteur3D(-1,-3,0)), (*new Vecteur3D(-2,-3,0)), Re), S4((*new Vecteur3D(-3,-1,0)), (*new Vecteur3D(-3,0,0)), Re),
              S5((*new Vecteur3D(-3,1,0)), (*new Vecteur3D(-3,2,0)), Re), S6((*new Vecteur3D(-1,3,0)), (*new Vecteur3D(0,3,0)), Re),
              S7((*new Vecteur3D(1,3,0)), (*new Vecteur3D(2,3,0)), Re), S8((*new Vecteur3D(3,1,0)), (*new Vecteur3D(3,0,0)), Re);

  //Ajout des Dipoles
  Dipole D1((*new Vecteur3D(3,-2,0)), (*new Vecteur3D(2,-3,0)), Re, Rc, Bz),  D2((*new Vecteur3D(-2,-3,0)), (*new Vecteur3D(-3,-2,0)), Re, Rc, Bz),
           D3((*new Vecteur3D(-3,2,0)), (*new Vecteur3D(-2,3,0)), Re, Rc, Bz),  D4((*new Vecteur3D(2,3,0)), (*new Vecteur3D(3,2,0)), Re, Rc, Bz);

  //Ajout des éléments dans l'accélérateur
  w.ajoutElement(&D1);
  w.ajoutElement(&Q2);
  w.ajoutElement(&S2);
  w.ajoutElement(&Q3);
  w.ajoutElement(&Q1);
  w.ajoutElement(&S1);
  w.ajoutElement(&S3);
  w.ajoutElement(&D2);
  w.ajoutElement(&S6);
  w.ajoutElement(&Q7);
  w.ajoutElement(&S7);
  w.ajoutElement(&D4);
  w.ajoutElement(&S4);
  w.ajoutElement(&Q8);
  w.ajoutElement(&S8);
  w.ajoutElement(&Q5);
  w.ajoutElement(&Q4);
  w.ajoutElement(&S5);
  w.ajoutElement(&D3);
  w.ajoutElement(&Q6);

  //Ajout des deux particules dans l'accélérateur
  //Deux faisceaux circulaires avec comme particules de référence p1 et p2
  FaisceauCirculaire faisceau1(p1, 36, 2);

  //Ajout des faisceaux dans l'accélérateur
  w.ajoutFaisceau(&faisceau1);


  w.show();



  return a.exec();
}
