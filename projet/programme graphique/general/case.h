#include "Particule.h"
#include <vector>

class Case {
private:
    int positionDeLaCase;
    std::vector<Particule*> particules;
    double rayon;
    double angle;

public:
    Case(int, double, double);
    Vecteur3D& entreeDeLaCase();
    Vecteur3D& sortieDeLaCase();
    bool ParticuleEstSortie(Particule const&);

};

