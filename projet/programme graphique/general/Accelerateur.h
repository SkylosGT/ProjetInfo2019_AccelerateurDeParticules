#pragma once

#include <iostream>
#include <vector>

#include "Faisceau.h"
#include "Case.h"

//En tête de la classe Accelerateur avec descriptions de ses méthodes. Corps dans "Accelerateur.cc"
class Accelerateur: public Dessinable {
	
	private: 
 
 	/*Attributs privés de l'accélérateur*/

 		std::vector <Element*> CollectionElement;//Un tableau d'éléments (contenant la collection d'éléments)
        std::vector <Faisceau*> CollectionFaisceau;//Un tableau de faisceau (contenant la collection de faisceau)
        std::vector <Case*> CollectionCases;//Un tableau de cases (contenant la collection de cases)

        double angleDeSegmentation;//Angle avec lequel on segmente l'espace de notre accelerateur (centré en (0,0,0))
        double rayon;//Le rayon (la taille de notre accelerateur)
		
	public:

    //Des accesseurs des collections pour que la fonction dessine puisse dessiner chaque élément, faisceau de l'accélérateur
		std::vector<Element*> getCollectionElement() const {return CollectionElement;}

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
	
	//Ajoute un élément dans l'accélérateur (dans sa collection d'éléments)
		void ajoutElement(Element*);
		
	//Supprime tout les éléments de l'accélérateur
		void supprCollectionElement();
	
	//Supprime tous les faisceaux de l'accélérateur
		void supprCollectionFaisceau();

    //Méthode qui construit un accelerateur circulaire d'un certain rayon
        void construireAccelerateur(int);

    //Méthode qui fait évoluer le système avec un pas de temps
		void evolue(double _dt) const;
	
	//Redéfinition de la méthode dessine héritée de la super classe Dessinable qui dessine l'accélérateur sur un support choisi
		virtual void dessine() override
		{ support->dessine(*this); }

    //Méthode qui trouve l'élément dans lequel se trouve une certaine particule
		Element* trouveElementDeLaParticule(Particule const&) const;

    //Méthode qui attache deux éléments entre eux à leur bord
        void attacheElements(Element*, Element*) const;

    //Méthode qui segmente l'espace de l'accelerateuren cases de facon circulaire
        void segmenterEspace(int);

    //Rend la case suivante dans le sens horaire
        int caseSuivante(int) const;

    //La particule passe à la case suivante
        void passeCaseSuivante(Faisceau*) const;
};
