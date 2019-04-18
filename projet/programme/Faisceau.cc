#include "Faisceau.h"
#include "ConstantesPhysiques.h"
#include <vector>

using namespace std;
using namespace ConstantesPhysiques;

Faisceau::Faisceau(Particule _ref, long int _nb, double _coef, SupportADessin* _support)
: Dessinable(_support), reference(_ref), nombre_particule(_nb), coef_simulation(_coef) {	
	CollectionParticule.push_back(new Particule(reference*=coef_simulation));
	energie_moy = (reference*=coef_simulation).Energie();
	(*this).calcul_ell_vert();
	(*this).calcul_ell_hori();
}

void Faisceau::energie_moyenne(){
	double _energie(0);
	for(auto _particule : CollectionParticule) {
		_energie += _particule->Energie();}
	energie_moy = (_energie/CollectionParticule.size());}

ostream& Faisceau::affiche(ostream& sortie) const{
	sortie << "Un Faisceau contenant les " << CollectionParticule.size() << " particules suivantes:"<< endl;
	for(auto _particule : CollectionParticule){
		_particule->affiche(sortie);}
	return sortie;}
	
void Faisceau::bouger(double dt) {
	for (auto _particule : CollectionParticule) {
		_particule->ajouteForceMagnetique(_particule->elemCourant()->champMagnetique(_particule->position()), dt);
		_particule->bouger(dt);}
	if((CollectionParticule.size()) < (nombre_particule/coef_simulation)) {
		CollectionParticule.push_back(new Particule(reference*=coef_simulation));}
	(*this).energie_moyenne();
	(*this).calcul_ell_vert();
	(*this).calcul_ell_vert();}
	
void Faisceau::calcul_ell_vert() {
/*	double moy_position_carre;
	for(auto _particule : CollectionParticule){
		moy_position_carre+=(_particule.position()).getz()*/
		
}

void Faisceau::calcul_ell_hori(){
}
		
	
