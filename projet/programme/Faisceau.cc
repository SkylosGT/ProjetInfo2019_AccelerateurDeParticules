#include "Faisceau.h"
#inlcude "ConstantesPhysiques.h"

using namespace std;
using namespace ConstantesPhysiques;

Faisceau::Faisceau(Particule _ref, long int _nb, double _coef, SupportADessin* _support)
: Dessinable(_support), CollectionParticule((_nb/_coef), (_coef*_ref)), reference(_ref), nombre_particule(_nb), coef_simulation(_coef) 
{	energie_moyenne = reference.Energie();
	

	
	/*METTRE PLEIN DE BAILS LA*/}


ostream& Faisceau::affiche(ostream& sortie) const{
	return reference.affiche(sortie);}
	
void Faisceau::bouger(double dt) {
	reference.bouger(dt);}
	
