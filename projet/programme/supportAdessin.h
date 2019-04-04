#ifndef SUPPORTADESSIN_H
#define SUPPORTADESSIN_H

class Particule;
class Dipole;
class Quadrupole;
class SectionDroite;

class SupportADessin
{
 public:
  virtual ~SupportADessin() {}

  virtual void dessine(Particule const& a_dessiner)=0;
  virtual void dessine(Dipole const& a_dessiner)=0;
  virtual void dessine(Quadrupole const& a_dessiner)=0;
  virtual void dessine(SectionDroite const& a_dessiner)=0;

  /* Mettre ici toutes les méthodes nécessaires pour dessiner tous les
   * objets que l'on veut dessiner. Par exemple :
   *    virtual void dessine(Nounours const& a_dessiner) = 0;
   *    virtual void dessine(Voiture  const& a_dessiner) = 0;
   */
};

#endif
