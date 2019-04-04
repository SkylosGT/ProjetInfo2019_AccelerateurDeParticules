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

all: testDessinable

testDessinable: testDessinable.o SupportConsole.o

testDessinable.o: testDessinable.cc SupportConsole.h SupportADessin.h Contenu.h Dessinable.h

SupportConsole.o: SupportConsole.cc SupportConsole.h supportADessin.h Contenu.h Dessinable.h