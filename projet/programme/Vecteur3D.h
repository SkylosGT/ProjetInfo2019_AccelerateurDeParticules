#pragma once
#include <iostream>

//En tête de la classe Vecteur3D, description des méthodes dans "Vecteur3D.cc"
class Vecteur3D {
	
	private: 
	
	//Description du vecteur en 3 coordonnées cartésiennes
		double scal_x;	//Composante sur X
		double scal_y;	//Composante sur Y
		double scal_z; 	//Composante sur Z
	
	//Méthodes auxquels on accède via des opérateurs internes à la classe Vecteur3D (fonctions utilisées par les opérateurs internes)
		
		bool compare(Vecteur3D const&) const; //Fonction qui compare deux vecteurs et return true si l'instance courante et l'autre vecteur3D sont égaux (même coordonnées)
		
		Vecteur3D oppose () const; //Fonction qui renvoie l'opposé de l'instance courante (opposé de chaque coordonnée)
	
		Vecteur3D unitaire() const; //Fonction qui renvoie un vecteur unitaire (norme=1) de même direction et sens que l'instance courante
	
	public:

	//Getter pour les coordonnées scal_x,scal_y,scal_z
		double getx() const {return scal_x;};
		double gety() const {return scal_y;};
		double getz() const {return scal_z;};
	
	//Un constructeur pour initialiser les objets (avec initialisation par défaut au vecteur nul)
		Vecteur3D (double scal_x=0.0, double scal_y=0.0, double scal_z=0.0);
	
	//OPERATEURS INTERNES (utilisant des fonctions prédéfinies à cet usage)
		bool operator==(Vecteur3D const&) const; //Teste l'égalité de l'instance courante avec un autre Veteur3D (retourne true si il scal_y a égalité)
		bool operator!=(Vecteur3D const&) const; //Teste l'égalité de l'instance courante avec un autre vecteur3D (retourne true si n'scal_y a pas égalité)
		const Vecteur3D operator-() const; //Retourne l'opposé de l'instance courante
		const Vecteur3D operator~() const; //Retourne le vecteur unitaire associé à l'instance courante
		Vecteur3D& operator+=(Vecteur3D const&); //Retourne dans l'instance courante l'addition de celle-ci avec un autre Vecteur3D
		Vecteur3D& operator-=(Vecteur3D const&); //Retourne dans l'instance courante la soustraction de celle-ci avec un autre Vecteur3D
		Vecteur3D& operator*=(double const&); //Retourne dans l'instance courante la multiplication de celle-ci avec un scalaire
		Vecteur3D& operator^=(Vecteur3D const&); //Retourne dans l'instance courante le produit vectoriel de celle-ci avec un autre Vecteur3D
		
	//Fonctions utilisées pas les opérateurs externes à la classe Vecteur3D
	
		std::ostream& affiche(std::ostream&) const; //Fonction permettant l'affichage des 3 coordonnées du vecteur3D en instance courante
		
		Vecteur3D addition (Vecteur3D const&) const; //Fonction qui retourne un vecteur3D résultant de l'addition de l'instance courante avec un autre vecteur3D
		
		Vecteur3D soustraction (Vecteur3D const&) const; //Fonction qui retourne un vecteur3D résultant de la soustraction de l'instance courante avec un autre vecteur3D
		
		Vecteur3D mult(double const&) const; //Fonction qui renvoie la mutliplication de l'instance courante par un scalaire réel
		
		double prod_scal(Vecteur3D const&) const; //Fonction qui renvoie le produit scalaire de l'instance courante avec un autre vecteur3D
		
		Vecteur3D prod_vect(Vecteur3D const&) const; //Fonction qui renvoie le produit vectoriel de l'instance courante avec un autre vecteur3D
		
		double prod_mixte(Vecteur3D, Vecteur3D) const; //Fonction qui renvoie le produit mixte de l'instance courante avec deux autres vecteurs3D 
														//(produit scalaire entre l'instance courante et le produit vectoriel des deux autres vecteurs)
	
	//Autres fonctions utiles à l'utilisation de la classe Vecteur3D
	
		double norme() const; //Fonction qui retourne la norme de l'instance courante
		
		double norme2() const; //Fonction qui retourne la norme au carré de l'instance courante
				
		Vecteur3D& rotation(Vecteur3D const&, double); // Fonction qui fait la rotation de l'instance courante autour d'un axe (vecteur unitaire passé en argument)
														//d'un angle en radiant passé aussi en argument

};

//OPERATEURS EXTERNES (utilisant les fonctions de la classe Vecteur3D

std::ostream& operator<<(std::ostream&, Vecteur3D const&); //Permet l'affichage d'un Vecteur3D (affiche ces 3 coordonnées)

const Vecteur3D operator+(Vecteur3D, Vecteur3D const&); //Additionne deux vecteurs 3D

const Vecteur3D operator-(Vecteur3D, Vecteur3D const&); //Soustrait deux vecteurs 3D

const Vecteur3D operator*(double, Vecteur3D const&); //Multiplie un vecteur3D par un scalaire

const Vecteur3D operator*(Vecteur3D const&, double); //Multiplie un vecteur3D par un scalaire

double operator*(Vecteur3D, Vecteur3D const&); //Fait le produit scalaire de deux vecteurs3D

Vecteur3D operator^(Vecteur3D, Vecteur3D const&); //Fait le produit vectoriel de deux vecteurs 3D


