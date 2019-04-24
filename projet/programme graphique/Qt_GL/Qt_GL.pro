QT += core gui opengl widgets
CONFIG += c++11

win32:LIBS += -lopengl32


TARGET = exerciceP12

LIBS += -L../general -lgeneral
PRE_TARGETDEPS += ../general/libgeneral.a

INCLUDEPATH = ../general

SOURCES += \
    main_qt_gl.cc \
    glwidget.cc \
    glsphere.cc\
    SupportOpenGL.cc

HEADERS += \
    glwidget.h \
    vertex_shader.h \
    SupportOpenGL.h \
    glsphere.h\
    ../general/Accelerateur.h \
    ../general/ConstantesPhysiques.h \
    ../general/Dessinable.h \
    ../general/Dipole.h \
    ../general/Element.h \
    ../general/ElementCourbe.h \
    ../general/ElementDroit.h \
    ../general/Particule.h \
    ../general/Quadrupole.h \
    ../general/SectionDroite.h \
    ../general/SupportAdessin.h \
    ../general/Vecteur3D.h

RESOURCES += \
    resource.qrc
