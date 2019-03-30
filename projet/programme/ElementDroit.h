/*Classe Abstraite*/
/*Hérite : Element.h*/

#pragma once

#include "Element.h"

//En tête de la classe ElementDroit avec descriptions de ses méthodes. Corps dans "ElementDroit.cc"
class ElementDroit: public Element {

public:

    //Constructeur d'un élément droit
    ElementDroit(Vecteur3D, Vecteur3D, double);
    ~ElementDroit();
    virtual bool heurte_bord(Particule const&) const override;
};


