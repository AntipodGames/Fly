LIBS += -L/usr/local/lib/ -lX11  -lsfml-window -lsfml-system -lsfml-graphics -lsfml-audio

INCLUDEPATH += /home/leni/SFML-1.6/include

CONFIG += c++11
QT += widgets
QT += phonon

SOURCES += main.cpp \
    entite.cpp \
    qsfml.cpp \
    qsfcanvas.cpp \
    environment.cpp \
    imagemanager.cpp \
    animatedmanager.cpp \
    animatedsprite.cpp \
    displaymanager.cpp \
    ingame.cpp \
    ingameui.cpp \
    fly.cpp \
    tzellipse.cpp \
    carte.cpp \
    soundmanager.cpp \
    triggerevent.cpp \
    datamanager.cpp

HEADERS += \
    entite.h \
    qsfml.h \
    qsfcanvas.h \
    environment.h \
    imagemanager.h \
    animatedmanager.h \
    animatedsprite.h \
    displaymanager.h \
    ingame.h \
    ingameui.h \
    fly.h \
    tzellipse.h \
    carte.h \
    soundmanager.h \
    triggerevent.h \
    datamanager.h

