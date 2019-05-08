#pragma once

#include "Faisceau.h"
#include "Particule.h"

//En tête de la sous classe FaisceauCirculaire de Faisceau avec descriptions de ses méthodes. Corps dans "FaisceauCiruclaire.h"
class FaisceauCirculaire : public Faisceau {

    private:
        double dt_lancement;
        double tmp;
	
	public : 
	
	//Constructeur d'un faisceau circulaire qui initialise par défaut le support comme pointant sur rien
    FaisceauCirculaire(Particule,long int, double, double dt_lancement=0.000000005, SupportADessin* _support=nullptr);
	
	//Redéfinition de la méthode virtuelle pure bouger de Faisceau qui fait bouger chaque particule du faisceau et qui en ajoute une 
	//si le nombre de particule voulu dans le faisceau n'est pas atteint
	virtual void bouger(double) override;
	
	//Redéfinition de la méthode virtuelle pure affiche qui permet de dessiner sur une console un faisceau
	virtual std::ostream& affiche(std::ostream&) const override;
	
	//Redéfinition de la méthode dessine héritée de la super classe Dessinable qui dessine l'accélérateur sur un support choisi
	virtual void dessine() override
    { support->dessine(*this); }

    virtual void lanceParticule(double) override;
	
};

