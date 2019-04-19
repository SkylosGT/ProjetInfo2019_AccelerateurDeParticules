#include <iostream>
#include "SupportConsole.h"
#include "Particule.h"
#include "Dipole.h"
#include "Quadrupole.h"
#include "SectionDroite.h"
#include "Accelerateur.h"
#include "Faisceau.h"

using namespace std;

void SupportConsole::dessine(Particule const& _p){_p.affiche(flot);}

void SupportConsole::dessine(Dipole const& _d){_d.affiche(flot);}

void SupportConsole::dessine(Quadrupole const& _q){_q.affiche(flot);}

void SupportConsole::dessine(SectionDroite const& _s){_s.affiche(flot);}

void SupportConsole::dessine(Faisceau const& _f) {(_f.affiche(flot));}

void SupportConsole::dessine(Accelerateur const& _a){
	if (_a.getCollectionElement().size() > 0) {
		if (_a.getCollectionElement().size() == 1) {
			cout << "L'accélérateur est constitué de l'élément suivant : " << endl;
					(_a.getCollectionElement()[0])->dessine();
					cout << endl;
				}else{
					cout << "L'accélérateur est constitué des " <<_a.getCollectionElement().size() <<" éléments suivantes :"<<endl;
					for (auto element : _a.getCollectionElement()) {
						element->dessine();}}
						cout << endl; } else {
							cout << "L'accélérateur n'est constitué d'aucun élément."<<endl;
						cout << endl;}
	
	if (_a.getCollectionFaisceau().size() > 0) { 
		if (_a.getCollectionFaisceau().size() == 1) {
			cout << "L'accélérateur contient le faisceau suivant : " << endl;
					(*(_a.getCollectionFaisceau()[0])).dessine();
					cout << endl;
				}else{
					cout << "L'accélérateur contient les " <<_a.getCollectionFaisceau().size() <<" faisceaux suivants :"<<endl;
					for (auto faisceau : _a.getCollectionFaisceau()) {
						(*faisceau).dessine();
						cout << endl;}}
						}else{
							cout << "L'accélérateur ne contient aucune particule."<< endl;
							cout << endl;
	}
}
