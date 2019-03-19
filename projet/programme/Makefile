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

all:: testParticule

Vecteur3D.o: Vecteur3D.cc Vecteur3D.h

testParticule: testParticule.o Vecteur3D.o Particule.o

Particule.o: Particule.cc Particule.h Vecteur3D.h ConstantesPhysiques.h

testParticule.o: testParticule.cc Particule.h Vecteur3D.h

Vecteur3D.o: Vecteur3D.cc Vecteur3D.h
#testVecteur.o: testVecteur.cc Vecteur3D.h

#testVecteur: testVecteur.o Vecteur3D.o