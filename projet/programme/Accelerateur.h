#pragma once
#include <iostream>
#include "ElementCourbe.h"
#include "ElementDroit.h"
#include "Dipole.h"
#include "Particule.h"
#include <vector>

//En tête de la classe Accelerateur avec descriptions de ses méthodes. Corps dans "Particule.h"
class Accelerateur {
	
	private : 
	//Une structure contenant tout les éléments d'un accélérateur de particule sous forme de tableaux (Elements droits, courbes et les dipôles)
		struc CollectionElement {
			vector <ElementCourbe> CollectionElementCourbe;
			vector <ElementDroit> CollectionElementDroit;
			vector <Dipole> CollectionDipole; };
	
	//Un tableau de particules (pas besoin de structure car les particules n'ont pas de sous-classes, de spécificationss)
		vector <Particule> CollectionParticule;
		
	
	public :
		Accelerateur();
		
		vector getCollectionElement() const;
		vector getCollectionParticule() const;
		
		std::ostream& affiche(std::ostream&) const;
	
};
