/*Hérite : ElementCourbe.h*/

#pragma once

#include "ElementDroit.h"

//En tête de la classe SectionDroite avec descriptions de ses méthodes. Corps dans "SectionDroite.cc"
class SectionDroite : public ElementDroit {

    public:
        
        //Constructeur de la section droite qui ne peut pas avoir d'élément suivant attaché à lui
        SectionDroite(Vecteur3D, Vecteur3D, double, double, double);

        //Destructeur de la section droite
        ~SectionDroite();

        //Calcule le champ magnétique de l'élément
        virtual Vecteur3D champMagnetique(Vecteur3D const&) const override;
};

