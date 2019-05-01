#pragma once

#include <vector>
#include "Dessinable.h"
#include "SupportADessin.h"

#include "Vecteur3D.h"

#include "Particule.h"

class Particule;

class Faisceau : public Dessinable {
	
	private: 
	
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

	Particule particuleDeReference() const {return reference;}
	
	void energie_moyenne();
	
    std::ostream& affiche(std::ostream&) const;

	virtual void dessine() override
    { support->dessine(*this); }
    
    void bouger(double);
    
    void calcul_ell_vert(); 
    
    void calcul_ell_hori();

	void changerElementDeLaParticuleDeReference(Element*);
	
};
