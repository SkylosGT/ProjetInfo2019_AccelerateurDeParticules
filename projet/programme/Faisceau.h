#pragma once

#include <vector>
#include "Dessinable.h"
#include "SupportADesssin.h"

#include "Vecteur3D.h"

#include "Particule.h"

class Particule;

class Faisceau : public Dessinable {
	
	private : 
	
	Particule reference;
	long int nombre_particule;
	double coef_simulation;
	std::vector<Particule> CollectionParticule;
	double energie_moy;
	
	double emit_vert;
	std::vector<double> coef_elipse_vert;
	
	double emit_horizontale;
	std::vector<double> coef_elipse_hori;
	
	
	public :
	Faisceau(Particule,long int, double, SupportADessin* _support=nullptr);
	
	void energie_moyenne();
	
    std::ostream& affiche(std::ostream&) const;

	virtual void dessine() override
    { support->dessine(*this); }
    
    void bouger(double);
    
    void calcul_ell_vert(); //VA CALCULER AUSSI LES COEF
    
    void calcul_ell_hori();
    
	
};
