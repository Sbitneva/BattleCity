#include <QApplication>
#include <QFile>
#include "game.h"

Game * game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new Game(QFile(":/maps/maps/level1.map"));
    game->show();

    return a.exec();
}
