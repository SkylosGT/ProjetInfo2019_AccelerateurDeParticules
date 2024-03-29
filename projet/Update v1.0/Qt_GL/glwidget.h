#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>    // Classe pour faire une fenêtre OpenGL
#include <QTime>            // Classe pour gérer le temps
#include "SupportOpenGL.h"
#include "Accelerateur.h"
#include "SectionDroite.h"

class GLWidget : public QOpenGLWidget
/* La fenêtre hérite de QOpenGLWidget ;
 * les événements (clavier, souris, temps) sont des méthodes virtuelles à redéfinir.
 */
{
public:
  GLWidget(QWidget* parent = nullptr)
    : QOpenGLWidget(parent), a(&vue) {}
  virtual ~GLWidget() {}

  void ajoutFaisceau(Faisceau* nouveau){a.ajoutFaisceau(nouveau);}
  void construireAccelerateur(int i){a.construireAccelerateur(i);}

  private:
  // Les 3 méthodes clés de la classe QOpenGLWidget à réimplémenter
  virtual void initializeGL()                  override;
  virtual void resizeGL(int width, int height) override;
  virtual void paintGL()                       override;

  // Méthodes de gestion d'évènements
  virtual void keyPressEvent(QKeyEvent* event) override;
  virtual void timerEvent(QTimerEvent* event)  override;

  // Méthodes de gestion interne
  void pause();

  // Vue : ce qu'il faut donner au contenu pour qu'il puisse se dessiner sur la vue
  SupportOpenGL vue;

  // Timer
  int timerId;
  // pour faire évoluer les objets avec le bon "dt"
  QTime chronometre;

  // Accelerateur à dessiner, faire évoluer
  Accelerateur a;

};

#endif // GLWIDGET_H
