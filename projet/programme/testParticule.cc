#include "Particule.h"
#include "Vecteur3D.h"
#include "ConstantesPhysiques.h"

using namespace std;
using namespace ConstantesPhysiques;

//TEST de la classe Particule, de ses méthode et de la surcharge des opérateurs pour les particules
int main()
{   
    //Positions de P1 et P2
    Vecteur3D _r1(3.00984, -0.391837, 0), _r2(2.99016, -0.391837, 0);

    //Vitesses de P1 et P2
    Vecteur3D _v1(-210200, -2.64754e+8, 0), _v2(210200, -2.64754e+8, 0);

    //Energie de P1 et P2
    double _E(2);

    //Masse de P1 et P2
    double _m(0.938272);

    //Charge de P1 et P2
    double _q(const_e);

    //Deux particules P1 et P2
    Particule p1(_r1,_v1,_E,_m,_q), p2(_r2,_v2,_E,_m,_q);

    //Test de l'affichage des deux particules
    cout<<"Création de deux particules :"<<endl;
    cout<<p1<<endl<<p2<<endl;  
    
    //Champs magnétique et pas de temps
    Vecteur3D _B(0,0,7);
    double _dt (1e-11);
    
    //Test de l'ajout d'une force magnétique a P1 et P2
    cout<<"Ajout d'une force Magnetique B="<<_B<<"(dt="<<_dt<<") :"<<endl;
    cout<<" à P1 :"<<endl;
    p1.ajouteForceMagnetique(_B, _dt);
    cout<<" à P2 :"<<endl;
    p2.ajouteForceMagnetique(_B,_dt);
    cout<<endl;
    
    //Test du changement de position de P1 et P2
    cout<<"Les particules bougent 1 fois (dt="<<_dt<<") :"<<endl;
    p1.bouger(_dt);
    p2.bouger(_dt);
    cout<<p1<<endl<<p2<<endl;
    return 0;
}
