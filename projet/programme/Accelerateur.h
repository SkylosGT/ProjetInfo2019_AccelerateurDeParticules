#include <iostream>
#include "Dipole.h"
#include "Particule.h"
#include <vector>

//En tête de la classe Accelerateur avec descriptions de ses méthodes. Corps dans "Particule.h"
class Accelerateur {
	
	private : 
 /*Attributs privés de l'accélérateur*/
 
	//Un tableau d'éléments (contenant la collection d'éléments)
		std::vector <Element*> CollectionElement;
		
	//Un tableau de particules (contenant la collection de particules)
		std::vector <Particule> CollectionParticule;
		
	
	public :
	//Constructeur par défauts qui initialise l'accélérateur vide (aucun élément, aucune particule)
		Accelerateur();
		
	//Suppression du constructeur de copie 
		Accelerateur(Accelerateur const&) = delete;
		
	//Suppression de l'opérateur d'affection =
		Accelerateur& operator=(Accelerateur const&) = delete;
	
 /*Méthodes de l'interface de la classe Accélérateur*/
	
	//Affiche chaque éléments et particules de l'instance sur la console de manière ergonomique
		std::ostream& affiche(std::ostream&) const;
		
	//Ajoute une particule dans l'accélérateur (dans sa collection de particules)
		void ajoutParticule(Particule);
	
	//Ajoute un élément dans l'accélérateur (dans sa collection d'éléments)
		void ajoutElement(Element*);
		
	//Supprime tout les éléments de l'accélérateur
		void supprCollectionElement();
		
	//Supprime toutes les particules de l'accélérateur
		void supprCollectionParticule();
	
	//Méthode qui fait évoluer le système
		void evolue() const;
	
};

//Permet l'affichage d'un accélérateur par surcharge
std::ostream& operator<<(std::ostream&, Accelerateur const&);
