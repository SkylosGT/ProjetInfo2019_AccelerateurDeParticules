#include "SupportOpenGL.h"
#include "vertex_shader.h" // Identifiants Qt de nos différents attributs
#include "Accelerateur.h"
#include "SectionDroite.h"
#include "Quadrupole.h"
#include "Dipole.h"
#include "FaisceauCirculaire.h"
#include "Element.h"
#include "MailleFODO.h"
#include <math.h>

#define _USE_MATH_DEFINES

// ======================================================================
void SupportOpenGL::dessine(Accelerateur const& a_dessiner)
{
    for (auto element : a_dessiner.getCollectionElement()) {
        element->dessine();}
    for (auto faisceau :a_dessiner.getCollectionFaisceau()) {
        faisceau->dessine();
    }
}

void SupportOpenGL::dessine(const MailleFODO &a_dessiner){
    for (auto element : a_dessiner.getElements()) {
        element->dessine();
    }
}

void SupportOpenGL::dessine(FaisceauCirculaire const& a_dessiner){
    for (auto particule : a_dessiner.getCollectionPart()) {
        particule->dessine();
    }
}
// =======================================================================

void SupportOpenGL::dessine(Particule const& a_dessiner){
    QMatrix4x4 matrice;
    matrice.translate(a_dessiner.position().getx(),a_dessiner.position().gety(),a_dessiner.position().getz());
    matrice.scale(0.05);
    dessineSphere(matrice,(*new Vecteur3D(0.33,100,0.8)));
}
void SupportOpenGL::dessine(Dipole const& a_dessiner){
    QMatrix4x4 matrice;
    matrice.translate(a_dessiner.entree().getx(),a_dessiner.entree().gety(),a_dessiner.entree().getz());
    if(a_dessiner.entree().getx()>0){
        if(a_dessiner.entree().gety()>0){
            matrice.rotate(270,0,0,1);
        }else {
        matrice.rotate(180,0,0,1);}
    }else{
        if(a_dessiner.entree().gety()>0){
            matrice.rotate(0,0,0,1);
        }else {
        matrice.rotate(90,0,0,1);}
    }
    dessinCylindreIncurve(matrice, a_dessiner.rayonDeCourbure(), a_dessiner.rayonDeLaChambre(), (*new Vecteur3D(0.33,0.4,0.8)));
}

void SupportOpenGL::dessine(Quadrupole const& a_dessiner){

    QMatrix4x4 matrice;

    matrice.translate(a_dessiner.entree().getx(), a_dessiner.entree().gety(), a_dessiner.entree().getz());
    if((a_dessiner.entree()-a_dessiner.sortie()).gety()==0){
        if(a_dessiner.entree().gety()>0){matrice.rotate(270,0,0,1);}
        else {matrice.rotate(90,0,0,1);}}
    else {
        if(a_dessiner.entree().getx()>0){matrice.rotate(180,0,0,1);}
        else {matrice.rotate(0,0,0,1);}}
    dessineCylindre(matrice, (a_dessiner.entree()-a_dessiner.sortie()).norme(), a_dessiner.rayonDeLaChambre(), (*new Vecteur3D(0.33,0.5,0.66)));
}
void SupportOpenGL::dessine(SectionDroite const& a_dessiner){

    QMatrix4x4 matrice;

    matrice.translate(a_dessiner.entree().getx(), a_dessiner.entree().gety(), a_dessiner.entree().getz());
    if((a_dessiner.entree()-a_dessiner.sortie()).gety()==0){
        if(a_dessiner.entree().gety()>0){matrice.rotate(270,0,0,1);}
        else {matrice.rotate(90,0,0,1);}}
    else {
        if(a_dessiner.entree().getx()>0){matrice.rotate(180,0,0,1);}
        else {matrice.rotate(0,0,0,1);}}
    dessineCylindre(matrice, (a_dessiner.entree()-a_dessiner.sortie()).norme(), a_dessiner.rayonDeLaChambre(), (*new Vecteur3D(0.33,0.7,0.73)));
}

// ======================================================================
void SupportOpenGL::init()
{
  /* Initialise notre vue OpenGL.
   * Dans cet exemple, nous créons et activons notre shader.
   *
   * En raison du contenu des fichiers *.glsl, le shader de cet exemple
   * NE permet QUE de dessiner des primitives colorées
   * (pas de textures, brouillard, reflets de la lumière ou autres).
   *
   * Il est séparé en deux parties VERTEX et FRAGMENT.
   * Le VERTEX :
   * - récupère pour chaque sommet des primitives de couleur (dans
   *     l'attribut couleur) et de position (dans l'attribut sommet)
   * - multiplie l'attribut sommet par les matrices 'vue_modele' et
   *     'projection' et donne le résultat à OpenGL
   *   - passe la couleur au shader FRAGMENT.
   *
   * Le FRAGMENT :
   *   - applique la couleur qu'on lui donne
   */

  prog.addShaderFromSourceFile(QOpenGLShader::Vertex,   ":/vertex_shader.glsl");
  prog.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/fragment_shader.glsl");

  /* Identifie les deux attributs du shader de cet exemple
   * (voir vertex_shader.glsl).
   *
   * L'attribut identifié par 0 est particulier, il permet d'envoyer un
   * nouveau "point" à OpenGL
   *
   * C'est pourquoi il devra obligatoirement être spécifié et en dernier
   * (après la couleur dans cet exemple, voir plus bas).
   */

  prog.bindAttributeLocation("sommet",  SommetId);
  prog.bindAttributeLocation("couleur", CouleurId);

  // Compilation du shader OpenGL
  prog.link();

  // Activation du shader
  prog.bind();

  /* Activation du "Test de profondeur" et du "Back-face culling"
   * Le Test de profondeur permet de dessiner un objet à l'arrière-plan
   * partielement caché par d'autres objets.
   *
   * Le Back-face culling consiste à ne dessiner que les face avec ordre
   * de déclaration dans le sens trigonométrique.
   */
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);

  sphere.initialize();
  initializePosition();
}

// ======================================================================
void SupportOpenGL::initializePosition()
{
  // position initiale
  matrice_vue.setToIdentity();
  matrice_vue.translate(0.0, 0.0, -5.0);
  //matrice_vue.rotate(60.0, 0.0, 1.0, 0.0);
  //matrice_vue.rotate(45.0, 0.0, 0.0, 1.0);
}

// ======================================================================
void SupportOpenGL::translate(double x, double y, double z)
{
  /* Multiplie la matrice de vue par LA GAUCHE.
   * Cela fait en sorte que la dernière modification apportée
   * à la matrice soit appliquée en dernier (composition de fonctions).
   */
  QMatrix4x4 translation_supplementaire;
  translation_supplementaire.translate(x, y, z);
  matrice_vue = translation_supplementaire * matrice_vue;
}

// ======================================================================
void SupportOpenGL::rotate(double angle, double dir_x, double dir_y, double dir_z)
{
  // Multiplie la matrice de vue par LA GAUCHE
  QMatrix4x4 rotation_supplementaire;
  rotation_supplementaire.rotate(angle, dir_x, dir_y, dir_z);
  matrice_vue = rotation_supplementaire * matrice_vue;
}

// ======================================================================
void SupportOpenGL::dessineAxes(QMatrix4x4 const& point_de_vue, bool en_couleur){
    prog.setUniformValue("vue_modele", matrice_vue*point_de_vue);

    glBegin(GL_LINES);

    // axe X
    if(en_couleur){prog.setAttributeValue(CouleurId, 1.0, 0.0, 0.0);} // rouge
    else {prog.setAttributeValue(CouleurId, 1.0, 1.0, 1.0);} // blanc
    prog.setAttributeValue(SommetId, 0.0,0.0,0.0);
    prog.setAttributeValue(SommetId, 1.0,0.0,0.0);

    // axe Y
    if(en_couleur) {prog.setAttributeValue(CouleurId, 0.0, 1.0, 0.0);} // vert
    else {prog.setAttributeValue(CouleurId, 1.0, 1.0, 1.0);} // blanc
    prog.setAttributeValue(SommetId, 0.0,0.0,0.0);
    prog.setAttributeValue(SommetId, 0.0,1.0,0.0);

    // axe Z
    if(en_couleur) {prog.setAttributeValue(CouleurId, 0.0, 0.0, 1.0);} // bleu
    else {prog.setAttributeValue(CouleurId, 1.0, 1.0, 1.0);} // blanc
    prog.setAttributeValue(SommetId, 0.0,0.0,0.0);
    prog.setAttributeValue(SommetId, 0.0,0.0,1.0);

    glEnd();
}

// ======================================================================
void SupportOpenGL::dessineCube (QMatrix4x4 const& point_de_vue)
{
  prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);

  glBegin(GL_QUADS);
  // face coté X = +1
  prog.setAttributeValue(CouleurId, 1.0, 0.0, 0.0); // rouge
  prog.setAttributeValue(SommetId, +1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, +1.0);

  // face coté X = -1
  prog.setAttributeValue(CouleurId, 0.0, 1.0, 0.0); // vert
  prog.setAttributeValue(SommetId, -1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, -1.0, -1.0, +1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, -1.0);

  // face coté Y = +1
  prog.setAttributeValue(CouleurId, 0.0, 0.0, 1.0); // bleu
  prog.setAttributeValue(SommetId, -1.0, +1.0, -1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, -1.0);

  // face coté Y = -1
  prog.setAttributeValue(CouleurId, 0.0, 1.0, 1.0); // cyan
  prog.setAttributeValue(SommetId, -1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, +1.0);
  prog.setAttributeValue(SommetId, -1.0, -1.0, +1.0);

  // face coté Z = +1
  prog.setAttributeValue(CouleurId, 1.0, 1.0, 0.0); // jaune
  prog.setAttributeValue(SommetId, -1.0, -1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, +1.0);

  // face coté Z = -1
  prog.setAttributeValue(CouleurId, 1.0, 0.0, 1.0); // magenta
  prog.setAttributeValue(SommetId, -1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, -1.0);

  glEnd();
}

void SupportOpenGL::dessineSphere(const QMatrix4x4 &point_de_vue, Vecteur3D couleur){
    prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);
    prog.setAttributeValue(CouleurId, couleur.getx(), couleur.gety(), couleur.getz());
    sphere.draw(prog, SommetId);
}

//Dessine un point
void SupportOpenGL::dessinePoint( QMatrix4x4 const& point_de_vue, double taille){
    prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);
    glPointSize(taille);
    glBegin(GL_POINTS);
    prog.setAttributeValue(SommetId, 0.0,0.0,0.0);
    glEnd();
}

//Dessin un cercle
void SupportOpenGL::dessineCercle(QMatrix4x4 const& point_de_vue, double precision, double rayon, Vecteur3D couleur){
    prog.setUniformValue("vue_modele", matrice_vue*point_de_vue);
    double theta=2*M_PI/precision;
    glBegin(GL_LINE_STRIP);
    for (size_t i(0);i<=precision;i++) {
       prog.setAttributeValue(CouleurId, couleur.getx(), couleur.gety(), couleur.getz());
       prog.setAttributeValue(SommetId, rayon*cos(i*theta),0.0,rayon*sin(i*theta));
    }
    glEnd();
}

//Dessine un cylindre en fil de fer
void SupportOpenGL::dessineCylindre(QMatrix4x4 const& point_de_vue, double longueur, double rayon, Vecteur3D couleur){
    prog.setUniformValue("vue_modele", matrice_vue*point_de_vue);
    double precision=36;
    int lineAmount=8;
    double theta=2*M_PI/lineAmount;
    dessineCercle(point_de_vue, precision, rayon, couleur);
    glBegin(GL_LINES);
    for (size_t i(0);i<lineAmount;i++) {
       prog.setAttributeValue(CouleurId, couleur.getx(), couleur.gety(), couleur.getz());
       prog.setAttributeValue(SommetId, rayon*cos(i*theta), 0, rayon*sin(i*theta));
       prog.setAttributeValue(SommetId, rayon*cos(i*theta), longueur, rayon*sin(i*theta));
    }
    glEnd();
    QMatrix4x4 matrice=point_de_vue;
    matrice.translate(0.0, longueur, 0.0);
    dessineCercle(matrice, precision, rayon, couleur);
}

//Dessine un cylindre en fil de fer incurvé
void SupportOpenGL::dessinCylindreIncurve(const QMatrix4x4 &point_de_vue, double rayonDeCourbure, double rayon, Vecteur3D couleur){
 double precision=36;
 int lineAmount=8;
 double angleCylindre=2*M_PI/(lineAmount);
 double angleLigne=M_PI/(2*precision);
 dessineCercle(point_de_vue, precision, rayon, couleur);
 QMatrix4x4 matrice=point_de_vue;
 for (size_t j(0);j<lineAmount;j++) {
     double rayonLigne=rayonDeCourbure+rayon*sin(j*angleCylindre);
     glBegin(GL_LINE_STRIP);
     for (size_t i(0);i<=precision;i++) {
         prog.setAttributeValue(CouleurId, couleur.getx(), couleur.gety(), couleur.getz());
         prog.setAttributeValue(SommetId, rayonDeCourbure-rayonLigne*cos(i*angleLigne),rayonLigne*sin(i*angleLigne), rayon*cos(j*angleCylindre));
     }
     glEnd();}
 matrice.translate(rayonDeCourbure,rayonDeCourbure,0);
 matrice.rotate(90, 0, 0,1);
 dessineCercle(matrice, precision, rayon, couleur);
 matrice=point_de_vue;
 matrice.translate(rayonDeCourbure-rayonDeCourbure*cos(M_PI/4),rayonDeCourbure*sin(M_PI/4),0);
 matrice.rotate(-45,0,0,1);

 dessineCercle(matrice, precision, rayon, couleur);
}
