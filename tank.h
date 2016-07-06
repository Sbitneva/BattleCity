#ifndef TANK_H
#define TANK_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Tank:public QObject, public QGraphicsPixmapItem{
public:
    Tank();
    //virtual ~Tank() = 0;

};

#endif // TANK_H
