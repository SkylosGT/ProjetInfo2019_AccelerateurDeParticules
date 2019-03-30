#include "ElementDroit.h"

class SectionDroite : public ElementDroit
{
private:
    /* data */
public:
    SectionDroite(/* args */);
    ~SectionDroite();
    virtual Vecteur3D champMagnetique(Vecteur3D const&) const override;
};

