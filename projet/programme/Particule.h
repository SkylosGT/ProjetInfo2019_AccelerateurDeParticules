#include "Vecteur3D.h"

/*Header de la classe particule
  unités SI*/

class Particule
{
private:
    Vecteur3D vec_r; //Position de la particule dans R3
    Vecteur3D vec_v; //Quantité de mouvement de la particule dans R3
    double scal_m; //Masse de la particule
    double scal_q; //Charge de la particule

public:
    //Constructeur par vecteur quantité de mouvement en Gev
    Particule(Vecteur3D /*Position*/, Vecteur3D /*Quantité de mouvement*/, double/*Masse*/, double/*Charge*/);
    //Constructeur par energie en GeV et direction vectorielle
    Particule(Vecteur3D/*Position*/, Vecteur3D /*Direction Vectorielle*/, double /*Energie*/, double/*Masse*/, double /*Charge*/ );
    //Déstructeur
    ~Particule();
  
    //Fonction transforme quantité de mouvement en GeV à quantité de mouvement SI
    Vecteur3D toVec_pSI(Vecteur3D/*Quantité de mouvement*/);
    
    //Fonction transforme quantité de mouvement en GeV à quantité de mouvement SI
    double toScalEnergieSI(double /*Energie*/);

    //Fonction norme de la vitesse
    double scalNormeVitesse();
    //Fonction Energie
    double scalEnergie();
    //Fonction Facteur Gamma
    double scalFacteurGamma();
};

