#include <QApplication>
#include "glwidget.h"
#include "Particule.h"
#include "SectionDroite.h"

int main(int argc, char* argv[])
{

  QApplication a(argc, argv);
  GLWidget w;
  Particule p((*new Vecteur3D), (*new Vecteur3D), 0,0);
  SectionDroite s((*new Vecteur3D), (*new Vecteur3D(1,0,0)), 0.5);
  w.ajoutElement(&s);
  w.ajoutParticule(&p);
  w.show();

  return a.exec();
}
