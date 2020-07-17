TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += "C:\Users\wujt8989\Desktop\SFML-2.5.1\include"

SOURCES += \
        StaticObject.cpp \
        baloon.cpp \
        elementy.cpp \
        guy.cpp \
        main.cpp \
        playagainbutton.cpp \
        playbutton.cpp \
        texty.cpp \
        tutorialbutton.cpp \
        wall.cpp

LIBS += -L"C:\Users\wujt8989\Desktop\SFML-2.5.1\lib"
CONFIG(debug, debug|release){
    LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
} else {
    LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
}

HEADERS += \
    StaticObject.h \
    baloon.h \
    elementy.h \
    guy.h \
    playagainbutton.h \
    playbutton.h \
    texty.h \
    tutorialbutton.h \
    wall.h
