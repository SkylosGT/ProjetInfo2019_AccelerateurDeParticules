#include <QApplication>
#include "glwidget.h"
#include "Particule.h"
#include "Dipole.h"
#include "Quadrupole.h"
#include "SectionDroite.h"
#include "ConstantesPhysiques.h"
#include "FaisceauCirculaire.h"
#include "MailleFODO.h"

using namespace ConstantesPhysiques;

int main(int argc, char* argv[])
{

  QApplication a(argc, argv);
  GLWidget w;

  //On construit l'accelerateur de rayon 1
  w.construireAccelerateur(1);

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

  //Un faisceau circulaire avec comme particules de référence p1
  FaisceauCirculaire faisceau1(p1, 17, 1);

  //Ajout du faisceau dans l'accélérateur
  w.ajoutFaisceau(&faisceau1);

  //Simulation
  w.show();

  return a.exec();
}
