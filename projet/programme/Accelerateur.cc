#include <iostream>
#include <vector>

#include "Accelerateur.h"

//DEFINITION DES METHODES DE LA CLASSE ACCELERATEUR ET SURCHARGE DE SES OPERATEUR

using namespace std;

//DEFINTION DES MÉTHODES PUBLIQUES DE LA CLASSE ACCELERATEUR
Accelerateur::Accelerateur(SupportADessin* _support) 
	: Dessinable(_support), CollectionElement(), CollectionParticule() {}
	
ostream& Accelerateur::affiche(ostream& sortie) const {
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
					<<CollectionParticule[0]<<endl;
				}else{
					sortie << "L'accélérateur contient les " <<CollectionParticule.size() <<" particules suivantes :"<<endl;
					for (auto particule : CollectionParticule) {
						sortie << particule << endl; }}
						}else{
							sortie << "L'accélérateur ne contient aucune particule."<< endl;}
	
	return sortie; }
	
void Accelerateur::ajoutParticule(Particule nouveau) {
	CollectionParticule.push_back(nouveau); }
	
void Accelerateur::ajoutElement(Element* nouveau) {
	if(CollectionElement.size()>0){
		(*nouveau).attache_element_suivant(CollectionElement[0]);
		(*CollectionElement.back()).attache_element_suivant(nouveau);}
	CollectionElement.push_back(nouveau);}
	
void Accelerateur::supprCollectionParticule() {
	CollectionParticule.clear();}
	
void Accelerateur::supprCollectionElement() {
	CollectionElement.clear();}
	
void Accelerateur::evolue() const{
	cout <<"Méthode évolue debbuging" << endl;}
	
	
//OPERATEUR EXTERNE A LA CLASSE PARTICULE UTILISANT UNE METHODE DE LA CLASSE
ostream& operator<<(ostream& sortie, Accelerateur const& a){
	return a.affiche(sortie);}
	
