#include "SectionDroite.h"
#include "ConstantesPhysiques.h"

using namespace std;
using namespace ConstantesPhysiques;

//DEFINITION DES METHODES DE LA CLASSE SECTION DROITE ET SURCHARGE DE SES OPERATEURS

//METHODES PUBLIQUES DE LA CLASSE SECTION DROITE
SectionDroite::SectionDroite(Vecteur3D _re, Vecteur3D _rs, double _Re, SupportADessin* _support)
:ElementDroit(_re, _rs, _Re, _support) {}

SectionDroite::~SectionDroite() {}

Vecteur3D SectionDroite::champMagnetique(Vecteur3D const& _B=vec_e3) const{
    return (*new Vecteur3D);}

ostream& SectionDroite::affiche(ostream& sortie) const {
    return sortie<<"Section Droite :"<<endl<<
    "   entree :"<<vec_re<<endl<<
    "   sortie :"<<vec_rs<<endl<<
    "   rayon de chambre :"<<scal_Re<<endl;}
