TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        joueur.cpp \
        main.cpp \
        rule.cpp \
        ruleBase.cpp \
        terrain.cpp

HEADERS += \
    joueur.h \
    rule.h \
    ruleBase.h \
    terrain.h
