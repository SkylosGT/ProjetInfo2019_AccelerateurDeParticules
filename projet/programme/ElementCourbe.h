/*Classe Abstraite*/
/*Hérite : Element.h*/

#pragma once

#include "Element.h"

//En tête de la classe ElementCourbe avec descriptions de ses méthodes. Corps dans "ElementCourbe.cc"
class ElementCourbe : public Element {

    protected:

    //Attribut spécifique aux éléments courbes
        double scal_k;//Rayon de courbure de l'élément courbe

    /*Méthode pour faciliter les calculs dans l'instance*/

        //Calcule la position du centre de courbure de l'élément courbe
        Vecteur3D centreDeCourbure() const;

    public:

        //Constructeur de l'élément Courbe qui ne peut pas avoir d'élément suivant attaché à lui
        ElementCourbe(Vecteur3D, Vecteur3D, double, double, SupportADessin*);

        //Destructeur d'un élément Courbe
        ~ElementCourbe();

    /*Méthodes de l'interface Element Courbe*/

        //Définit si une particule heurte le bord de l'élément
        virtual bool heurte_bord(Particule const&) const override;
};

