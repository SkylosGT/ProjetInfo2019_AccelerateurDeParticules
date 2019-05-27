#include "Dipole.h"
#include "ConstantesPhysiques.h"

using namespace std;
using namespace ConstantesPhysiques;

//DEFINITION DES METHODES DE LA CLASSE DIPOLE ET SURCHARGE DE SES OPERATEURS

//METHODES PUBLIQUES DE LA CLASSE DIPOLE
Dipole::Dipole(Vecteur3D _re, Vecteur3D _rs, double _Re, double _k, double _Bz, SupportADessin* _support)
:ElementCourbe(_re, _rs, _Re, _k, _support), scal_Bz(_Bz) {}

Dipole::~Dipole() {}

Vecteur3D Dipole::champMagnetique(Vecteur3D const& _B=vec_e3) const {
    return scal_Bz*vec_e3;}

ostream& Dipole::affiche(ostream& sortie) const {
    return sortie<<"Dipole :"<<endl<<
    "   entree :"<<vec_re<<endl<<
    "   sortie :"<<vec_rs<<endl<<
    "   rayon de chambre :"<<scal_Re<<endl<<
    "   rayon de courbure :"<<scal_k<<endl<<
    "   centre de courbure :"<<centreDeCourbure()<<endl<<
    "   champ magnetique :"<<champMagnetique()<<endl<<*elem_suivant<<endl;}

