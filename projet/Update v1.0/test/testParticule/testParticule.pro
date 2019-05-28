CONFIG += c++11

TARGET = testParticule

LIBS += -L../../general -lgeneral
PRE_TARGETDEPS += ../../general/libgeneral.a

INCLUDEPATH = ../../general

SOURCES += \
    testParticule.cc


HEADERS += \
    ../../general/Particule.h

