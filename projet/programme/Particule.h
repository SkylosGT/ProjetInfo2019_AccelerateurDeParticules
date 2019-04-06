#pragma once

#include "Vecteur3D.h"
#include "Element.h"

#include "Dessinable.h"
#include "SupportADessin.h"

class Element;

//En tête de la classe Particule avec descriptions de ses méthodes. Corps dans "Particule.cc"

class Particule : public Dessinable {
  
  private:
  
  //Attributs physiques d'une particule
    Vecteur3D vec_r; //Position de la particule 
    Vecteur3D vec_v; //Vitesse de la particule
    double scal_m; //Masse de la particule
    double scal_q; //Charge de la particule
    Vecteur3D vec_f; //Force appliquée sur la particule
    Element* elem_courant; //Elément courant dans lequel se trouve la particule

  /*Méthodes pour faciliter les calculs des attributs de l'instance*/

    //Transforme une masse donnée en GeV/c^2 en kg
    double transformMassGeVToKg();

    //Calcule l'angle de déviation de la force 
    double calculateDeviationAngle(double);

  public:

    //Getter, retourne la position de la particule
    Vecteur3D position() const {return vec_r;};

    //Constructeur par vecteur quantité de mouvement en GeV
    Particule(Vecteur3D, Vecteur3D, double, double, SupportADessin* _support=nullptr ,Element* _courant=nullptr);

    //Constructeur par energie en GeV et direction vectorielle
    Particule(Vecteur3D, Vecteur3D, double, double, double, SupportADessin* _support=nullptr ,Element* _courant=nullptr);

  /*Méthodes de l'interface de la classe particule*/

    //Calcule l'énergie de la particule en tout temps en fonction de sa vitesse et de sa masse
    double Energie() const;

    //Calcule le facteur gamma de la particule en fonciton de sa vitesse
    double FacteurGamma() const;

    //Ajoute une force s'appliquant sur la particule et effectue une rotation sur celle la
    void ajouteForceMagnetique(Vecteur3D, double);

    //Déplace la particule et modifie sa vitesse en fonction des attributs de l'instance courante et du pas de temps définit
    void bouger(double);

    //Affiche les attributs de l'instance sur la console de manière ergonomique
    std::ostream& affiche(std::ostream&) const;

    //La particule change d'élément
    void change_element(Element*);

    virtual void dessine() override
    { support->dessine(*this); }
};

/*OPERATEURS EXTERNES*/

//Permet l'affichage d'une Particule par surcharge
std::ostream& operator<<(std::ostream&, Particule const&);