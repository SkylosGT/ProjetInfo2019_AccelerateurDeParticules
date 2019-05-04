#pragma once

#include "Faisceau.h"
#include "Particule.h"
#include "SupportADessin.h"
#include "Dessinable.h"

class FaisceauCirculaire : public Faisceau {
	
	public : 
	
	FaisceauCirculaire(Particule,long int, double, SupportADessin* _support=nullptr);
	
	virtual void bouger(double) override;
	
	virtual std::ostream& affiche(std::ostream&) const override;
	
	virtual void dessine() override
    { support->dessine(*this); }
	
};

