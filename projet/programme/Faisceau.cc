#include "Faisceau.h"
#include "ConstantesPhysiques.h"

#include <vector>
#include <cmath>

#include "ElementDroit.h"
#include "ElementCourbe.h"

using namespace ConstantesPhysiques;

Faisceau::Faisceau(Particule _ref, long int _nb, double _coef, SupportADessin* _support)
: Dessinable(_support), reference(_ref), nombre_particule(_nb), coef_simulation(_coef) {}

void Faisceau::energie_moyenne(){
	double _energie(0);
	for(auto _particule : CollectionPart) {
		_energie += _particule->Energie();}
	energie_moy = (_energie/CollectionPart.size());}
		
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

void Faisceau::changerElementDeLaParticuleDeReference(Element* element){
	reference.change_element(element);}
		
	
