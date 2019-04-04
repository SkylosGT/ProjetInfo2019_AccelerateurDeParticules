#include <iostream> // pour endl
#include "SupportConsole.h"
#include "Contenu.h"
#include "Particule.h"

void SupportConsole::dessine(Contenu const&)
{
  /* Dans ce premier exemple très simple, on n'utilise       *
   * pas l'argument Contenu. Nous ne l'avons donc pas nommé. */

  flot << "un cube" << std::endl;
}

void SupportConsole::dessine(Particule const& _p){_p.affiche(flot);}
