#include <iostream>

#include "Quadrupole.h"

using namespace std;

//DEFINITION DES METHODES DE LA CLASSE QUADRUPOLE ET SURCHARGE DE SES OPERATEURS

//METHODES PUBLIQUES DE LA CLASSE QUADRUPOLE
Quadrupole::Quadrupole(Vecteur3D _re, Vecteur3D _rs, double _Re, double _b)
:ElementDroit(_re, _rs, _Re), scal_b(_b) {}

Quadrupole::~Quadrupole() {}

 Vecteur3D Quadrupole::champMagnetique(Vecteur3D const&) const {
    
 }

ostream& Quadrupole::affiche(ostream& sortie) const {
    return sortie<<"Quadrupole :"<<endl<<
    "   entree :"<<vec_re<<endl<<
    "   sortie :"<<vec_rs<<endl<<
    "   rayon de chambre :"<<scal_Re<<endl<<
    "   intensité magnetique :"<<scal_b<<endl;}
 