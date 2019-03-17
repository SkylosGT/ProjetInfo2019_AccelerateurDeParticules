#include <iostream>
#include <cmath>
#include "Vecteur3D.h"
using namespace std;
//DEFINITIONS (PROTOTYPE + CORPS) DES METHODES ET DES FONCTIONS DE LA CLASSE VECTEUR3D

//METHODES PRIVEES DE LA CLASSE VECTEUR3D
//compare() : compare les coordonnées de l'instance avec celles d'un autre vecteur
bool Vecteur3D::compare(Vecteur3D const& Acomparer) const {
	if ((x == Acomparer.getx()) and (y ==  Acomparer.gety()) and (z == Acomparer.getz())) {
			return true;
		} else {
			return false;
		}
	}
	
//oppose() : Multiplie l'instance par (-1)
Vecteur3D Vecteur3D::oppose () const 
{ 	
	return Vecteur3D (-x,-y,-z);
}

//unitaire() : Retourne le vecteur unitaire de même direction et sens que l'instance
Vecteur3D Vecteur3D::unitaire() const 
{
	return Vecteur3D (x/norme(), y/norme(), z/norme());
}

//OPERATEURS INTERNES A LA CLASSE VECTEUR3D
bool Vecteur3D::operator==(Vecteur3D const& Acomparer) const {
	return (*this).compare(Acomparer);}
	
bool Vecteur3D::operator!=(Vecteur3D const& Acomparer) const {
	return !((*this).compare(Acomparer));}
		
const Vecteur3D Vecteur3D::operator-() const {
	return (*this).oppose();}
	
const Vecteur3D Vecteur3D::operator ~() const {
	return (*this).unitaire();}

Vecteur3D& Vecteur3D::operator+=(Vecteur3D const& autre){
	*this = *this + autre;
	return *this; }

Vecteur3D& Vecteur3D::operator-=(Vecteur3D const& autre){
	*this = *this - autre;
	return *this; }
	
Vecteur3D& Vecteur3D::operator*=(double const& scalaire){
	*this = scalaire*(*this);
	return *this; }
	
Vecteur3D& Vecteur3D::operator^=(Vecteur3D const& autre){
	*this = (*this)^autre;
	return *this; }

//METHODES PUBLIQUES DE LA CLASSE VECTEURS3D
//affiche() : affiche les coordonnées de l'instance 
std::ostream& Vecteur3D::affiche(std::ostream& sortie) const 
{
	sortie <<x<<' '<<y<<' '<<z;
	
	return sortie;
}

//addition() : Additionne l'instance avec un vecteur passé en paramètre
Vecteur3D Vecteur3D::addition(Vecteur3D const& autre) const
{		
	return Vecteur3D ( x + autre.getx(), y + autre.gety(), z + autre.getz());
}

//soustraction() : Soustrait l'instance avec un vecteur passé en paramètre
Vecteur3D Vecteur3D::soustraction(Vecteur3D const& autre) const
{
	return Vecteur3D (x - autre.getx(), y - autre.gety(), z - autre.getz());
}

//mult() : Multiplie l'instance par un scalaire
Vecteur3D Vecteur3D::mult (double const& scalaire) const
{	
	return Vecteur3D (scalaire*x,scalaire*y,scalaire*z);
}

//prod_scal() : Effectue un produit scalaire entre l'instance et un vecteur passé en paramètre
double Vecteur3D::prod_scal(Vecteur3D const& autre) const
{
	return double (x*autre.getx() + y*autre.gety() + z*autre.getz());
}

//prod_vect() : Effectue un produit vectoriel entre l'instance et un vecteur passé en paramètre
Vecteur3D Vecteur3D::prod_vect(Vecteur3D const& autre) const
{ 	
	return Vecteur3D (y*autre.getz() - z*autre.gety(), z*autre.getx() - x*autre.getz(), x*autre.gety() - y*autre.getx());
}

//prod_mixte() : Effectue un produit mixte entre l'instance et deux vecteurs passés en paramètre
double Vecteur3D::prod_mixte(Vecteur3D V1, Vecteur3D V2) const 
{	
	return double (prod_scal(V1.prod_vect(V2)));
}

//norme() : Calcule la norme de l'instance
double Vecteur3D::norme() const
{
	return double (sqrt(x*x + y*y + z*z));
}

//norme2() : Calcule le carré de la norme de l'instance
double Vecteur3D::norme2() const
{ 
	return double (pow( norme(), 2));
}

//rotation(): Effetcue une rotation de l'instance d'un angle t en radiant autour d'un axe donné par un vecteur unitaire (angle et axe passés en paramètres)
Vecteur3D Vecteur3D::rotation(Vecteur3D const& a, double t) const 
{
	return (cos(t)*(*this)+(1-cos(t))*((*this)*(~a))*(~a)+sin(t)*((~a)^(*this)));
}
	

//OPERATEURS EXTERNES A LA CLASSE VECTEUR3D UTILISANT LES METHODES DE LA CLASSE
ostream& operator<<(ostream& sortie, Vecteur3D const& V) {
	return V.affiche(sortie); }
	
const Vecteur3D operator+(Vecteur3D V1, Vecteur3D const& V2) {
	return V1.addition(V2);}
	
const Vecteur3D operator-(Vecteur3D V1, Vecteur3D const& V2) {
	return V1.soustraction(V2);}
	
const Vecteur3D operator*(double scalaire, Vecteur3D const& V){
	return V.mult(scalaire);}
	
const Vecteur3D operator*(Vecteur3D const& V, double scalaire){
	return V.mult(scalaire);}
	
double operator*(Vecteur3D V1, Vecteur3D const& V2){
	return V1.prod_scal(V2);}
	
Vecteur3D operator^(Vecteur3D V1, Vecteur3D const& V2) {
	return V1.prod_vect(V2);}
