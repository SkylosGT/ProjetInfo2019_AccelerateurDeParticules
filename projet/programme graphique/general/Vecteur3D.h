#pragma once

#include <iostream>

//En tête de la classe Vecteur3D avec descriptions de ses méthodes. Corps dans "Vecteur3D.cc"
class Vecteur3D {
	
	private: 
	
	//Description du vecteur en 3 coordonnées cartésiennes
		double scal_x;	//Composante sur X
		double scal_y;	//Composante sur Y
		double scal_z; 	//Composante sur Z
	
	/*Méthode utilisée par les opérateurs internes de comparaison*/

		//Méthode qui compare deux vecteurs et return true si l'instance courante et l'autre vecteur3D sont égaux (même coordonnées)
		bool compare(Vecteur3D const&) const;
	
	public:

	//Getter pour les coordonnées scal_x,scal_y,scal_z
        double getx() const {return scal_x;}
        double gety() const {return scal_y;}
        double getz() const {return scal_z;}
	
	//Constructeur pour initialiser un Vecteur3D (avec initialisation par défaut au vecteur nul)
		Vecteur3D (double scal_x=0.0, double scal_y=0.0, double scal_z=0.0);
	
	/*OPERATEURS INTERNES*/

		//Teste l'égalité de l'instance courante avec un autre Veteur3D (retourne true si il scal_y a égalité)
		bool operator==(Vecteur3D const&) const;

		//Teste l'égalité de l'instance courante avec un autre vecteur3D (retourne true si n'scal_y a pas égalité)
		bool operator!=(Vecteur3D const&) const; 

		//Retourne l'opposé de l'instance courante
		const Vecteur3D operator-() const;

		//Retourne le vecteur unitaire associé à l'instance courante
		const Vecteur3D operator~() const; 
		
		//Retourne dans l'instance courante l'addition de celle-ci avec un autre Vecteur3D
		Vecteur3D& operator+=(Vecteur3D const&);
		
		//Retourne dans l'instance courante la soustraction de celle-ci avec un autre Vecteur3D
		Vecteur3D& operator-=(Vecteur3D const&); 
		
		//Retourne dans l'instance courante la multiplication de celle-ci avec un scalaire
		Vecteur3D& operator*=(double const);
		
		//Retourne dans l'instance courante le produit vectoriel de celle-ci avec un autre Vecteur3D
		Vecteur3D& operator^=(Vecteur3D const&); 
		
	/*Méthodes utilisées pas les opérateurs externes à la classe Vecteur3D*/

		//Permet l'affichage des 3 coordonnées du vecteur3D en instance courante
		std::ostream& affiche(std::ostream&) const;

		//Renvoie le produit scalaire de l'instance courante avec un autre vecteur3D
		double prod_scal(Vecteur3D const&) const; 
	
	/*Autres méthodes de l'interface de la classe Vecteur3D*/

		//Méthode qui retourne la norme de l'instance courante
		double norme() const; 
		
		//Méthode qui retourne la norme au carré de l'instance courante	
		double norme2() const;
		
		// Méthode qui fait la rotation de l'instance courante autour d'un axe (vecteur unitaire passé en argument) d'un angle en radiant passé aussi en argument
        Vecteur3D& rotation(Vecteur3D const&, double);

};

/*OPERATEURS EXTERNES*/

//Permet l'affichage d'un Vecteur3D (affiche ces 3 coordonnées)
std::ostream& operator<<(std::ostream&, Vecteur3D const&);

//Additione deux vecteurs 3D
const Vecteur3D operator+(Vecteur3D, Vecteur3D const&);

//Soustrait deux vecteurs 3D
const Vecteur3D operator-(Vecteur3D, Vecteur3D const&);

//Multiplie un vecteur3D par un scalaire
const Vecteur3D operator*(Vecteur3D, double);

//Multiplie un vecteur3D par un scalaire
const Vecteur3D operator*(double, Vecteur3D);

//Fait le produit scalaire de deux vecteurs3D
double operator*(Vecteur3D, Vecteur3D const&);

//Fait le produit vectoriel de deux vecteurs 3D
const Vecteur3D operator^(Vecteur3D, Vecteur3D const&); 

Vecteur3D const& arrondis(Vecteur3D const&);
