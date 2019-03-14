#include <iostream>
#include "Vecteur3D.h"
using namespace std;

/*Boucle principale
pour le moment il ne s'agit que du test de la classe vecteur3D*/
int main ()
{
Vecteur3D vect1;
Vecteur3D vect2;
Vecteur3D vect3;

// Note : Cette partie sera revue dans deux semaines (constructeurs, surcharge des opérateurs).

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
