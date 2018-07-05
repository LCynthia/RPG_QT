#-------------------------------------------------
#
# Project created by QtCreator 2018-06-12T10:44:13
#
#-------------------------------------------------

QT       += core gui
QT += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RPG
TEMPLATE = app


SOURCES += main.cpp \
    bat.cpp \
    bullet.cpp \
    game.cpp \
    health.cpp \
    monster.cpp \
    player.cpp \
    score.cpp \
    wealth.cpp \
    box.cpp \
    backpack.cpp \
    diamond.cpp \
    saying.cpp \
    store.cpp \
    skill.cpp

HEADERS  += \
    bullet.h \
    head.h \
    health.h \
    monster.h \
    player.h \
    score.h \
    wealth.h \
    bat.h \
    box.h \
    backpack.h \
    diamond.h \
    game.h \
    saying.h \
    store.h \
    skill.h

FORMS    += mainwindow.ui

RESOURCES += \
    resource.qrc
CONFIG+=resources_big
