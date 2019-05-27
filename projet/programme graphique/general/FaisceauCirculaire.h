/*Hérite : Faisceau.h*/

#pragma once

#include "Faisceau.h"
#include "Particule.h"

//En tête de la sous classe FaisceauCirculaire de Faisceau avec descriptions de ses méthodes. Corps dans "FaisceauCiruclaire.cc"
class FaisceauCirculaire : public Faisceau {

    private:

    /*Attributs privés d'un faisceau circulaire*/

        double dt_lancement;//Pas de temps de lancement d'une particule
        double chronometre; //Compteur chronomètre de lancement
	
	public : 
	
	//Constructeur d'un faisceau circulaire qui initialise par défaut le support comme pointant sur rien
        FaisceauCirculaire(Particule,long int, double, double dt_lancement=5e-9, SupportADessin* _support=nullptr);

/*Méthodes publiques de l'interface de la classe Faisceau circulaire*/

	//Redéfinition de la méthode virtuelle pure bouger de Faisceau qui fait bouger chaque particule du faisceau et qui en ajoute une si le nombre de particule voulu dans le faisceau n'est pas atteint
        virtual void bouger(double) override;
	
	//Redéfinition de la méthode virtuelle pure affiche qui permet de dessiner sur une console un faisceau
        virtual std::ostream& affiche(std::ostream&) const override;
	
	//Redéfinition de la méthode dessine héritée de la super classe Dessinable qui dessine l'accélérateur sur un support choisi
        virtual void dessine() override
        { support->dessine(*this); }

    //Redéfinition de la methode qui lance une particule
        virtual void lanceParticule() override;
};

