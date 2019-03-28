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
	//Constructeur par défauts
		Accelerateur();
	//Suppression du constructeur de copie 
		Accelerateur(Accelerateur const&) = delete;
	//Suppression de l'opérateur d'affection =
		Accelerateur& operator=(Accelerateur const&) = delete;
		
		std::ostream& affiche(std::ostream&) const;
		
		void ajoutParticule(Particule);
		
		void ajoutElement(Element);
		
		void supprCollectionElement();
		
		void supprCollectionParticule();
		
		void evolue() const;
	
};

std::ostream& operator<<(std::ostream&, Accelerateur const&);
