#include <iostream>
#include "Dipole.h"
#include "Particule.h"
#include <vector>

//En tête de la classe Accelerateur avec descriptions de ses méthodes. Corps dans "Particule.h"
class Accelerateur {
	
	private : 
	//Un tableau d'éléments
		std::vector <Element> CollectionElement;
	//Un tableau de particules 
		std::vector <Particule> CollectionParticule;
		
	
	public :
		Accelerateur();
		
		Accelerateur(Accelerateur const&) = delete;
		
		Accelerateur& operator=(Accelerateur const&) = delete;
		
		std::ostream& affiche(std::ostream&) const;
	
};
