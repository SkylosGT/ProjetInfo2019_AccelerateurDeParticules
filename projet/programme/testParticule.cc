#include <iostream>
#include "Particule.h"
#include "Vecteur3D.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Vecteur3D r;
    r.set(0,0,0);
    Vecteur3D v;
    v.set(1,1,1);
    double m(10);
    double q(5);
    Vecteur3D p;
    p.set(3,3,3);

    Particule p(r,p,m,q);
    p.affiche();
    return 0;
}

