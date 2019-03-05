#pragma once

//En tête de la classe Vecteur3D, description des méthodes dans "Vecteur3D.cc"
class Vecteur3D {
	
	private: 
	
	//Déscription du vecteur en coordonnées cartésiennes
		double x;
		double y;
		double z;
	
	public:
	
	//Getter pour les coordonnées x,y,z
		double getx() const {return x;};
		double gety() const {return y;};
		double getz() const {return z;};
	
	//Setter pour l'initialisation d'un vecteur !!!à remplacer par un Constructeur!!
		void set(double, double, double);
		
		void affiche () const;
		
		bool compare (Vecteur3D) const;
		
		Vecteur3D addition (Vecteur3D) const;
		
		Vecteur3D soustraction (Vecteur3D) const;
		
		Vecteur3D oppose () const;
	
		Vecteur3D mult(double) const;
		
		double prod_scal(Vecteur3D) const;
		
		Vecteur3D prod_vect(Vecteur3D) const;
		
		double norme() const;
		
		double norme2() const;
		
		Vecteur3D unitaire() const;
		
		double prod_mixte(Vecteur3D, Vecteur3D) const;
};