#include "FaisceauCirculaire.h"

using namespace std;

//DEFINITION DES METHODES DE LA SOUS CLASSE FAISCEAUCIRUCLAIRE

FaisceauCirculaire::FaisceauCirculaire(Particule _ref,long int _nb, double _coef, double dt_lancement, SupportADessin* _support)
: Faisceau(_ref,_nb, _coef, _support), dt_lancement(dt_lancement)
{	CollectionPart.push_back(new Particule(reference*=coef_simulation));
	energie_moy = (reference*=coef_simulation).Energie();
    tmp=0;
}

void FaisceauCirculaire::bouger(double dt) {
	for (auto _particule : CollectionPart) {
		_particule->ajouteForceMagnetique(_particule->elemCourant()->champMagnetique(_particule->position()), dt);
        //for(auto part : CollectionPart){
            //if(not((*part)==(*_particule))){
                //_particule->ajouteInteractionParticule(*part);}}
		_particule->bouger(dt);}
    lanceParticule(dt);
	(*this).energie_moyenne();
	(*this).calcul_ell_vert();
	(*this).calcul_ell_vert();}

ostream& FaisceauCirculaire::affiche(ostream& sortie) const{
	sortie << "Un Faisceau Circulaire contenant les " << CollectionPart.size() << " particules suivantes:"<< endl;
	for(auto _particule : CollectionPart){
		_particule->affiche(sortie);}
	return sortie;}
	
void FaisceauCirculaire::lanceParticule(double dt){
    if(tmp>=dt_lancement){
    if((CollectionPart.size()) < (nombre_particule/coef_simulation)) {
        CollectionPart.push_back(new Particule(reference*=coef_simulation));
    tmp=0;}}
    else {
        tmp+=dt;
    }
}
