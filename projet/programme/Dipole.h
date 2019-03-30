/*Hérite : ElementDroit.h*/

#pragma once

#include <iostream>

#include "ElementCourbe.h"

//En tête de la classe Dipole avec descriptions de ses méthodes. Corps dans "Dipole.cc"
class Dipole : public ElementCourbe {
    
    private:
    
    //Attribut spécifique aux Dipôles
        double scal_Bz;//Norme du champ magnétique

    public:

        //Constructeur du Dipole qui ne peut pas avoir d'élément suivant attaché à lui
        Dipole(Vecteur3D, Vecteur3D, double, double, double);

        //Destructeur du Dipole
        ~Dipole();

        //Calcule le champ magnétique de l'élément
        virtual Vecteur3D champMagnetique(Vecteur3D const& _B=ConstantesPhysiques::vec_e3) const override;

        //Affiche un Dipole
        virtual std::ostream& affiche(std::ostream&) const;
};

