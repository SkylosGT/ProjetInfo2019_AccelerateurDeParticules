#include "ElementCourbe.h"
#include "Vecteur3D.h"

class Dipole : public ElementCourbe
{
private:
    double scal_Bz;

public:
    Dipole(Vecteur3D, Vecteur3D, double, Element const&, double, double);
    ~Dipole();
    virtual Vecteur3D champMagnetique(Vecteur3D const&) const override;
};

