/*Hérite : SupportADessin.h*/

#include <iostream>

#include "SupportADessin.h"

//En tête de la classe SupportConsole avec descriptions de ses méthodes. Corps dans "SupportConsole.cc"
class SupportConsole : public SupportADessin {
	
 private:

 //Un ostream en attribut privé qui permet de dessiner sur la console
  std::ostream& flot;
 
 public:

 //Un constructeur
 SupportConsole(std::ostream& flot)
    : flot(flot)
  {}
  
  //Un destructeur par défaut
  virtual ~SupportConsole() {}

  //Redéfinition des méthodes dessine héritées de SupportADessin qui dessine l'argument sur la console
  virtual void dessine(Accelerateur const& a_dessiner) override;
  virtual void dessine(FaisceauCirculaire const& a_dessiner) override;
  virtual void dessine(Particule const& a_dessiner) override;
  virtual void dessine(Dipole const& a_dessiner) override;
  virtual void dessine(Quadrupole const& a_dessiner) override;
  virtual void dessine(SectionDroite const& a_dessiner) override;
  virtual void dessine(MailleFODO const& a_dessiner) override;
};
