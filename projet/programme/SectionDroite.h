/*Hérite : ElementDroit.h*/

#pragma once

#include "ElementDroit.h"
#include "ConstantesPhysiques.h"

//En tête de la classe SectionDroite avec descriptions de ses méthodes. Corps dans "SectionDroite.cc"
class SectionDroite : public ElementDroit {

    public:
        
        //Constructeur de la section droite qui ne peut pas avoir d'élément suivant attaché à lui
        SectionDroite(Vecteur3D, Vecteur3D, double);

        //Destructeur de la section droite
        ~SectionDroite();

    /*Méthodes de l'interface de la classe SectionDroite*/

        //Calcule le champ magnétique de l'élément
        virtual Vecteur3D champMagnetique(Vecteur3D const& _B=ConstantesPhysiques::vec_e3) const override;

        //Affiche une Section Droite
        virtual std::ostream& affiche(std::ostream&) const override;
};

