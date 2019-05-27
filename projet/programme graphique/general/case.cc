#include <math.h>
#include <vector>

#include "case.h"
#include "Particule.h"

using namespace std;

Case::Case(int position, double angle, double rayon) :positionDeLaCase(position), angle(angle), rayon(rayon){}

Vecteur3D& Case::entreeDeLaCase(){
    return (*new Vecteur3D(rayon*cos(positionDeLaCase*angle), -rayon*sin(positionDeLaCase*angle), 0));}

Vecteur3D& Case::sortieDeLaCase(){
    return (*new Vecteur3D(rayon*cos(positionDeLaCase*angle+angle), -(rayon*sin(positionDeLaCase*angle+angle)), 0));}

bool Case::particuleCollider(const Particule& particule){
    if((particule.position()^entreeDeLaCase()).getz()>=0 && (particule.position()^sortieDeLaCase()).getz()<=0){
        return true;}
    else {return false;}}

void Case::ajouteParticule(Particule* particule){
  particules.push_back(particule);}

void Case::enleveParticule(Particule* part){
    for (size_t i(0); i<particules.size();i++) {
        if(part==particules[i]){
            particules.erase(particules.begin()+i);}}}

std::vector<Particule*> Case::paticulesQuiInteragissent(Case* avant, Case* apres){
    vector<Particule*>particulesQuiInteragissent;
    particulesQuiInteragissent.reserve(avant->particules.size()+particules.size()+apres->particules.size());
    particulesQuiInteragissent.insert(particulesQuiInteragissent.end(), avant->particules.begin(), avant->particules.end());
    particulesQuiInteragissent.insert(particulesQuiInteragissent.end(), particules.begin(), particules.end());
    particulesQuiInteragissent.insert(particulesQuiInteragissent.end(), apres->particules.begin(), apres->particules.end());
    return particulesQuiInteragissent;
}
