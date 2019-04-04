#include <iostream>
#include "SupportConsole.h"
#include "Contenu.h"
#include "Particule.h"
using namespace std;

int main()
{
  /* Nous voulons un support à dessin :                          *
   * ici un TextViewer qui écrit sur cout                        */
  SupportConsole ecran(cout);
  
  /* Nous voulons un contenu à dessiner, et que ce contenu       *
   * se dessine sur notre support à dessin précédent             */
  Contenu c(&ecran);

  //Positions de p
  Vecteur3D _r1(3.00984, -0.391837, 0);

  //Vitesses de p
  Vecteur3D _v1(-210200, -2.64754e+8, 0);

  //Energie de p
  double _E(2);

  //Masse de p
  double _m(0.938272);

  //Charge de p
  double _q(1);

  Particule p(_r1, _v1, _E, _m, _q, &ecran);

  // Nous dessinons notre contenu
  c.dessine();
  p.dessine();

  return 0;
}
