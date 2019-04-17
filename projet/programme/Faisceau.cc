#include "Faisceau.h"
#inlcude "ConstantesPhysiques.h"

using namespace std;
using namespace ConstantesPhysiques;

Faisceau::Faisceau(Particule _ref, long int _nb, double _coef, SupportADessin* _support)
: Dessinable(_support), CollectionParticule((_nb/_coef), (_coef*_ref)), reference(_ref), nombre_particule(_nb), coef_simulation(_coef) 
{	
	//LA CA INJECTE TOUTE LES PARTICULES VOULUES DANS LE FAISCEAU AU MEME MOMENT ET MEME VITESSE DONC BOUGE COMME UNE SEULE? COMMENT FAIRE ? FAUT-IL LES INJECTER UNE PAR UNE ??

	
}

double Faisceau::energie_moyenne() const {
	double _energie;
	for(auto _particule : CollectionParticule) {
		_energie += _particule.Energie();}
	return (_energie/CollectionParticule.size());}

ostream& Faisceau::affiche(ostream& sortie) const{
	sortie << "Un Faisceau contenant les " << CollectionParticule.size() << " particules suivantes:"<< endl;
	for(auto _particule : CollectionParticule){
		_particule.affiche(sortie);}
	return sortie;}
	
void Faisceau::bouger(double dt) {
	for (auto _particule : CollectionParticule) {
		_particule.bouger(dt);}}
		
	
