#include "Game.h"
#include <QWidget>
#include <QTimer>
#include "player.h"
#include <QImage>
#include <QString>
#include <QPixmap>

Game::Game(QWidget * parent){

    scene = new QGraphicsScene();
    scene->setSceneRect(0,0, 832, 832);

    scene->setBackgroundBrush(Qt::black);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(832, 832);
    setScene(scene);    

    player = new Player();

    scene->addItem(player);

    QTimer * timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(200);

    show();
}
