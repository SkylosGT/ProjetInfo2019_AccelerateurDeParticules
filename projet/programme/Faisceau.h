#pragma once

#include <vector>

#include "Dessinable.h"
#include "SupportADesssin.h"

#include "Particule.h"

class Particule;

class Faisceau : public Dessinable {
	
	private : 
	
	Particule reference;//LA POSITION DU VECTEUR DE REF INDIQUE LE POINT D'INJECTION 
	long int nombre_particule;
	double coef_simulation;
	std::vector<Particule> CollectionParticule;
	
	//APRES LES EMITENCES (EN FAIRE 2?) + LES COEF D'ELLIPSE POUR CHACUNE D'ELLES (EN FAIRE 2?, FAIRE EN VECTOR?)
	//CES DERNIERES + ENERGIE A CALCULER DANS LE {} DU CONSTRUCTEUR
	
	
	
	
	public :
	Faisceau(Particule,long int, double, SupportADessin* _support=nullptr);
	
	double energie_moyenne() const;//CHANGE EN FONCTION DU TEMPS?? OU UNE CARACTÉRISTIQUE CALCULABLE A L'INITIALISATION D'UN FAISCEAU?
	
    std::ostream& affiche(std::ostream&) const;

	virtual void dessine() override
    { support->dessine(*this); }
    
    void bouger(double); //MAIS ELLES VONT TOUTE ALLER AU MEME ENDROIT?
	
};
