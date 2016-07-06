#ifndef TANK_H
#define TANK_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Tank:public QObject, public QGraphicsPixmapItem{
public:
    Tank();
    //virtual ~Tank();

};

#endif // TANK_H
