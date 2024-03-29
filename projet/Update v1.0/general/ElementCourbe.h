/*Classe Abstraite*/
/*Hérite : Element.h*/

#pragma once

#include "Element.h"

//En tête de la classe ElementCourbe avec descriptions de ses méthodes. Corps dans "ElementCourbe.cc"
class ElementCourbe : public Element {

    protected:

    /*Attribut spécifique aux éléments courbes*/

        double scal_k;//Rayon de courbure de l'élément courbe

    /*Méthode pour faciliter les calculs dans l'instance*/

        //Calcule la position du centre de courbure de l'élément courbe
        Vecteur3D centreDeCourbure() const;

    public:

        //Accesseur au rayon de courbure d'un element courbe
        double rayonDeCourbure() const {return scal_k;}

        //Constructeur de l'élément Courbe qui ne peut pas avoir d'élément suivant attaché à lui
        ElementCourbe(Vecteur3D, Vecteur3D, double, double, SupportADessin*);

    /*Méthodes de l'interface Element Courbe (redéfinition de méthodes héritées de Element)*/

        //Définit si une particule heurte le bord de l'élément
        virtual bool heurte_bord(Particule const&) const override;
        
        //Calcul un vecteur3D spécifique aux éléments courbes nécesaire aux calculs d'émittances d'un faisceau
        virtual Vecteur3D u(Particule const&) const override;
};

