#include <iostream>
#include <cmath>
#include "Vecteur3D.h"
namespace std;

//affiche() : affiche les composantes x, y, z d'un vecteur sur la console
void Vecteur3D::affiche() const {
		
		cout << x << " " << y << " " << z << endl;
	}

//compare() : Compare l'instance coordonnée par coordonnée avec un vecteur passé en paramètre 
bool Vecteur3D::compare(Vecteur3D Acomparer) const
	{
		if ((x == Acomparer.getx()) and (y ==  Acomparer.gety()) and (z == Acomparer.getz()))
		{
		
		return true;
		
	} else {
		
		return false;
		
	}
}

/*Setter !!A REMPLACER!!*/
void Vecteur3D::set(double xx, double yy, double zz) 
{
	x = xx;
	y = yy;
	z = zz;
}

//addition() : Additionne l'instance avec un vecteur passé en paramètre
Vecteur3D Vecteur3D::addition(Vecteur3D autre) const
{	
	Vecteur3D nouveau;
	nouveau.set( x + autre.getx(), y + autre.gety(), z + autre.getz());
	
	return nouveau;
}

//soustraction() : Soustrait l'instance avec un vecteur passé en paramètre
Vecteur3D Vecteur3D::soustraction(Vecteur3D autre) const
{
	Vecteur3D nouveau;
	nouveau.set(x - autre.getx(), y - autre.gety(), z - autre.getz());
	
	return nouveau;
}

//oppose() : Multiplie l'instance par (-1)
Vecteur3D Vecteur3D::oppose () const 
{ 	
	Vecteur3D nouveau;
	nouveau.set(-x,-y,-z);
	
	return nouveau;
}

//mult() : Multiplie l'instance par un scalaire
Vecteur3D Vecteur3D::mult (double scalaire) const
{
	Vecteur3D nouveau;
	nouveau.set(scalaire*x,scalaire*y,scalaire*z);
	
	return nouveau;
}

//prod_scal() : Effectue un produit scalaire entre l'instance et un vecteur passé en paramètre
double Vecteur3D::prod_scal(Vecteur3D autre) const
{
	double produit_scalaire;
	produit_scalaire = x*autre.getx() + y*autre.gety() + z*autre.getz() ;
	
	return produit_scalaire;
}

//prod_vect() : Effectue un produit vectoriel entre l'instance et un vecteur passé en paramètre
Vecteur3D Vecteur3D::prod_vect(Vecteur3D autre) const
{ 
	Vecteur3D nouveau;
	nouveau.set(y*autre.getz() - z*autre.gety(), z*autre.getx() - x*autre.getz(), x*autre.gety() - y*autre.getx());
	
	return nouveau;
}

//norme() : Calcule la norme de l'instance
double Vecteur3D::norme() const
{
	double norm;
	norm = sqrt(x*x + y*y + z*z);
	
	return norm;
}

//norme2() : Calcule le carré de la norme de l'instance
double Vecteur3D::norme2() const
{ 
	double norme_carre;
	norme_carre = pow( norme(), 2);
	
	return norme_carre;
}

//unitaire() : Retourne le vecteur unitaire de même direction que l'instance
Vecteur3D Vecteur3D::unitaire() const 
{
	Vecteur3D nouveau;
	nouveau.set(x/norme(), y/norme(), z/norme());
	
	return nouveau;
}

//prod_mixte() : Effectue un produit mixte entre l'instance et deux vecteurs passés en paramètre
double Vecteur3D::prod_mixte(Vecteur3D V1, Vecteur3D V2) const 
{
	double produit_mixte;
	produit_mixte = prod_scal(V1.prod_vect(V2));
	
	return produit_mixte;
}
