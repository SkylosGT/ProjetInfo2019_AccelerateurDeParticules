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


all:  testParticule testVecteur testAccell

testParticule: testParticule.o Vecteur3D.o Particule.o

Vecteur3D.o: Vecteur3D.cc Vecteur3D.h

Particule.o: Particule.cc Particule.h Vecteur3D.h ConstantesPhysiques.h

testParticule.o: testParticule.cc Particule.h Vecteur3D.h 

testVecteur: testVecteur.o Vecteur3D.o

testVecteur.o: testVecteur.cc Vecteur3D.h

Dipole.o: Dipole.cc Dipole.h ElementCourbe.h Element.h Vecteur3D.h \
  Particule.h ConstantesPhysiques.h

Element.o: Element.cc Element.h Vecteur3D.h Particule.h \
  ConstantesPhysiques.h

ElementCourbe.o: ElementCourbe.cc ElementCourbe.h Element.h Vecteur3D.h \
  Particule.h ConstantesPhysiques.h

ElementDroit.o: ElementDroit.cc ElementDroit.h Element.h Vecteur3D.h \
  Particule.h

testAccell.o: testAccell.cc Accelerateur.h ElementCourbe.h Element.h \
  Vecteur3D.h Particule.h ElementDroit.h Dipole.h

