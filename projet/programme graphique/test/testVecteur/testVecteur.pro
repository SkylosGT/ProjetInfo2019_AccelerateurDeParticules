CONFIG += c++11

TARGET = testVecteur

LIBS += -L../../general -lgeneral
PRE_TARGETDEPS += ../../general/libgeneral.a

INCLUDEPATH = ../../general

SOURCES += \
    testVecteur.cc


HEADERS += \
    ../../general/Vecteur3D.h
