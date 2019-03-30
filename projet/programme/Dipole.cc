#include "Dipole.h"

using namespace std;

//DEFINITION DES METHODES DE LA CLASSE DIPOLE ET SURCHARGE DE SES OPERATEURS

//METHODES PUBLIQUES DE LA CLASSE DIPOLE
Dipole::Dipole(Vecteur3D _re, Vecteur3D _rs, double _Re, double _k, double _Bz)
:ElementCourbe(_re, _rs, _Re, _k), scal_Bz(_Bz) {}

Dipole::~Dipole() {}

Vecteur3D Dipole::champMagnetique(Vecteur3D const& _B) const {
    return scal_Bz*_B;}

ostream& Dipole::affiche(ostream& sortie) const {
    return sortie<<"Dipole :"<<endl<<
    "   entree :"<<vec_re<<endl<<
    "   sortie :"<<vec_rs<<endl<<
    "   rayon de chambre :"<<scal_Re<<endl<<
    "   rayon de courbure :"<<scal_k<<endl<<
    "   centre de courbure :"<<centreDeCourbure()<<endl<<
    "   champ magnetique :"<<scal_Bz<<endl;}