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

all: main_text

main_text: main_text.o text_viewer.o

main_text.o: main_text.cc text_viewer.h support_a_dessin.h contenu.h dessinable.h

text_viewer.o: text_viewer.cc text_viewer.h support_a_dessin.h contenu.h dessinable.h