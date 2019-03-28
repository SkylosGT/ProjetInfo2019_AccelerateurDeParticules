#include <iostream>
#include "Accelerateur.h"
#include <vector>

using namespace std;

Accelerateur::Accelerateur() 
	: CollectionElement(), CollectionParticule() {}
	
ostream& Accelerateur::affiche(ostream& sortie) const {
	if (CollectionElement.size() > 0) {
		if (CollectionElement.size() == 1) {
			sortie << "L'accélérateur est constitué de l'élément suivant : " << endl
					<<CollectionElement[0]<< endl; 
				}else{
					sortie << "L'accélérateur est constitué des " <<CollectionElement.size() <<" éléments suivantes :"<<endl;
					for (auto element : CollectionElement) {
						sortie << element<< endl; }}}
	
	if (CollectionParticule.size() > 0) {
		if (CollectionParticule.size() == 1) {
			sortie << "L'accélérateur contient la particule suivante : " << endl
					<<CollectionParticule[0]<<endl;
				}else{
					sortie << "L'accélérateur contient les " <<CollectionParticule.size() <<" particules suivantes :"<<endl;
					for (auto particule : CollectionParticule) {
						sortie << particule << endl; }}}
	
	return sortie; }
	
void Accelerateur::ajoutParticule(Particule nouveau) {
	CollectionParticule.push_back(nouveau); }
	
void Accelerateur::ajoutElement(Element nouveau) {
	CollectionElement.push_back(nouveau);}
	
void Accelerateur::supprCollectionElement() {
	CollectionElement.clear();}
	
void Accelerateur::supprCollectionParticule() {
	CollectionParticule.clear();}
	
void Accelerateur::evolue() const{
	cout <<"Méthode évolue debbuging" << endl;}
	
ostream& operator<<(ostream& sortie, Accelerateur const& a){
	return a.affiche(sortie);}
	
