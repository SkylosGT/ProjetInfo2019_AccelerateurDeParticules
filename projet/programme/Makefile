CXX = g++
CC  = $(CXX)

CXXFLAGS = -std=c++11  # C++11, ou autre suivant vos préférences

# Partie commentée : choisissez les options que vous voulez avoir
#                    en décommentant la/les lignes correspondantes
#
CXXFLAGS += -pedantic -Wall       # pour les purs et durs
CXXFLAGS += -g                    # pour debugger
# CXXFLAGS += -pg                 # pour profiler
# LDFLAGS  += -pg                 # pour profiler
# CXXFLAGS += -O2                 # pour optimiser la vitesse


all:  testParticule testVecteur exerciceP9 exerciceP10 exerciceP11

exerciceP11: exerciceP11.o SupportConsole.o Particule.o Vecteur3D.o Dipole.o ElementCourbe.o Element.o Accelerateur.o ElementDroit.o Quadrupole.o SectionDroite.o Faisceau.o

exerciceP11.o: exerciceP11.cc SupportConsole.h SupportADessin.h Dessinable.h

exerciceP10: exerciceP10.o SupportConsole.o Particule.o Vecteur3D.o Dipole.o ElementCourbe.o Element.o Accelerateur.o ElementDroit.o Quadrupole.o SectionDroite.o Faisceau.o

exerciceP10.o: exerciceP10.cc SupportConsole.h SupportADessin.h Dessinable.h

exerciceP9: exerciceP9.o SupportConsole.o Particule.o Vecteur3D.o Dipole.o ElementCourbe.o Element.o Accelerateur.o ElementDroit.o Quadrupole.o SectionDroite.o Faisceau.o

exerciceP9.o: exerciceP9.cc SupportConsole.h SupportADessin.h Dessinable.h

SupportConsole.o: SupportConsole.cc SupportConsole.h supportADessin.h Dessinable.h

testParticule: testParticule.o Vecteur3D.o Particule.o

testVecteur: testVecteur.o Vecteur3D.o

testAccel1: testAccel1.o Particule.o Vecteur3D.o Accelerateur.o Dipole.o Element.o ElementCourbe.o ElementDroit.o Quadrupole.o SectionDroite.o Faisceau.o

Accelerateur.o: Accelerateur.cc Accelerateur.h Dipole.h ElementCourbe.h Element.h Vecteur3D.h Particule.h Faisceau.h

Dipole.o: Dipole.cc Dipole.h ElementCourbe.h Element.h Vecteur3D.h Particule.h ConstantesPhysiques.h

ElementCourbe.o: ElementCourbe.cc ElementCourbe.h Element.h Vecteur3D.h Particule.h ConstantesPhysiques.h

testAccel1.o: testAccel1.cc Accelerateur.h Dipole.h ElementCourbe.h Element.h Vecteur3D.h Particule.h ConstantesPhysiques.h 

Element.o: Element.cc Element.h Vecteur3D.h Particule.h ConstantesPhysiques.h

ElementDroit.o: ElementDroit.cc ElementDroit.h Element.h Vecteur3D.h Particule.h

Particule.o: Particule.cc Particule.h Vecteur3D.h Element.h ConstantesPhysiques.h

Quadrupole.o: Quadrupole.cc Quadrupole.h ElementDroit.h Element.h Vecteur3D.h Particule.h ConstantesPhysiques.h

SectionDroite.o: SectionDroite.cc SectionDroite.h ElementDroit.h Element.h Vecteur3D.h Particule.h ConstantesPhysiques.h

testAccel1.o: testAccel1.cc Accelerateur.h Element.h Vecteur3D.h Particule.h Dipole.h ElementCourbe.h Quadrupole.h ElementDroit.h SectionDroite.h ConstantesPhysiques.h

testParticule.o: testParticule.cc Particule.h Vecteur3D.h Element.h ConstantesPhysiques.h

testVecteur.o: testVecteur.cc Vecteur3D.h

Vecteur3D.o: Vecteur3D.cc Vecteur3D.h

Faisceau.o: Faisceau.cc Faisceau.h Dessinable.h SupportADessin.h Vecteur3D.h Particule.h Element.h ConstantesPhysiques.h

FaisceauCirculaire.o: FaisceauCirculaire.cc FaisceauCirculaire.h Faisceau.h Vecteur3D.h Particule.h Element.h ConstantesPhysiques.h 