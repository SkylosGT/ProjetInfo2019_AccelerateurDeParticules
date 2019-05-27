#ifndef MAILLEFODO_H
#define MAILLEFODO_H
#include "ElementDroit.h"
#include <vector>

class MailleFODO:public ElementDroit{
protected:

private:
    std::vector<Element*> elements;
    Vecteur3D vec_d;
    double scal_L;
    double scal_b;

public:
    MailleFODO(Vecteur3D, Vecteur3D, double, double, double, SupportADessin* _support=nullptr);

    double longueurQuadrupole();
    std::vector<Element*> getElements() const {return elements;}
    Element* trouveElementDeLaMaille(Vecteur3D const&) const;
    virtual Vecteur3D champMagnetique(Vecteur3D const&) const override;
    virtual std::ostream& affiche(std::ostream&) const;
    virtual void change_support(SupportADessin* nouveau) override;
    virtual void dessine() override
    { support->dessine(*this); }
};

#endif // MAILLEFODO_H
