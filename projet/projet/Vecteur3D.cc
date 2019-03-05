#include <iostream>
#include <cmath>
namespace std;

void Vecteur3D::affiche() const {
		
		cout << x << " " << y << " " << z << endl;
	}
	
bool Vecteur3D::compare(Vecteur3D Acomparer) const
	{
		if ((x == Acomparer.getx()) and (y ==  Acomparer.gety()) and (z == Acomparer.getz()))
		{
		
		return true;
		
	} else {
		
		return false;
		
	}
}

void Vecteur3D::set(double xx, double yy, double zz) 
{
	
	x = xx;
	y = yy;
	z = zz;
}

Vecteur3D Vecteur3D::addition(Vecteur3D autre) const
{	
	Vecteur3D nouveau;
	nouveau.set( x + autre.getx(), y + autre.gety(), z + autre.getz());
	
	return nouveau;
}

Vecteur3D Vecteur3D::soustraction(Vecteur3D autre) const
{
	Vecteur3D nouveau;
	nouveau.set(x - autre.getx(), y - autre.gety(), z - autre.getz());
	
	return nouveau;
}

Vecteur3D Vecteur3D::oppose () const 
{ 	
	Vecteur3D nouveau;
	nouveau.set(-x,-y,-z);
	
	return nouveau;
}

Vecteur3D Vecteur3D::mult (double scalaire) const
{
	Vecteur3D nouveau;
	nouveau.set(scalaire*x,scalaire*y,scalaire*z);
	
	return nouveau;
}

double Vecteur3D::prod_scal(Vecteur3D autre) const
{
	double produit_scalaire;
	produit_scalaire = x*autre.getx() + y*autre.gety() + z*autre.getz() ;
	
	return produit_scalaire;
}

Vecteur3D Vecteur3D::prod_vect(Vecteur3D autre) const
{ 
	Vecteur3D nouveau;
	nouveau.set(y*autre.getz() - z*autre.gety(), z*autre.getx() - x*autre.getz(), x*autre.gety() - y*autre.getx());
	
	return nouveau;
}

double Vecteur3D::norme() const
{
	double norm;
	norm = sqrt(x*x + y*y + z*z);
	
	return norm;
}

double Vecteur3D::norme2() const
{ 
	double norme_carre;
	norme_carre = pow( norme(), 2);
	
	return norme_carre;
}

Vecteur3D Vecteur3D::unitaire() const 
{
	Vecteur3D nouveau;
	nouveau.set(x/norme(), y/norme(), z/norme());
	
	return nouveau;
}

double Vecteur3D::prod_mixte(Vecteur3D V1, Vecteur3D V2) const 
{
	double produit_mixte;
	produit_mixte = prod_scal(V1.prod_vect(V2));
	
	return produit_mixte;
}

int main ()
{
	Vecteur3D vecteur;
	vecteur.set(2.0,1.0,21);
	cout<<vecteur.getx()<<", "<<vecteur.gety()<<", "<<vecteur.getz();
}
