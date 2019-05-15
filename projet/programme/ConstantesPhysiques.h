#include <cmath>

#include "Vecteur3D.h"

//On définit quelques constantes de Physiques utilisées dans de nombreux calculs
namespace ConstantesPhysiques {
    const double const_c(299792458); //Scalaire constant vitesse de la lumière dans le vide
    const double const_e(1.60217653e-19); //Scalaire constant charge d'un électron
    const double const_e0(8.85e-12); //Scalaire de la permitivité du vide

    const Vecteur3D vec_e1(1,0,0), vec_e2(0,1,0), vec_e3(0,0,1); //Vecteurs constants base cartésienne orthonormée
    
}
