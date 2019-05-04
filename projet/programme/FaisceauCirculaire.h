#pragma once

#include "Faisceau.h"

class FaisceauCirculaire : public Faisceau {
	
	public : 
	
	FaisceauCirculaire(Particule,long int, double, SupportADessin* _support=nullptr);
	
	virtual void bouger(double) override;
	
	std::ostream& affiche(std::ostream&) const;
	
	virtual void dessine() override
    { support->dessine(*this); }
	
};

