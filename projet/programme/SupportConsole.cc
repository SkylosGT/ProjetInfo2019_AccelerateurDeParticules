#include <iostream>
#include "SupportConsole.h"
#include "Particule.h"
#include "Dipole.h"
#include "Quadrupole.h"
#include "SectionDroite.h"
#include "Accelerateur.h"

using namespace std;

void SupportConsole::dessine(Particule const& _p){_p.affiche(flot);}

void SupportConsole::dessine(Dipole const& _d){_d.affiche(flot);}

void SupportConsole::dessine(Quadrupole const& _q){_q.affiche(flot);}

void SupportConsole::dessine(SectionDroite const& _s){_s.affiche(flot);}

void SupportConsole::dessine(Accelerateur const& _a){
	if (_a.getCollectionEl().size() > 0) {
		if (_a.getCollectionEl().size() == 1) {
			cout << "L'accélérateur est constitué de l'élément suivant : " << endl;
					(_a.getCollectionEl()[0])->dessine();
					cout << endl;
				}else{
					cout << "L'accélérateur est constitué des " <<_a.getCollectionEl().size() <<" éléments suivantes :"<<endl;
					for (auto element : _a.getCollectionEl()) {
						element->dessine();}}
						cout << endl; } else {
							cout << "L'accélérateur n'est constitué d'aucun élément."<<endl;
						cout << endl;}
	
	if (_a.getCollectionPa().size() > 0) { 
		if (_a.getCollectionPa().size() == 1) {
			cout << "L'accélérateur contient la particule suivante : " << endl;
					(_a.getCollectionPa()[0]).dessine();
					cout << endl;
				}else{
					cout << "L'accélérateur contient les " <<_a.getCollectionPa().size() <<" particules suivantes :"<<endl;
					for (auto particule : _a.getCollectionPa()) {
						particule.dessine();
						cout << endl;}}
						}else{
							cout << "L'accélérateur ne contient aucune particule."<< endl;
							cout << endl;
	}
}
