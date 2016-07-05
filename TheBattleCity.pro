#-------------------------------------------------
#
# Project created by QtCreator 2016-07-02T23:33:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TheButtleCity
TEMPLATE = app


SOURCES += main.cpp \
    Game.cpp \
    Player.cpp \
    bullet.cpp \
    enemy.cpp \
    smallbrick.cpp \
    armored.cpp

HEADERS  += \
    Game.h \
    Player.h \
    bullet.h \
    enemy.h \
    smallbrick.h \
    armored.h

RESOURCES += \
    board_items.qrc \
    tank.qrc \
    maps.qrc

DISTFILES +=

