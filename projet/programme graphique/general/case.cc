#include <math.h>

#include "case.h"

Case::Case(int position, double angle, double rayon) :positionDeLaCase(position), angle(angle), rayon(rayon){}

Vecteur3D& Case::entreeDeLaCase(){
    return (*new Vecteur3D(rayon*cos(positionDeLaCase*angle), -rayon*sin(positionDeLaCase*angle), 0));}

Vecteur3D& Case::sortieDeLaCase(){
    return (*new Vecteur3D(rayon*cos(positionDeLaCase*angle+angle), -(rayon*sin(positionDeLaCase*angle+angle)), 0));}

bool Case::ParticuleEstSortie(const Particule& particule){
    if((particule.position()^sortieDeLaCase()).getz()>0){
        return true;
    }else {
        return false;
}
}
