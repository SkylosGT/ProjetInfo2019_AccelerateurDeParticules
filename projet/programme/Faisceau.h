#pragma once

#include <vector>
#include "Dessinable.h"
#include "SupportADessin.h"

#include "Vecteur3D.h"

#include "Particule.h"

class Particule;

class Faisceau : public Dessinable {
	
	protected : 
	
	Particule reference;
	long int nombre_particule;
	double coef_simulation;
	std::vector<Particule*> CollectionPart;
	double energie_moy;
	
	double emit_verticale;
	double coef_A11_vert;
	double coef_A12_vert;
	double coef_A22_vert;
	
	double emit_horizontale;
	double coef_A11_hori;
	double coef_A12_hori;
	double coef_A22_hori;
	
	
	public:
	Faisceau(Particule,long int, double, SupportADessin* _support=nullptr);
	
	std::vector<Particule*> getCollectionPart() const {return CollectionPart;}

	Particule particuleDeReference() const {return reference;}
	
	void energie_moyenne();
	
	virtual std::ostream& affiche(std::ostream&) const =0;
    
    virtual void bouger(double) = 0;
    
    void calcul_ell_vert(); 
    
    void calcul_ell_hori();

	void changerElementDeLaParticuleDeReference(Element*);
	
};
