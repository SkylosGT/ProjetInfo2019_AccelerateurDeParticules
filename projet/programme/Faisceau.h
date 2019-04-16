#pragma once

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
	
	double energie_moyenne;
	//APRES LES EMITENCES (EN FAIRE 2?) + LES COEF D'ELLIPSE POUR CHACUNE D'ELLES (EN FAIRE 2?, FAIRE EN VECTOR?)
	//CES DERNIERES + ENERGIE A CALCULER DANS LE {} DU CONSTRUCTEUR
	
	
	
	
	public :
	Faisceau(Particule,long int, double, SupportADessin* _support=nullptr);
	
	
};
