/*Classe abstraite*/

#pragma once

class Particule;
class Dipole;
class Quadrupole;
class SectionDroite;
class Accelerateur;
class FaisceauCirculaire;
class MailleFODO;

//En tête de la classe SupportADessin avec descriptions de ses méthodes
class SupportADessin
{
    public:

    //Un destructeur par défaut
    virtual ~SupportADessin() {}

/*Des méthodes virtuelles pure qui dessine (en fonction de l'argument = surcharge) accélérateur, faisceau ciruclaire, particules, dipole,
 * quadrupole et section droite. Ces méthodes seront redéfinies par les sous classes de SuppoprtADessin afin de pouvoir dessiner un accélérateur
 * dans sa totalité sur différents supports*/

  virtual void dessine(Accelerateur const& a_dessiner)=0;
  virtual void dessine(FaisceauCirculaire const& a_dessiner)=0;
  virtual void dessine(Particule const& a_dessiner)=0;
  virtual void dessine(Dipole const& a_dessiner)=0;
  virtual void dessine(Quadrupole const& a_dessiner)=0;
  virtual void dessine(SectionDroite const& a_dessiner)=0;
  virtual void dessine(MailleFODO const& a_dessiner)=0;
};


