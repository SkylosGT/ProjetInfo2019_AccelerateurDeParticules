#ifndef TEXT_VIEWER_H
#define TEXT_VIEWER_H

#include <iostream>
#include "SupportADessin.h"

class SupportConsole : public SupportADessin {
 public:
 SupportConsole(std::ostream& flot)
    : flot(flot)
  {}
  virtual ~SupportConsole() {}

  virtual void dessine(Contenu const& a_dessiner) override;
  virtual void dessine(Particule const& a_dessiner) override;

 private:
  std::ostream& flot;
};

#endif