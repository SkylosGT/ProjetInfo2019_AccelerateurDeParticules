#include <iostream>
#include "Accelerateur.h"
#include <vector>

using namespace std;

Accelerateur::Accelerateur() 
	: CollectionElement(), CollectionParticule() {}
	
ostream& Accelerateur::affiche(ostream& sortie) const {
	/*if (CollectionElement.size() > 0) {
		if (CollectionElement.size() == 1) {
			sortie << "L'accélérateur est constitué de l'élément suivant : " << endl
					<<CollectionElement[0].affiche(sortie)<< endl; 
				}else{
					sortie << "L'accélérateur est constitué des " <<CollectionElement.size() <<" éléments suivantes :"<<endl;
					for (auto element : CollectionElement) {
						sortie << element.affiche(sortie) << endl; }}}*/
	
	if (CollectionParticule.size() > 0) {
		if (CollectionParticule.size() == 1) {
			sortie << "L'accélérateur contient la particule suivante : " << endl
					<<CollectionParticule[0]<<endl;
					sortie << "L'accélérateur contient les " <<CollectionParticule.size() <<" particules suivantes :"<<endl;
					for (auto particule : CollectionParticule) {
						sortie << particule << endl; }}}
	
	return sortie; }
	
	
	
