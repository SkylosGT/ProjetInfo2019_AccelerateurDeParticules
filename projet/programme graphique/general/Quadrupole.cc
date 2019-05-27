#include "Quadrupole.h"
#include "ConstantesPhysiques.h"

using namespace std;
using namespace ConstantesPhysiques;

//DEFINITION DES METHODES DE LA CLASSE QUADRUPOLE ET SURCHARGE DE SES OPERATEURS

//METHODES PUBLIQUES DE LA CLASSE QUADRUPOLE
Quadrupole::Quadrupole(Vecteur3D _re, Vecteur3D _rs, double _Re, double _b, SupportADessin* _support)
:ElementDroit(_re, _rs, _Re, _support), scal_b(_b) {}

Quadrupole::~Quadrupole() {}

 Vecteur3D Quadrupole::champMagnetique(Vecteur3D const& _x) const {
    Vecteur3D vec_X(_x-vec_re), vec_d(~(vec_rs-vec_re));
    Vecteur3D vec_y(vec_X-(vec_X*vec_d)*vec_d), vec_u(vec_e3^vec_d);
    return scal_b*((vec_y*vec_u)*vec_e3+(_x.getz()*vec_u));}

ostream& Quadrupole::affiche(ostream& sortie) const {
    return sortie<<"Quadrupole :"<<endl<<
    "   entree :"<<vec_re<<endl<<
    "   sortie :"<<vec_rs<<endl<<
    "   rayon de chambre :"<<scal_Re<<endl<<
    "   intensité magnetique :"<<scal_b<<endl;}
 
