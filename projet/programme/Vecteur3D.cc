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
	
Vecteur3D& Vecteur3D::operator*=(double const scalaire) {
	scal_x *= scalaire;
	scal_y *= scalaire;
	scal_z *= scalaire;
	return *this;}
	
Vecteur3D& Vecteur3D::operator^=(Vecteur3D const& autre) {
	Vecteur3D tmp(*this);
	scal_x = tmp.scal_y*autre.scal_z - tmp.scal_z*autre.scal_y;
	scal_y = tmp.scal_z*autre.scal_x - tmp.scal_x*autre.scal_z;
	scal_z = tmp.scal_x*autre.scal_y - tmp.scal_y*autre.scal_x;
	return *this;}

//METHODES PUBLIQUES DE LA CLASSE VECTEURS3D

//Le constrcteur qui initialise le nouvel objet vecteur3D
Vecteur3D::Vecteur3D(double scal_x, double scal_y, double scal_z) 
: scal_x(scal_x), scal_y(scal_y), scal_z(scal_z) {}

//affiche() : affiche les coordonnées de l'instance 
std::ostream& Vecteur3D::affiche(std::ostream& sortie) const 
{
	sortie <<scal_x<<' '<<scal_y<<' '<<scal_z;
	return sortie;
}

//prod_scal() : Effectue un produit scalaire entre l'instance et un vecteur passé en paramètre
double Vecteur3D::prod_scal(Vecteur3D const& autre) const
{
	return double (scal_x*autre.scal_x + scal_y*autre.scal_y + scal_z*autre.scal_z);
}

//norme() : Calcule la norme de l'instance
double Vecteur3D::norme() const
{
	return sqrt(scal_x*scal_x + scal_y*scal_y + scal_z*scal_z);
}

//norme2() : Calcule le carré de la norme de l'instance
double Vecteur3D::norme2() const
{ 
	return scal_x*scal_x + scal_y*scal_y + scal_z*scal_z;
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
	
const Vecteur3D operator*(Vecteur3D V, double scalaire){
	return V *= scalaire;} 

const Vecteur3D operator*(double scalaire, Vecteur3D V){
	return V *= scalaire;} 
	
double operator*(Vecteur3D V1, Vecteur3D const& V2){
	return V1.prod_scal(V2);}
	
const Vecteur3D operator^(Vecteur3D V1, Vecteur3D const& V2) {
	return V1^=V2;}
