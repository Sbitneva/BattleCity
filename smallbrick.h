#ifndef SMALLBRICK_H
#define SMALLBRICK_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsScene>

class SmallBrick:public QObject, public QGraphicsPixmapItem{
    public:
    SmallBrick(int x, int y);
};

#endif // SMALLBRICK_H
