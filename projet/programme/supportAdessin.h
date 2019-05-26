#pragma once

class Faisceau;
class Particule;
class Dipole;
class Quadrupole;
class SectionDroite;
class Accelerateur;

class SupportADessin
{
 public:
  virtual ~SupportADessin() {}

  virtual void dessine(Accelerateur const& a_dessiner)=0;
  virtual void dessine(Faisceau const& a_dessiner)=0;
  virtual void dessine(Particule const& a_dessiner)=0;
  virtual void dessine(Dipole const& a_dessiner)=0;
  virtual void dessine(Quadrupole const& a_dessiner)=0;
  virtual void dessine(SectionDroite const& a_dessiner)=0;
  
  private:
    SupportADessin(SupportADessin const&) = deleted;
    SupportADessin& operator=(SupportADessin const&) = deleted;

};


