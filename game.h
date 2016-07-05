#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QTimer>
#include <QObject>
#include <QWidget>
#include <player.h>


class Game: public QGraphicsView{
public:
    Game(QWidget * parent = nullptr);

    QGraphicsScene * scene;

    Player * player;

private:
    void loadMapFromFile();
    QVector<QVector<QString>> mapMatrix;
    void createObstacles();
};

#endif // GAME_H
