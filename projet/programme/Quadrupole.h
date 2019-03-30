#include "ElementDroit.h"
class Quadrupole : public ElementDroit
{
private:
    /* data */
public:
    Quadrupole(/* args */);
    ~Quadrupole();
    virtual Vecteur3D champMagnetique(Vecteur3D const&) const override;
};


