#include <iostream>
using namespace std;

class Vecteur3D {
	
	private : 
	
		double x;
		double y;
		double z;
	
	public:
	
		double getx() const;
		double gety() const;
		double getz() const;
		
		void set(double xx, double yy, double zz);
		
		void affiche () const;
		
		bool compare ( Vecteur3D Acomparer) const;
		
		Vecteur3D addition (Vecteur3D autre) const;
	
};

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
	
double Vecteur3D::getx() const
{
	
	return x;
}

double Vecteur3D::gety() const
{
	
	return y;
}

double Vecteur3D::getz() const
{
	
	return z ;
	
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


int main ()
{
	
	Vecteur3D vect1;
	Vecteur3D vect2;
	Vecteur3D vect3;


		vect1.set(1.0, 2.0, -0.1);
		vect2.set(2.6, 3.5, 4.1);
		vect3 = vect1;

	cout << "Vecteur 1 : ";
	vect1.affiche();
	cout << endl;

	cout << "Vecteur 2 : ";
	vect2.affiche();
	cout << endl;

	cout << "Le vecteur 1 est ";
	if (vect1.compare(vect2)) {
		cout << "égal au";
		
		} else {
		cout << "différent du";
		}

		cout << " vecteur 2," << endl << "et est ";
	if (not vect1.compare(vect3)) {
		cout << "différent du";
			} else {
				cout << "égal au";
				}
			cout << " vecteur 3." << endl;
	
}
