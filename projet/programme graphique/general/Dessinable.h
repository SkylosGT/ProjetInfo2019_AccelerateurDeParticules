#pragma once

class SupportADessin;


//En tête de la classe virtuelle Dessinable 
class Dessinable {
 public:
 //Un constructeur qui initialise les attributs de Dessinable
  Dessinable(SupportADessin* support)
    : support(support)
  {}
  
  //Un destructeur par défaut
  virtual ~Dessinable() {}
  
  //Une méthode virtuelle dessine qui sera redéfini dans les sous classes de Dessinable
  virtual void dessine() = 0;

  virtual void change_support(SupportADessin* nouveau){support=nouveau;}

 protected:
 //Un pointeur sur un support a dessin comme attribut uniquement accessible pour ses sous classes
  SupportADessin* support;
};
