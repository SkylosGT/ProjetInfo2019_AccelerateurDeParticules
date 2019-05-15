#include "FaisceauCirculaire.h"
#include <iostream>
using namespace std;

//DEFINITION DES METHODES DE LA SOUS CLASSE FAISCEAUCIRUCLAIRE

FaisceauCirculaire::FaisceauCirculaire(Particule _ref,long int _nb, double _coef, SupportADessin* _support) 
: Faisceau(_ref,_nb, _coef, _support)
{	CollectionPart.push_back(new Particule(reference*=coef_simulation));
	energie_moy = (reference*=coef_simulation).Energie();
}

void FaisceauCirculaire::bouger(double dt) {
	for (auto particule : CollectionPart) {
		particule->ajouteForceMagnetique(particule->elemCourant()->champMagnetique(particule->position()), dt);
		for(auto part : CollectionPart){
			if(not((*part)==(*particule))){
				particule->ajouteInteractionParticule(*(part));}}
		particule->bouger(dt);}
	if((CollectionPart.size()) < (nombre_particule/coef_simulation)) {
		CollectionPart.push_back(new Particule(reference*=coef_simulation));}
	(*this).energie_moyenne();
	(*this).calcul_ell_vert();
	(*this).calcul_ell_vert();}

ostream& FaisceauCirculaire::affiche(ostream& sortie) const{
	sortie << "Un Faisceau Circulaire contenant les " << CollectionPart.size() << " particules suivantes:"<< endl;
	for(auto _particule : CollectionPart){
		_particule->affiche(sortie);}
	return sortie;}
	
