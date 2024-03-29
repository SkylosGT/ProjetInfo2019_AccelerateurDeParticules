/*Classe Abstraite*/
/*Hérite : Element.h*/

#pragma once

#include "Element.h"

//En tête de la classe ElementDroit avec descriptions de ses méthodes. Corps dans "ElementDroit.cc"
class ElementDroit: public Element {

    public:

        //Constructeur de l'élément droit qui ne peut pas avoir d'élément suivant attaché à lui
        ElementDroit(Vecteur3D, Vecteur3D, double, SupportADessin*);

    /*Méthodes de l'interface Element Droit (redéfinition de méthode héritées de Element)*/

        //Définit si une particule heurte le bord de l'élément
        virtual bool heurte_bord(Particule const&) const override;
        
        //Calcul un vecteur3D spécifique aux éléments droits nécesaire aux calculs d'émittances d'un faisceau
        virtual Vecteur3D u(Particule const&) const override;
};


