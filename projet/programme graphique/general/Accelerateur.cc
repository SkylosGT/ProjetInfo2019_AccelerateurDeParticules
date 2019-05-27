#include <iostream>
#include <vector>
#include <math.h>

#include "Accelerateur.h"
#include "ConstantesPhysiques.h"
#include "Dipole.h"
#include "maillefodo.h"

//DEFINITION DES METHODES DE LA CLASSE ACCELERATEUR ET SURCHARGE DE SES OPERATEUR

using namespace std;
using namespace ConstantesPhysiques;

//DEFINTION DES MÉTHODES PUBLIQUES DE LA CLASSE ACCELERATEUR
Accelerateur::Accelerateur(SupportADessin* _support) 
    : Dessinable(_support), CollectionElement(), CollectionParticule() ,CollectionFaisceau(), angleDeSegmentation(0), rayon(0) {}
	
/*ostream& Accelerateur::affiche(ostream& sortie) const {
	if (CollectionElement.size() > 0) {
		if (CollectionElement.size() == 1) {
			sortie << "L'accélérateur est constitué de l'élément suivant : " << endl
					<<*(CollectionElement[0])<< endl; 
				}else{
					sortie << "L'accélérateur est constitué des " <<CollectionElement.size() <<" éléments suivantes :"<<endl;
					for (auto element : CollectionElement) {
						sortie << *element<< endl; }}
						sortie << endl; } else {
							sortie << "L'accélérateur n'est constitué d'aucun élément."<<endl;
						sortie << endl;}
	if (CollectionParticule.size() > 0) { 
		if (CollectionParticule.size() == 1) {
			sortie << "L'accélérateur contient la particule suivante : " << endl
					<<*CollectionParticule[0]<<endl;
				}else{
					sortie << "L'accélérateur contient les " <<CollectionParticule.size() <<" particules suivantes :"<<endl;
					for (auto particule : CollectionParticule) {
						sortie << *particule << endl; }}
						}else{
							sortie << "L'accélérateur ne contient aucune particule."<< endl;}
	return sortie; }*/
	
void Accelerateur::ajoutFaisceau(Faisceau* nouveau) {
    nouveau->changerElementDeLaParticuleDeReference(trouveElementDeLaParticule(nouveau->particuleDeReference()));
    nouveau->getCollectionPart()[0]->change_element(trouveElementDeLaParticule(nouveau->particuleDeReference()));
    int i(0); while(!CollectionCases[i]->particuleCollider(nouveau->particuleDeReference())){i++;}
    nouveau->changerCaseDeLaParticuleDeReference(i);
	nouveau->change_support(support);
    CollectionFaisceau.push_back(nouveau);}
	
void Accelerateur::ajoutParticule(Particule* nouveau) {
	nouveau->change_element(trouveElementDeLaParticule(*nouveau));
	nouveau->change_support(support);
    CollectionParticule.push_back(nouveau);}
	
void Accelerateur::ajoutElement(Element* nouveau) {
    if(CollectionElement.size()>0){
        for (auto element : CollectionElement) {
            attacheElements(element, nouveau);}}
	nouveau->change_support(support);
    CollectionElement.push_back(nouveau);}
	
void Accelerateur::supprCollectionParticule() {
	CollectionParticule.clear();}
	
void Accelerateur::supprCollectionElement() {
	CollectionElement.clear();}
	
void Accelerateur::supprCollectionFaisceau() {
	CollectionFaisceau.clear();}
	
void Accelerateur::evolue(double _dt) const{
	if(CollectionFaisceau.size()>0){
		for(Faisceau* faisceau : CollectionFaisceau){
            (*faisceau).bouger(_dt);
            faisceau->passeAuSuivant();
            for (auto particule:faisceau->getCollectionPart()) {
                if(!CollectionCases[particule->caseParticule()]->particuleCollider(*particule)){
                    CollectionCases[particule->caseParticule()]->enleveParticule(particule);
                    CollectionCases[changeIndiceCase(particule->caseParticule())]->ajouteParticule(particule);
                    particule->change_case(changeIndiceCase(particule->caseParticule()));}}}}

    /*if(CollectionParticule.size()>0){
		for(auto particule : CollectionParticule){
        cout<<*((*particule).elemCourant())<<endl;
		(*particule).ajouteForceMagnetique((*particule).elemCourant()->champMagnetique((*particule).position()), _dt);
		(*particule).bouger(_dt);
		if((*particule).elemCourant()->passe_au_suivant((*particule))){
            (*particule).change_element((*particule).elemCourant()->elemSuivant());}}}*/}

Element* Accelerateur::trouveElementDeLaParticule(Particule const& particule) const {
	if(CollectionElement.size()>0){
        for (auto element : CollectionElement) {
            if(element->element_particule(particule.position())){return element;}}}}

void Accelerateur::attacheElements(Element* element1, Element * element2){
    if(element1->sortie()==element2->entree()){element1->attacheElementSuivant(element2);}
    if(element2->sortie()==element1->entree()){element2->attacheElementSuivant(element1);}}

void Accelerateur::construireAccelerateur(int taille){

    double Re(0.1), b(1.2), Rc(1), Bz(5.89158), L(1), epsilon(10e-3);
    Vecteur3D vec_re(-2,3,0), vec_rs(2, 3, 0), re_d(-3,2,0), rs_d(-2,3,0);

    rayon=taille*2+1;
    angleDeSegmentation=(2*M_PI)/(round(2*M_PI/atan(epsilon/3)));

    segmenterEspace(round(2*M_PI/atan(epsilon/3)));

    for (size_t i(0); i<4; i++) {
        cout<<i<<endl;
            ajoutElement(new Dipole(re_d.rotation(vec_e3, (M_PI/2)),rs_d.rotation(vec_e3, (M_PI/2)),Re,Rc,Bz));
            ajoutElement(new MailleFODO(vec_re.rotation(vec_e3, (M_PI/2)), vec_rs.rotation(vec_e3, (M_PI/2)), Re, b, L));}}

void Accelerateur::segmenterEspace(int taille){
    for (size_t i(0);i<taille;i++) {
        CollectionCases.push_back(new Case(i, angleDeSegmentation, rayon));}
}

int Accelerateur::changeIndiceCase(int i) const{
    if(i<CollectionCases.size()-1){return i+1;}
    else {return 0;}}

/*//OPERATEUR EXTERNE A LA CLASSE PARTICULE UTILISANT UNE METHODE DE LA CLASSE
ostream& operator<<(ostream& sortie, Accelerateur const& a){
	return a.affiche(sortie);}*/

