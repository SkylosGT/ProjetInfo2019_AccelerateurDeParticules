#include <iostream>
#include "SupportConsole.h"
#include "Particule.h"
#include "Dipole.h"
using namespace std;

int main()
{
  /* Nous voulons un support à dessin :                          *
   * ici un TextViewer qui écrit sur cout                        */
  SupportConsole ecran(cout);
  
  /* Nous voulons un contenu à dessiner, et que ce contenu       *
   * se dessine sur notre support à dessin précédent             */

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

   //Position d'entrée de D
    Vecteur3D _re1(1,0,0);

    //Position de sortie de D
    Vecteur3D _rs1(0,-1,0);
    
    //Rayon de la chambre à vide de D
    double _Re1(0.1);

    //Rayon de courbure de D
    double _k(1);

    //Norme du champ magnetique de D 
    double _Bz(7);


  Particule p(_r1, _v1, _E, _m, _q, &ecran);

  Dipole d(_re1, _rs1, _Re1, _k,_Bz, &ecran);

  // Nous dessinons notre contenu
  p.dessine();
  d.dessine();

  return 0;
}
