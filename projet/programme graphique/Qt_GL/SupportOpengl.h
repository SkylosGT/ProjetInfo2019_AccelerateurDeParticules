#ifndef SUPPORTOPENGL_H
#define SUPPORTOPENGL_H

#include <QOpenGLShaderProgram> // Classe qui regroupe les fonctions OpenGL liées aux shaders
#include <QMatrix4x4>
#include "SupportAdessin.h"
#include "glsphere.h"

class SupportOpenGL : public SupportADessin {
 public:
  // méthode(s) de dessin (héritée(s) de SupportADessin)
  virtual void dessine(Accelerateur const& a_dessiner) override;
  virtual void dessine(Particule const& a_dessiner) override;
  virtual void dessine(Dipole const& a_dessiner) override;
  virtual void dessine(Quadrupole const& a_dessiner) override;
  virtual void dessine(SectionDroite const& a_dessiner) override;

  // méthodes de (ré-)initialisation
  void init();
  void initializePosition();

  // méthode set
  void setProjection(QMatrix4x4 const& projection)
  { prog.setUniformValue("projection", projection); }

  // Méthodes set
  void translate(double x, double y, double z);
  void rotate(double angle, double dir_x, double dir_y, double dir_z);
  
  // méthode utilitaire offerte pour simplifier
  void dessineAxes(QMatrix4x4 const& point_de_vue=QMatrix4x4(), bool en_couleur=true);
  void dessineCube(QMatrix4x4 const& point_de_vue = QMatrix4x4() );
  void dessineSphere(QMatrix4x4 const& point_de_vue, double rouge=1.0, double vert=1.0, double bleu=1.0);

 private:
  // Un shader OpenGL encapsulé dans une classe Qt
  QOpenGLShaderProgram prog;
  GLSphere sphere;

  // Caméra
  QMatrix4x4 matrice_vue;
};

#endif
