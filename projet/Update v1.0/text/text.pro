CONFIG += c++11

TARGET = exerciceP14

LIBS += -L../general -lgeneral
PRE_TARGETDEPS += ../general/libgeneral.a

INCLUDEPATH = ../general

SOURCES += \
    SupportConsole.cc \
    exerciceP14.cc \

HEADERS += \
    SupportConsole.h \
    ../general/Accelerateur.h \
    ../general/ConstantesPhysiques.h \
    ../general/Dessinable.h \
    ../general/Dipole.h \
    ../general/Element.h \
    ../general/ElementCourbe.h \
    ../general/ElementDroit.h \
    ../general/Faisceau.h\
    ../general/FaisceauCirculaire.h\
    ../general/Particule.h \
    ../general/Quadrupole.h \
    ../general/SectionDroite.h \
    ../general/SupportAdessin.h \
    ../general/Vecteur3D.h
