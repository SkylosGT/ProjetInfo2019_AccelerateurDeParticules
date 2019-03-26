#include "Dipole.h"
#include "ConstantesPhysiques.h"

using namespace ConstantesPhysiques;


Dipole::Dipole(Vecteur3D _re, Vecteur3D _rs, double _Re, Element const& _suivant, double _k, double _Bz)
:ElementCourbe(_re, _rs, _Re, _suivant, _k), scal_Bz(_Bz) {}

Dipole::~Dipole()
{}

Vecteur3D Dipole::champMagnetique(Vecteur3D const& _r) const {
    return scal_Bz*_r;
}