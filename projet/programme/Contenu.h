#ifndef CONTENU_H
#define CONTENU_H

#include "Dessinable.h"
#include "SupportADessin.h"

class Contenu : public Dessinable {
public:
  Contenu(SupportADessin* vue)
    : Dessinable(vue)
  {}
  virtual ~Contenu() {}

  virtual void dessine() override
  { support->dessine(*this); }
};

#endif // CONTENU_H
