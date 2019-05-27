#ifndef MAILLEFODO_H
#define MAILLEFODO_H
#include "ElementDroit.h"
#include <vector>

class MailleFODO:public ElementDroit{

    private:

    /*Attributs privés d'une Maille Fodo*/

        std::vector<Element*> elements;//Elements contenu dans la maille
        Vecteur3D vec_d;//Vecteur unitaire de la direction de la maille
        double scal_L;//Longueur des sections droites
        double scal_l;//Longueur des quadrupoles
        double scal_b;//Champ magnetique des quadrupoles

    public:

        //Accesseur retourne les elements d'une maille
        std::vector<Element*> getElements() const {return elements;}

        //Constructeur d'une maille fodo qui initialise par défaut le support comme pointant sur rien
        MailleFODO(Vecteur3D, Vecteur3D, double, double, double, SupportADessin* _support=nullptr);

/*Méthodes publiques de l'interface de la classe Faisceau circulaire*/

        //Trouve l'element dans lequel la particule se situe
        Element* trouveElementDeLaMaille(Vecteur3D const&) const;

        //Donne le champs magnetique de la maille en fonction de la position
        virtual Vecteur3D champMagnetique(Vecteur3D const&) const override;

        //Affiche la maille sur la console
        virtual std::ostream& affiche(std::ostream&) const;

        //Change le support d'une maille fodo et de tous ses elements
        virtual void change_support(SupportADessin* nouveau) override;

        //Dessine la maille fodo en fonction de son support
        virtual void dessine() override
        { support->dessine(*this); }
};

#endif // MAILLEFODO_H
