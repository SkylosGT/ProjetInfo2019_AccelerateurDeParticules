#include "Vecteur3D.h"

/*Header de la classe particule
  unités SI*/

class Particule
{
private:
    Vecteur3D vec_r; //Position de la particule dans R3
    Vecteur3D vec_p; //Quantité de mouvement de la particule dans R3
    double scal_m; //Masse de la particule
    double scal_q; //Charge de la particule

public:
    //Constructeur
    Particule(/*Position*/Vecteur3D, /*Quantité de mouvement*/Vecteur3D, /*Masse*/double, /*Charge*/double);
    //Déstructeur
    ~Particule();
    //Fonction norme de la vitesse
    double scalNormeVitesse();
    //Fonction Energie
    double scalEnergie();
    //Fonction Facteur Gamma
    double scalFacteurGamma();
};

