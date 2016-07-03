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
    board.cpp \
    bullet.cpp \
    brickwall.cpp \
    enemy.cpp

HEADERS  += \
    Game.h \
    Player.h \
    board.h \
    bullet.h \
    brickwall.h \
    enemy.h

RESOURCES += \
    board_items.qrc \
    tank.qrc

