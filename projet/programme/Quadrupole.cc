#include "Quadrupole.h"

//DEFINITION DES METHODES DE LA CLASSE QUADRUPOLE ET SURCHARGE DE SES OPERATEURS

//METHODES PUBLIQUES DE LA CLASSE QUADRUPOLE
Quadrupole::Quadrupole(Vecteur3D _re, Vecteur3D _rs, double _Re, double _b)
:ElementDroit(_re, _rs, _Re), scal_b(_b) {}

Quadrupole::~Quadrupole() {}

 Vecteur3D Quadrupole::champMagnetique(Vecteur3D const&) const {
    
 }