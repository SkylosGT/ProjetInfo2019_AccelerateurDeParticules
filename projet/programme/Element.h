/*Classe abstraite*/

#pragma once

#include <iostream>

#include "Vecteur3D.h"
#include "Particule.h"

//En tête de la classe Element avec descriptions de ses méthodes. Corps dans "Element.cc"
class Element {
    protected:
    
    //Attributs d'un élément de l'accélérateur
        Vecteur3D vec_re;//Position d'entrée de l'élément
        Vecteur3D vec_rs;//Position de sortie de l'élément
        double scal_Re;//Rayon de la chambre à vide        
        Element* elem_suivant;//Pointeur vers l'élément suivant celui-ci dans l'accélérateur

    public:
    
        //Constructeur d'un élément qui ne pointe par défault vers aucun élément suivant
        Element(Vecteur3D, Vecteur3D, double, Element* _suivant=nullptr);

        //Déstructeur de l'élément
        ~Element();

    /*Méthodes virtuelles pures de la classe Element*/

        //Sera substituée pour calculer le champs magnétique de l'élément
        virtual Vecteur3D champMagnetique(Vecteur3D const&) const=0;

        //Sera substituée pour définir si une particule heurte le bord de l'élément
        virtual bool heurte_bord(Particule const&) const=0;

        //Sera subsistuée pour afficher un élément
        virtual std::ostream& affiche(std::ostream&) const=0;
    
    /*Méthodes de l'interface de la classe Element*/

        //Définit si une particule passe à l'élément suivant
        bool passe_au_suivant(Particule const&) const;

        //Attache un élément suivant à l'instance courante
        void attache_element_suivant(Element*);
};

