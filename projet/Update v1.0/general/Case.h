#pragma once

#include "Particule.h"
#include <vector>

//En tête de la classe Case avec descriptions de ses méthodes. Corps dans "Case.cc"
class Case {

    private:

/*Attributs privés de la case*/

        std::vector<Particule*> particules;//Particules dans une case

        int positionDeLaCase;//Position de la case dans le tableau
        double rayon;//Rayon de l'accelerateur
        double angle;//Angle de segmentation

    public:

    //Constructeur qui initialise une case avec sa position angulaire (rayon, angle et place)
        Case(int, double, double);

/*Méthodes de l'interface de la classe Case*/

    //Rend la position d'entrée de la case
        Vecteur3D& entreeDeLaCase();

    //Rend la position de sortie de la case
        Vecteur3D& sortieDeLaCase();

    //Ajoute une particule à la case
        void ajouteParticule(Particule*);

    //Enleve une particule de la case
        void enleveParticule(Particule*);

    //Verifie si une particule est dans la case
        bool particuleCollider(Particule const&);

    //Rend un tableau de particules assez proche pour intéragir
        std::vector<Particule*> paticulesQuiInteragissent(Case*, Case*);
};

