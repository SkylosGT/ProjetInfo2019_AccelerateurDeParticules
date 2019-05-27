TEMPLATE = lib

CONFIG = staticlib c++11

SOURCES += \
    Accelerateur.cc \
    Dipole.cc \
    Element.cc \
    ElementCourbe.cc \
    ElementDroit.cc \
    Faisceau.cc\
    FaisceauCirculaire.cc\
    Particule.cc \
    Quadrupole.cc \
    SectionDroite.cc \
    Vecteur3D.cc \
    case.cc \
    maillefodo.cc

HEADERS += \
    Accelerateur.h \
    Case.h \
    ConstantesPhysiques.h \
    Dessinable.h \
    Dipole.h \
    Element.h \
    ElementCourbe.h \
    ElementDroit.h \
    Faisceau.h\
    FaisceauCirculaire.h\
    MailleFODO.h \
    Particule.h \
    Quadrupole.h \
    SectionDroite.h \
    SupportAdessin.h \
    Vecteur3D.h



