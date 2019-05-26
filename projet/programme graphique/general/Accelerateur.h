#pragma once

#include <iostream>
#include <vector>

//#include "Element.h"
#include "Faisceau.h"
#include "case.h"


//En tête de la classe Accelerateur avec descriptions de ses méthodes. Corps dans "Accelerateur.h"
class Accelerateur: public Dessinable {
	
	private: 
 
 	/*Attributs privés de l'accélérateur*/
 		std::vector <Element*> CollectionElement;//Un tableau d'éléments (contenant la collection d'éléments)
 		std::vector <Particule*> CollectionParticule;//Un tableau de particule (contenant collection de particule)
		std::vector <Faisceau*> CollectionFaisceau;//Un tableau de faisceau (contenant collection de faisceau)
        std::vector <Case*> CollectionCases;

        double angleDeSegmentation;
        double rayon;
		
	public:
	//Des accesseurs des collections pour que la fonction dessine puisse dessiner chaque élément, faisceau (et particule) de l'accélérateur
		std::vector<Element*> getCollectionElement() const {return CollectionElement;}
		
		std::vector<Particule*> getCollectionParticule() const {return CollectionParticule;}

		std::vector<Faisceau*> getCollectionFaisceau() const {return CollectionFaisceau;}

	//Constructeur par défauts qui initialise l'accélérateur vide (aucun élément, aucune particule)
		Accelerateur(SupportADessin* _support=nullptr);
		
	//Suppression du constructeur de copie 
		Accelerateur(Accelerateur const&) = delete;
		
	//Suppression de l'opérateur d'affection =
		Accelerateur& operator=(Accelerateur const&) = delete;
	
 /*Méthodes de l'interface de la classe Accélérateur*/
	
	//Ajoute un faisceau dans l'accélérateur (dans sa collection de faisceaux)
		void ajoutFaisceau(Faisceau*);
		
	//Ajoute une particule dans l'accélérateur (dans sa collection de particules)
		void ajoutParticule(Particule*);
	
	//Ajoute un élément dans l'accélérateur (dans sa collection d'éléments)
		void ajoutElement(Element*);
		
	//Supprime tout les éléments de l'accélérateur
		void supprCollectionElement();
		
	//Supprime toutes les particules de l'accélérateur
		void supprCollectionParticule();
	
	//Supprime tous les faisceaux de l'accélérateur
		void supprCollectionFaisceau();
	
	//Méthode qui fait évoluer le système avec un pas de temps
		void evolue(double _dt) const;
	
	//Redéfinition de la méthode dessine héritée de la super classe Dessinable qui dessine l'accélérateur sur un support choisi
		virtual void dessine() override
		{ support->dessine(*this); }

	//Méthode qui trouve l'élément courant dans lequel se trouve une certaine particule
		Element* trouveElementDeLaParticule(Particule const&) const;

        void attacheElements(Element*, Element*);

        void construireAccelerateur(int);

        void segmenterEspace(int);

        /*//Affiche chaque éléments et particules de l'instance sur la console de manière ergonomique
		std::ostream& affiche(std::ostream&) const;*/
};

/*//Permet l'affichage d'un accélérateur par surcharge
std::ostream& operator<<(std::ostream&, Accelerateur const&);*/
