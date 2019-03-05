#include <iostream>
#include "Vecteur3D.h"
using namespace std;

int main ()
{
	Vecteur3D vecteur;
	vecteur.set(2.0,1.0,21);
	cout<<vecteur.getx()<<", "<<vecteur.gety()<<", "<<vecteur.getz();
}
