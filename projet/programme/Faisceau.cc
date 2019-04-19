#include "Faisceau.h"
#include "ConstantesPhysiques.h"
#include <vector>
#include <cmath>

using namespace std;
using namespace ConstantesPhysiques;

Faisceau::Faisceau(Particule _ref, long int _nb, double _coef, SupportADessin* _support)
: Dessinable(_support), reference(_ref), nombre_particule(_nb), coef_simulation(_coef) {	
	CollectionPart.push_back(new Particule(reference*=coef_simulation));
	energie_moy = (reference*=coef_simulation).Energie();
	(*this).calcul_ell_vert();
	(*this).calcul_ell_hori();
}

void Faisceau::energie_moyenne(){
	double _energie(0);
	for(auto _particule : CollectionPart) {
		_energie += _particule->Energie();}
	energie_moy = (_energie/CollectionPart.size());}

ostream& Faisceau::affiche(ostream& sortie) const{
	sortie << "Un Faisceau contenant les " << CollectionPart.size() << " particules suivantes:"<< endl;
	for(auto _particule : CollectionPart){
		_particule->affiche(sortie);}
	return sortie;}
	
void Faisceau::bouger(double dt) {
	for (auto _particule : CollectionPart) {
		_particule->ajouteForceMagnetique(_particule->elemCourant()->champMagnetique(_particule->position()), dt);
		_particule->bouger(dt);}
	if((CollectionPart.size()) < (nombre_particule/coef_simulation)) {
		CollectionPart.push_back(new Particule(reference*=coef_simulation));}
	(*this).energie_moyenne();
	(*this).calcul_ell_vert();
	(*this).calcul_ell_vert();}
	
void Faisceau::calcul_ell_vert() {
	double moy_position_carre(0);
	double moy_vitesse_carre(0);
	double moy_position_vitesse(0);
	
	for(auto _particule : CollectionPart){
		moy_position_carre+=pow((_particule->position()).getz(),2);
		moy_vitesse_carre += pow((_particule->vitesse()).getz(),2);
		moy_position_vitesse += ((_particule->position()).getz())*((_particule->vitesse()).getz());}
		
		moy_position_carre /= CollectionPart.size();
		moy_vitesse_carre /= CollectionPart.size();
		moy_position_vitesse /= CollectionPart.size();
		
	emit_verticale = sqrt(moy_position_carre*moy_vitesse_carre - pow(moy_position_vitesse,2));
	
	coef_A22_vert = moy_position_carre / emit_verticale;
	coef_A11_vert = moy_vitesse_carre / emit_verticale;
	coef_A12_vert = (-moy_position_vitesse) / emit_verticale;	
}

void Faisceau::calcul_ell_hori(){
	double moy_position_carre(0);
	double moy_vitesse_carre(0);
	double moy_position_vitesse(0);
	
	for (auto _particule : CollectionPart) {
		moy_position_carre += pow(((_particule->elemCourant())->u((*_particule)))*(_particule->position()),2);
		moy_vitesse_carre += pow(((_particule->elemCourant())->u((*_particule)))*(_particule->vitesse()),2);
		moy_position_vitesse += (((_particule->elemCourant())->u((*_particule)))*(_particule->position()))*(((_particule->elemCourant())->u((*_particule)))*(_particule->vitesse()));}
		
		moy_position_carre /= CollectionPart.size();
		moy_vitesse_carre /= CollectionPart.size();
		moy_position_vitesse/= CollectionPart.size();
		
	emit_horizontale = sqrt(moy_position_carre*moy_vitesse_carre - pow(moy_position_vitesse,2));
	
	coef_A22_hori = moy_position_carre / emit_verticale;
	coef_A11_hori = moy_vitesse_carre / emit_verticale;
	coef_A12_hori = (-moy_position_vitesse) / emit_verticale;		
}
		
	
