#include <iostream>
#include <cmath>
#include "Vecteur3D.h"
using namespace std;
//DEFINITION (PROTOTYPE + CORPS) DES METHODES ET DES FONCTIONS DE LA CLASSE VECTEUR3D

//METHODES PRIVEES DE LA CLASSE VECTEUR3D
//compare() : compare les coordonnées de l'instance avec celles d'un autre vecteur
bool Vecteur3D::compare(Vecteur3D const& Acomparer) const {
	if ((scal_x == Acomparer.scal_x) and (scal_y ==  Acomparer.scal_y) and (scal_z == Acomparer.scal_z)) {
			return true;
		} else {
			return false;
		}
	} 
/*	
//oppose() : Multiplie l'instance par (-1)
Vecteur3D Vecteur3D::oppose () const 
{ 	
	return Vecteur3D (-scal_x,-scal_y,-scal_z);
}

//unitaire() : Retourne le vecteur unitaire de même direction et sens que l'instance
Vecteur3D Vecteur3D::unitaire() const 
{
	return Vecteur3D (scal_x/norme(), scal_y/norme(), scal_z/norme());
} */

//OPERATEURS INTERNES A LA CLASSE VECTEUR3D
bool Vecteur3D::operator==(Vecteur3D const& Acomparer) const {
	return (*this).compare(Acomparer);}
	
bool Vecteur3D::operator!=(Vecteur3D const& Acomparer) const {
	return !((*this).compare(Acomparer));}
		
const Vecteur3D Vecteur3D::operator-() const {
	return Vecteur3D (-scal_x,-scal_y,-scal_z);
}

const Vecteur3D Vecteur3D::operator ~() const {
	return Vecteur3D (scal_x/norme(), scal_y/norme(), scal_z/norme());
}
	
Vecteur3D& Vecteur3D::operator+=(Vecteur3D const& autre) {
	scal_x += autre.scal_x;
	scal_y += autre.scal_y;
	scal_z += autre.scal_z;
	return *this;}

Vecteur3D& Vecteur3D::operator-=(Vecteur3D const& autre) {
	scal_x -= autre.scal_x;
	scal_y -= autre.scal_y; 
	scal_z -= autre.scal_z;
	return *this;}
	
/*Vecteur3D& Vecteur3D::operator*=(double const scalaire) {
	return *this;
	}*/
	
Vecteur3D& Vecteur3D::operator^=(Vecteur3D const& autre) {
	scal_x = scal_y*autre.scal_z - scal_z*autre.scal_y;
	scal_y = scal_z*autre.scal_x - scal_x*autre.scal_z;
	scal_z = scal_x*autre.scal_y - scal_y*autre.scal_x;
	return *this;}

//METHODES PUBLIQUES DE LA CLASSE VECTEURS3D
//Le constrcteur qui initialise le nouvel objet vecteur3D
Vecteur3D::Vecteur3D(double scal_x, double scal_y, double scal_z) : scal_x(scal_x), scal_y(scal_y), scal_z(scal_z) {}

//affiche() : affiche les coordonnées de l'instance 
std::ostream& Vecteur3D::affiche(std::ostream& sortie) const 
{
	sortie <<scal_x<<' '<<scal_y<<' '<<scal_z;
	
	return sortie;
}
/*
//addition() : Additionne l'instance avec un vecteur passé en paramètre
Vecteur3D Vecteur3D::addition(Vecteur3D const& autre) const
{		
	return Vecteur3D ( scal_x + autre.scal_x, scal_y + autre.scal_y, scal_z + autre.scal_z);
} 

//soustraction() : Soustrait l'instance avec un vecteur passé en paramètre
Vecteur3D Vecteur3D::soustraction(Vecteur3D const& autre) const
{
	return Vecteur3D (scal_x - autre.scal_x, scal_y - autre.scal_y, scal_z - autre.scal_z);
}

//mult() : Multiplie l'instance par un scalaire
Vecteur3D Vecteur3D::mult (double const& scalaire) const
{	
	return Vecteur3D (scalaire*scal_x,scalaire*scal_y,scalaire*scal_z);
}*/

//prod_scal() : Effectue un produit scalaire entre l'instance et un vecteur passé en paramètre
double Vecteur3D::prod_scal(Vecteur3D const& autre) const
{
	return double (scal_x*autre.scal_x + scal_y*autre.scal_y + scal_z*autre.scal_z);
}
/*
//prod_vect() : Effectue un produit vectoriel entre l'instance et un vecteur passé en paramètre
Vecteur3D Vecteur3D::prod_vect(Vecteur3D const& autre) const
{ 	
	return Vecteur3D (scal_y*autre.scal_z - scal_z*autre.scal_y, scal_z*autre.scal_x - scal_x*autre.scal_z, scal_x*autre.scal_y - scal_y*autre.scal_x);
}

//prod_mixte() : Effectue un produit mixte entre l'instance et deux vecteurs passés en paramètre
double Vecteur3D::prod_mixte(Vecteur3D V1, Vecteur3D V2) const 
{	
	return double (prod_scal(V1.prod_vect(V2)));
}*/

//norme() : Calcule la norme de l'instance
double Vecteur3D::norme() const
{
	return double (sqrt(scal_x*scal_x + scal_y*scal_y + scal_z*scal_z));
}

//norme2() : Calcule le carré de la norme de l'instance
double Vecteur3D::norme2() const
{ 
	return norme()*norme();
}

//rotation(): Effetcue une rotation de l'instance d'un angle t en radiant autour d'un ascal_xe donné par un vecteur unitaire (angle et ascal_xe passés en paramètres)
Vecteur3D& Vecteur3D::rotation(Vecteur3D const& a, double t) 
{
	*this=((cos(t)*(*this))+(1-cos(t))*((*this)*(~a))*(~a)+sin(t)*((~a)^(*this)));
	return *this;
}
	

//OPERATEURS EXTERNES A LA CLASSE VECTEUR3D UTILISANT LES METHODES DE LA CLASSE
ostream& operator<<(ostream& sortie, Vecteur3D const& V){
	return V.affiche(sortie); }
	
const Vecteur3D operator+(Vecteur3D V1, Vecteur3D const& V2){
	return V1+=V2;}
	
const Vecteur3D operator-(Vecteur3D V1, Vecteur3D const& V2){
	return V1-=V2;}
/*	
const Vecteur3D operator*(double scalaire, Vecteur3D const& V){
	return V*=scalaire;}
	
const Vecteur3D operator*(Vecteur3D const& V, double scalaire){
	return V*=scalaire;} */
	
double operator*(Vecteur3D V1, Vecteur3D const& V2){
	return V1.prod_scal(V2);}
	
Vecteur3D operator^(Vecteur3D V1, Vecteur3D const& V2) {
	return V1^=V2;}
