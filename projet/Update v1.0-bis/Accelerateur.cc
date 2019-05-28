
#define _USE_MATH_DEFINES

#include <iostream>
#include <vector>
#include <math.h>

#include "Accelerateur.h"
#include "ConstantesPhysiques.h"
#include "Dipole.h"
#include "MailleFODO.h"

using namespace std;
using namespace ConstantesPhysiques;

//DEFINITION DES METHODES DE LA CLASSE ACCELERATEUR ET SURCHARGE DE SES OPERATEUR

//DEFINTION DES MÉTHODES PUBLIQUES DE LA CLASSE ACCELERATEUR
Accelerateur::Accelerateur(SupportADessin* _support) 
    : Dessinable(_support), CollectionElement() ,CollectionFaisceau(), angleDeSegmentation(0), rayon(0) {}
	
Accelerateur::~Accelerateur(){
    supprCollectionFaisceau();
    supprCollectionElement();
    supprCollectionCases();}

void Accelerateur::ajoutFaisceau(Faisceau* nouveau) {
    nouveau->changerElementDeLaParticuleDeReference(trouveElementDeLaParticule(nouveau->particuleDeReference()));
    nouveau->getCollectionPart()[0]->change_element(trouveElementDeLaParticule(nouveau->particuleDeReference()));
    int i(0); while(!CollectionCases[i]->particuleCollider(nouveau->particuleDeReference())){i++;}
    nouveau->changerCaseDeLaParticuleDeReference(i);
	nouveau->change_support(support);
    CollectionFaisceau.push_back(nouveau);}
	
void Accelerateur::ajoutElement(Element* nouveau) {
    if(CollectionElement.size()>0){
        for (auto element : CollectionElement) {
            attacheElements(element, nouveau);}}
	nouveau->change_support(support);
    CollectionElement.push_back(nouveau);}
	
void Accelerateur::supprCollectionElement() {
    for (auto element: CollectionElement) {
        delete element;}
	CollectionElement.clear();}
	
void Accelerateur::supprCollectionFaisceau() {
	CollectionFaisceau.clear();}

void Accelerateur::supprCollectionCases(){
    for (auto c:CollectionCases) {
        delete c;}
    CollectionCases.clear();}
	
void Accelerateur::evolue(double _dt) const{
	if(CollectionFaisceau.size()>0){
		for(Faisceau* faisceau : CollectionFaisceau){
            //interactionParticules(faisceau);
            (*faisceau).bouger(_dt);
            faisceau->passeAuSuivant();
            passeCaseSuivante(faisceau);}}}

Element* Accelerateur::trouveElementDeLaParticule(Particule const& particule) const {
	if(CollectionElement.size()>0){
        for (auto element : CollectionElement) {
            if(element->particuleCollider(particule.position())){return element;}}}}

void Accelerateur::attacheElements(Element* element1, Element * element2) const{
    if(element1->sortie()==element2->entree()){element1->attacheElementSuivant(element2);}
    if(element2->sortie()==element1->entree()){element2->attacheElementSuivant(element1);}}

void Accelerateur::construireAccelerateur(int taille){
    double Re(0.1), b(1.2), Rc(1), Bz(5.89158), L(1), epsilon(10e-3);
    rayon=taille*2+1;
    angleDeSegmentation=(2*M_PI)/(round(2*M_PI/atan(epsilon/3)));
    segmenterEspace(round(2*M_PI/atan(epsilon/3)));
    Vecteur3D vec_re(-2,3,0), vec_rs(2, 3, 0), re_d(-3,2,0), rs_d(-2,3,0);

    for (size_t i(0); i<4; i++) {
        ajoutElement(new Dipole(re_d.rotation(vec_e3, (M_PI/2)),rs_d.rotation(vec_e3, (M_PI/2)),Re,Rc,Bz));
           ajoutElement(new MailleFODO(vec_re.rotation(vec_e3, (M_PI/2)), vec_rs.rotation(vec_e3, (M_PI/2)), Re, b, L)); }}

void Accelerateur::segmenterEspace(int taille){
    for (size_t i(0);i<taille;i++) {
        CollectionCases.push_back(new Case(i, angleDeSegmentation, rayon));}}

int Accelerateur::caseSuivante(int i) const{
    if(i<CollectionCases.size()-1){return i+1;}
    else {return 0;}}

int Accelerateur::casePrecedente(int i) const{
    if(i>0){return i-1;}
    else{return CollectionCases.size()-1;}}

void Accelerateur::passeCaseSuivante(Faisceau* faisceau) const{
    for (auto particule:faisceau->getCollectionPart()) {
        if(!CollectionCases[particule->caseParticule()]->particuleCollider(*particule)){
            CollectionCases[particule->caseParticule()]->enleveParticule(particule);
            CollectionCases[caseSuivante(particule->caseParticule())]->ajouteParticule(particule);
            particule->change_case(caseSuivante(particule->caseParticule()));}}}

void Accelerateur::interactionParticules(Faisceau* faisceau) const{
    for (auto particule: faisceau->getCollectionPart()) {
        for(auto _particule: CollectionCases[particule->caseParticule()]->paticulesQuiInteragissent(CollectionCases[caseSuivante(particule->caseParticule())], CollectionCases[casePrecedente(particule->caseParticule())])){
            if(not((*particule)==(*_particule))){
                _particule->ajouteInteractionParticule(*particule);}}}}
