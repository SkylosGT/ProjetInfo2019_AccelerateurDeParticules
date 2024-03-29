/*Hérite : ElementDroit.h*/

#pragma once

#include "ElementCourbe.h"

//En tête de la classe Dipole avec descriptions de ses méthodes. Corps dans "Dipole.cc"
class Dipole : public ElementCourbe {
    
    private:
    
    //Attribut spécifique aux Dipôles

        double scal_Bz;//Norme du champ magnétique

    public:

        //Constructeur du Dipole qui ne peut pas avoir d'élément suivant attaché à lui
        Dipole(Vecteur3D, Vecteur3D, double, double, double, SupportADessin* _support=nullptr);

    /*Méthodes de l'interface de la classe Dipole*/

        //Calcule le champ magnétique de l'élément
        virtual Vecteur3D champMagnetique(Vecteur3D const&) const override;
  
        //Affiche un Dipole
        virtual std::ostream& affiche(std::ostream&) const override;

        //Méthode dessine en fonction du support du dessinable
        virtual void dessine() override
        { support->dessine(*this); }
};

