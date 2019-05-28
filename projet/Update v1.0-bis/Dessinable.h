/*Classe abstraite*/

#pragma once

class SupportADessin;


//En tête de la classe virtuelle Dessinable. Tout objet pouvant être représenté visuellement en hérite
class Dessinable {
    public:

    //Un constructeur qui initialise les attributs de Dessinable
        Dessinable(SupportADessin* support) : support(support) {}
  
    //Un destructeur par défaut
        virtual ~Dessinable() {}

/*Méthodes de l'interface de la classe Dessinable*/

    //Une méthode virtuelle dessine qui sera redéfinie dans les sous classes de Dessinable
        virtual void dessine() = 0;

    //Change le support à dessin d'un objet dessinable
        virtual void change_support(SupportADessin* nouveau){support=nouveau;}

    protected:

/*Attributs protégés d'un dessinable*/

        SupportADessin* support;//Un pointeur sur un support a dessin comme attribut uniquement accessible pour ses sous classes
};
