#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <math.h>
#include "Vecteur3D.h"
using namespace std;

/*Boucle principale
pour le moment il ne s'agit que du test de la classe vecteur3D*/
int main ()
{
	// un vecteur en 3D :
	Vecteur3D vect1(1, 2, -1);

	// un autre vecteur en 3D
	Vecteur3D vect2(2, 3,  4);

	Vecteur3D vect3(vect1);  // copie de V1
	Vecteur3D vect4(1);      // le vecteur nul initialisé avec la première valeure

	//Affichage des vecteurs à l'aide d'opérateurs
	cout << "Vecteur 1 puis 3 : " << vect1 <<" , "<< vect3<< endl;
	cout << "Vecteur 2 : " << vect2 << endl;
	cout << "Vecteur 4 : " << vect4 << endl;
	cout << endl;
	
	//Comparaison de vecteurs à l'aide d'opérateurs
	cout << "Le vecteur 1 est ";
		if (vect1 == vect2) {
			cout << "égal au";
		} else {
			cout << "différent du";}
			
	cout << " vecteur 2," << endl << "et est ";
		if (vect1 != vect3) {
			cout << "différent du";
		} else {
			cout << "égal au";}
	
	cout << " vecteur 3." << endl;
	cout << endl;

	//Test des opérateurs produit scalaire, vectoriel et produit mixte
	cout << "Le produit scalaire du vecteur 1 avec le vecteur 2 est : " << vect1*vect2 << endl;
	cout << "Le produit vectoriel du vecteur 2 avec le vecteur 3 est : " <<(vect2^vect3)<< endl;
	cout << "Le produit mixte du vecteur 1 avec les vecteur 2 et 3 est : " <<((vect1)*(vect2^vect4)) << endl;
	cout << endl;

	//Test des fonctions normes et normes au carré
	cout <<"La norme du vecteur 2 est : " << vect2.norme();
	cout<< " , sa norme au carré est donc : " << vect2.norme2() << endl;
	
	//Test des opérateurs opposé, unitaire, multiplication par un scalaire
	cout <<"L'opposé du vecteur 1 est : " << (-vect1) << endl;
	cout << "Son vecteur unitaire associé est : " << (~vect1) << endl;
	cout << "Le Multiplier à gauche par 4 donne le vecteur : " <<vect1*4.0<< " et à droite : "<<vect1*4 << endl;
	/*
	//Test de la fonction rotation
	cout << "Le vecteur résultant de la rotation du vecteur (1, 0, 0) d'un angle de 90° autour de l'axe du vecteur (0,0,1) est " << Vecteur3D(1,0,0).rotation(Vecteur3D(0,0,1), (M_PI/2)) << endl;
	cout <<endl;
	
	//Test de l'addition et de la sousctraction de deux vecteurs 
	cout << " Vecteur 3 + vecteur 2 = " << vect3 + vect2 << endl;
	cout << " Vecteur 2 + vecteur 3 = " << vect2 + vect3 << endl;
	cout << " Vecteur 3 - vecteur 2 = " << vect3 - vect2 << endl;
	cout << " Vecteur 2 - vecteur 3 = " << vect2 - vect3 << endl;
	cout << endl;
	
	//Test des opérateurs +=,-=,*= et ^=
	vect1+=vect2;
	vect2-=vect3;
	vect3*=4;
	vect4^=vect1;
	
	cout <<"L'addition du vecteur 1 avec le vecteur 2 est le nouveau vecteur 1 : " << vect1<< endl;
	cout <<"La soustraction du vecteur 2 avec le vecteur 3 est le nouveau vecteur 2 : " << vect2<< endl;
	cout <<"La multiplication du vecteur 3 avec un scalaire = 4 est le nouveau vecteur 3 : " << vect3 << endl;
	cout <<"Le produit scalaire du vecteur 4 avec le nouveau vecteur 3 est le nouveau vecteur 4 : " << vect4 << endl;
*/
	return 0;
}
