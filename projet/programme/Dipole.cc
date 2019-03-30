#include "Dipole.h"
#include "ConstantesPhysiques.h"

using namespace ConstantesPhysiques;
using namespace std;

Dipole::Dipole(Vecteur3D _re, Vecteur3D _rs, double _Re, Element const& _suivant, double _k, double _Bz)
:ElementCourbe(_re, _rs, _Re, _suivant, _k), scal_Bz(_Bz) {}

Dipole::~Dipole()
{}

Vecteur3D Dipole::champMagnetique() const {
    return scal_Bz*vec_e3;}
    
void Dipole::affiche() const{
	cout<<"Test dipole"<<endl;}
