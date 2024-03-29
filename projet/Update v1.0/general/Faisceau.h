/*Classe Abstraite*/
/*Hérite : Dessinable.h*/

#pragma once

#include <vector>
#include "Dessinable.h"
#include "SupportADessin.h"

#include "Vecteur3D.h"

#include "Particule.h"

//En tête de la sous classe Faisceau de Dessinable avec descriptions de ses méthodes. Corps dans "Faisceau.h"
class Faisceau : public Dessinable {

    protected :

/*Attributs protégés d'un faisceau (uniquement accessible par ses sous classes)*/

	Particule reference; //La particule de réference qui indique toutes les caractéristiques des particules du faisceau
	long int nombre_particule; // Nombre de vraies partiules du faisceau
	double coef_simulation;	//Facteur des macro-particules simulées 
	std::vector<Particule*> CollectionPart; //Tableau de particules (contenant toutes les particules du faisceau)
	double energie_moy; //Moyenne des énergies des particules qui compose le faisceau
	
	double emit_verticale; //Emittance du faisceau suivant l'axe vertical
	double coef_A11_vert; //Coefficient A11 des ellipses de phases suivant l'axe vertical
	double coef_A12_vert; //Coefficient A12 des ellipses de phases suivant l'axe vertical
	double coef_A22_vert; //Coefficient A22 des ellipses de phases suivant l'axe vertical
	
	double emit_horizontale; // Emittance du faisceau suivant l'axe horizontal
	double coef_A11_hori; //Coefficient A11 des ellipses de phases suivant l'axe horizontal
	double coef_A12_hori; //Coefficient A12 des ellipses de phases suivant l'axe horizontal
	double coef_A22_hori; //Coefficient A22 des ellipses de phases suivant l'axe horizontal
	
	public:

	//Constructeur d'un faisceau qui initialise par défaut le support comme pointant sur rien
	Faisceau(Particule,long int, double, SupportADessin* _support=nullptr);

    //Destructeur du faisceau
    ~Faisceau();

	//Getter, retourne la colllection de particule du faisceau
	std::vector<Particule*> getCollectionPart() const {return CollectionPart;}

	//Getter, retourne la particule de référence du faisceau
    Particule particuleDeReference() const {return reference;}
	
/*Méthodes publiques de l'interface de la classe Faisceau*/

	//Méthode qui calcul l'énergie du faisceau dans son attribut energie_moy
	void energie_moyenne();
	
	//Méthode virtuelle pure qui affiche un faisceau (utilisé pour dessiner un faisceau sur une console)
	virtual std::ostream& affiche(std::ostream&) const =0;
    
    //Méthode virtuelle pure qui fait bouger l'ensemble des particules d'un faisceau en fonction du type de faisceau
    virtual void bouger(double) = 0;
    
    //Calcul de l'émittance verticale dans l'attribut emit_verticale
    void calcul_ell_vert(); 
    
    //Calcul de l'émittance horizontale dans l'attribut emit_horizontale
    void calcul_ell_hori();

    //Modifie l'element courant de la particule de reference
	void changerElementDeLaParticuleDeReference(Element*);

    //Modifie la case courante de la particule de reference
    void changerCaseDeLaParticuleDeReference(int);

    //Fait passer une particule de la collection de particules à l'élément suivant
    void passeAuSuivant();

    //Change le support à dessin d'un faisceau
	virtual void change_support(SupportADessin*) override;

    //Lance des particules
    virtual void lanceParticule(double)=0;
};
