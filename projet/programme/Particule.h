#include "Vecteur3D.h"

/*Header de la classe particule
  unités GeV*/

class Particule
{
private:
    Vecteur3D vec_r; //Position de la particule dans R3 
    Vecteur3D vec_v; //Quantité de mouvement de la particule dans R3
    double scal_m; //Masse de la particule
    double scal_q; //Charge de la particule
    Vecteur3D vec_f; //Force appliquée sur la particule

public:
    //Constructeur par vecteur quantité de mouvement en Gev
    Particule(Vecteur3D /*Position*/, Vecteur3D /*Quantité de mouvement*/, double/*Masse*/, double/*Charge*/);

    //Constructeur par energie en GeV et direction vectorielle
    Particule(Vecteur3D/*Position*/, Vecteur3D /*Direction Vectorielle*/, double /*Energie*/, double/*Masse*/, double /*Charge*/);
    
    //Déstructeur
    ~Particule();

    double Energie();

    double FacteurGamma();

    void ajouteForceMagnetique(Vecteur3D /*Champs magnétique*/, double /*Pas de temps*/);

    void bouger(double /*Pas de temps*/);

    void affiche();
};

std::ostream& operator<<(std::ostream&, Particule const&);