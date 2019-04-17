#pragma once

#include <vector>
#include <vector>
#include "Dessinable.h"
#include "SupportADesssin.h"

#include "Particule.h"

class Particule;

class Faisceau : public Dessinable {
	
	private : 
	
	Particule reference;
	long int nombre_particule;
	double coef_simulation;
	std::vector<Particule> CollectionParticule;
	double energie_moy;
	
	
	public :
	Faisceau(Particule,long int, double, SupportADessin* _support=nullptr);
	
	void energie_moyenne();//CHANGE EN FONCTION DU TEMPS?? OU UNE CARACTÉRISTIQUE CALCULABLE A L'INITIALISATION D'UN FAISCEAU?
	
    std::ostream& affiche(std::ostream&) const;

	virtual void dessine() override
    { support->dessine(*this); }
    
    void bouger(double);
	
};
