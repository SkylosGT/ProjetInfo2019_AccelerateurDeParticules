#include "Vecteur3D.h"

/*Header de la classe particule
  unités GeV*/

class Particule
{
private:
    Vecteur3D vec_r; //Position de la particule dans R3
    /*Vecteur vitesse normé??*/
    Vecteur3D vec_p; //Quantité de mouvement de la particule dans R3
    double scal_m; //Masse de la particule
    double scal_q; //Charge de la particule
    
    /*Temporaire*/
    double scal_E; //Energie de la particule  
    double scal_gamma; //Facteur gamma de la particule

public:
    Particule(Vecteur3D/*position*/, Vecteur3D, double/*masse*/, double, double);
    ~Particule();
};

