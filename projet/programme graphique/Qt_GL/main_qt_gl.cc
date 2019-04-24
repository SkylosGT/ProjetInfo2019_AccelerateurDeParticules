#include <QApplication>
#include "glwidget.h"

int main(int argc, char* argv[])
{

  QApplication a(argc, argv);
  GLWidget w;
  w.construireAccelerateur();
  w.show();

  return a.exec();
}
