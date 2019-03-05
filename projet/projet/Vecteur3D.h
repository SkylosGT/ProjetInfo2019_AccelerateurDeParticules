#pragma once

class Vecteur3D {
	
	private: 
	
		double x;
		double y;
		double z;
	
	public:
	
		double getx() const;
		double gety() const;
		double getz() const;
		
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