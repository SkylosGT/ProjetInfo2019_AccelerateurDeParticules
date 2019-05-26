#include "Particule.h"
#include <vector>

class Case {
private:
    int positionDeLaCase;
    std::vector<Particule*> particules;

public:
    Case(int);
    Vecteur3D& entreeDeLaCase(double);
    Vecteur3D& sortieDeLaCase(double);

};

