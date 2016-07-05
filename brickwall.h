#ifndef BRICKWALL_H
#define BRICKWALL_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsScene>

class BrickWall:public QObject{
public:
    BrickWall(int x, int y, QGraphicsScene *  scene);
    QGraphicsScene * scene;
};

#endif // BRICKWALL_H
