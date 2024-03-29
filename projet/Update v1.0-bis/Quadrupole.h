/*Hérite : ElementDroit.h*/

#pragma once

#include "ElementDroit.h"

//En tête de la classe Quadrupole avec descriptions de ses méthodes. Corps dans "Quadrupole.cc"
class Quadrupole : public ElementDroit {
    
    private:
    
    /*Attribut spécifique au quadrupole*/

        double scal_b; //Intensité du champ magnétique

    public:

        //Constructeur du Quadrupole qui ne peut pas avoir d'élément suivant attaché à lui
        Quadrupole(Vecteur3D, Vecteur3D, double, double, SupportADessin* _support=nullptr);

    /*Méthodes de l'interface de la classe SectionDroite*/

        //Calcule le champ magnétique de l'élément
        virtual Vecteur3D champMagnetique(Vecteur3D const&) const override;

        //Affiche un Quadrupole
        virtual std::ostream& affiche(std::ostream&) const override;

        //Dessine un quadrupole en fonction de son support
        virtual void dessine() override
        { support->dessine(*this); }
};


