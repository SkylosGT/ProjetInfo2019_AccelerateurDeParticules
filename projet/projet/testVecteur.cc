#include "Vecteur3D.h"

/*Boucle principale
pour le moment il ne s'agit que du test de la classe vecteur3D*/
int main ()
{
	const double testX=2.4;
	const double testY= 7.1;
	const double testZ= 3.7;
	Vecteur3D testVecteur1(testX, testY, testZ);
	Vecteur3D testVecteur2(testX, testY, testZ);
	testVecteur1.affiche();
	testVecteur2.affiche();
	testVecteur1.addition(testVecteur2).affiche();
	testVecteur1.soustraction(testVecteur2).affiche();
	testVecteur1.oppose().affiche();
	testVecteur1.mult(4.0).affiche();

}
