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
	
		Vecteur3D(double _x=0.0, double _y=0.0, double _z=0.0)
		: x(_x) , y(_y), z(_z) 
		{}
		
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
