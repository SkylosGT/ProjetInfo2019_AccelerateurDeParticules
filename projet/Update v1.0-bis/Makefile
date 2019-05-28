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


all: testParticule testVecteur exerciceP14 

testAccel1: testAccel1.o Particule.o Vecteur3D.o Accelerateur.o Dipole.o Element.o ElementCourbe.o Quadrupole.o SectionDroite.o Faisceau.o

testParticule: testParticule.o Vecteur3D.o Particule.o

testVecteur: testVecteur.o Vecteur3D.o

exerciceP14: exerciceP14.o Particule.o Faisceau.o Accelerateur.o Vecteur3D.o FaisceauCirculaire.o SupportConsole.o Element.o Case.o Dipole.o ElementCourbe.o MailleFODO.o ElementDroit.o Quadrupole.o SectionDroite.o

exerciceP14.o:exerciceP14.cc SupportConsole.h Particule.h Dipole.h Accelerateur.h ConstantesPhysiques.h Quadrupole.h SectionDroite.h Vecteur3D.h ElementDroit.h ElementCourbe.h Faisceau.h FaisceauCirculaire.h MailleFODO.h

SupportConsole.o: SupportConsole.cc SupportConsole.h SupportADessin.h Dessinable.h

Accelerateur.o: Accelerateur.cc Accelerateur.h Dipole.h ElementCourbe.h Element.h Vecteur3D.h Particule.h Faisceau.h Case.h MailleFODO.h

Case.o: Case.cc Case.h Particule.h Vecteur3D.h Element.h Dessinable.h SupportADessin.h

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

MailleFODO.o: MailleFODO.cc ElementDroit.h Element.h Particule.h Vecteur3D.h Dessinable.h SupportADessin.h Quadrupole.h SectionDroite.h
