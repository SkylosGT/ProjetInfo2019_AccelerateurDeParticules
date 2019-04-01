#include "SectionDroite.h"

using namespace std;

//DEFINITION DES METHODES DE LA CLASSE SECTION DROITE ET SURCHARGE DE SES OPERATEURS

//METHODES PUBLIQUES DE LA CLASSE SECTION DROITE
SectionDroite::SectionDroite(Vecteur3D _re, Vecteur3D _rs, double _Re)
:ElementDroit(_re, _rs, _Re) {}

SectionDroite::~SectionDroite() {}

Vecteur3D SectionDroite::champMagnetique(Vecteur3D const& _B) const{
    return 0*_B;}

ostream& SectionDroite::affiche(ostream& sortie) const {
    return sortie<<"Section Droite :"<<endl<<
    "   entree :"<<vec_re<<endl<<
    "   sortie :"<<vec_rs<<endl<<
    "   rayon de chambre :"<<scal_Re<<endl;}
