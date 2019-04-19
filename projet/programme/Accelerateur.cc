#include <iostream>
#include <vector>

#include "Accelerateur.h"
#include "ConstantesPhysiques.h"

//DEFINITION DES METHODES DE LA CLASSE ACCELERATEUR ET SURCHARGE DE SES OPERATEUR

using namespace std;
using namespace ConstantesPhysiques;

//DEFINTION DES MÉTHODES PUBLIQUES DE LA CLASSE ACCELERATEUR
Accelerateur::Accelerateur(SupportADessin* _support) 
	: Dessinable(_support), CollectionElement(), CollectionFaisceau() {}
	
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
	CollectionFaisceau.push_back(nouveau);}
	
void Accelerateur::ajoutParticule(Particule* nouveau) {
	double distanceMinimum(const_c);
	Element* elementAvecDistanceMinimum(nullptr);
	if(CollectionElement.size()>0){
		for(auto element:CollectionElement){
			if(element->distance_particule(*nouveau)<distanceMinimum){
				distanceMinimum=element->distance_particule(*nouveau);
				elementAvecDistanceMinimum=element;}}}
	nouveau->change_element(elementAvecDistanceMinimum);
	CollectionParticule.push_back(nouveau);}
	
void Accelerateur::ajoutElement(Element* nouveau) {
	if(CollectionElement.size()>0){
		for(auto element : CollectionElement){
			element->attache_element_suivant(nouveau);}
		for(auto element : CollectionElement){
			nouveau->attache_element_suivant(element);}}
	CollectionElement.push_back(nouveau);}
	
void Accelerateur::supprCollectionParticule() {
	CollectionParticule.clear();}
	
void Accelerateur::supprCollectionElement() {
	CollectionElement.clear();}
	
void Accelerateur::supprCollectionFaisceau() {
	CollectionFaisceau.clear();}
	
void Accelerateur::evolue(double _dt) const{
	for(Faisceau* faisceau : CollectionFaisceau){
		faisceau->bouger(_dt);}
		
	for(auto particule : CollectionParticule)
{
		(*particule).ajouteForceMagnetique((*particule).elemCourant()->champMagnetique((*particule).position()), _dt);
		(*particule).bouger(_dt);
		if((*particule).elemCourant()->passe_au_suivant((*particule))){
			(*particule).change_element((*particule).elemCourant()->elemSuivant());}}}
	
/*//OPERATEUR EXTERNE A LA CLASSE PARTICULE UTILISANT UNE METHODE DE LA CLASSE
ostream& operator<<(ostream& sortie, Accelerateur const& a){
	return a.dessine();}*/
	
