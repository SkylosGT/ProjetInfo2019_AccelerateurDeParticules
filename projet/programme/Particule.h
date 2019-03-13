#include "Vecteur3D.h"

/*Header de la classe particule
  unités SI*/

class Particule
{
private:
    Vecteur3D vec_r; //Position de la particule dans R3
    Vecteur3D vec_v; //Vitesse de la particule dans R3
    double scal_m; //Masse de la particule
    double scal_q; //Charge de la particule
    
    /*Temporaire*/
    double scal_E; //Energie de la particule  
    double scal_gamma; //Facteur gamma de la particule

public:
    Particule(/* args */);
    ~Particule();
};

