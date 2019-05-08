/*Classe abstraite*/

#pragma once

#include "Particule.h"

#include "Dessinable.h"
#include "SupportADessin.h"

class Particule;

//En tête de la classe Element avec descriptions de ses méthodes. Corps dans "Element.cc"
class Element : public Dessinable{
    protected:
    
    //Attributs d'un élément de l'accélérateur
        Vecteur3D vec_re;//Position d'entrée de l'élément
        Vecteur3D vec_rs;//Position de sortie de l'élément
        double scal_Re;//Rayon de la chambre à vide        
        Element* elem_suivant;//Pointeur vers l'élément suivant celui-ci dans l'accélérateur

    public:

        //Getter, retourne l'élément suivant l'élément courant
        Element* elemSuivant() const{return elem_suivant;}
        Vecteur3D entree() const{return vec_re;}
        Vecteur3D sortie() const{return vec_rs;}
    
        //Constructeur d'un élément qui ne pointe par défault vers aucun élément suivant
        Element(Vecteur3D, Vecteur3D, double, SupportADessin*, Element* _suivant=nullptr);

        //Déstructeur de l'élément
        virtual ~Element();

    /*Méthodes virtuelles pures de la classe Element*/

        //Sera substituée pour calculer le champs magnétique de l'élément
        virtual Vecteur3D champMagnetique(Vecteur3D const&) const=0;

        //Sera substituée pour définir si une particule heurte le bord de l'élément
        virtual bool heurte_bord(Particule const&) const=0;

        //Sera subsistuée pour afficher un élément
        virtual std::ostream& affiche(std::ostream&) const=0;
        
        //Sera substitué afin de calculer en fonction de l'élément courant d'une particule un vecteur3D u utile aux calculs d'émittance d'un faisceau
        virtual Vecteur3D u(Particule const&) const=0;
    
    /*Méthodes de l'interface de la classe Element*/

        //Définit si une particule passe à l'élément suivant
        bool passe_au_suivant(Particule const&) const;

        //Attache un élément suivant à l'instance courante
        void attache_element_suivant(Element*);

        double distance_particule(Particule const&) const;
};

/*OPERATEURS EXTERNES*/

//Permet l'affichage d'un Element par surcharge
std::ostream& operator<<(std::ostream&, Element const&);
