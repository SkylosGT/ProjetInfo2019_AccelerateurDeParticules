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
	
	double energie_moyenne;//QUE FAIRE? ELLES ONT TOUTES MEME ENERGIE DONC JUSTE PRENDRE L'ENERGIE DE LA PARTICULE DE REF? OU ALORS IL FAUT PRENDRE ENERGIE DE LA PARTICULE AUGMENTÉE? OU FAIRE DES MOYENNES???
	//APRES LES EMITENCES (EN FAIRE 2?) + LES COEF D'ELLIPSE POUR CHACUNE D'ELLES (EN FAIRE 2?, FAIRE EN VECTOR?)
	//CES DERNIERES + ENERGIE A CALCULER DANS LE {} DU CONSTRUCTEUR
	
	
	
	
	public :
	Faisceau(Particule,long int, double, SupportADessin* _support=nullptr);
	
	
};
