#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QString>
#include <QMediaPlayer>
#include <QTimer>
#include <QPixmap>
#include "object.h"

class Bullet: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet(Rotation rotation, QString tank);
public slots:
    void move();
private:
    QTimer timer;
    QPixmap pixmap;
    QList<QGraphicsItem *> colliding_items;
	Rotation rotation;
    QString parent;
    void removeBricks(int i);
    void removeBricksUp(int coordX, int coordY);
    void removeBricksLeft(int coordX, int coordY);
};

#endif // BULLET_H
