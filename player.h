#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QString>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QWidget>
#include <bullet.h>
#include <QTime>

class Player: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player();
private:
    QString rotation = "Up";
    QTime * timeLastBullet = new QTime();
    void keyPressEvent(QKeyEvent * event);
    void shot();
    void moveLeft();
    void moveRight();
    void moveDown();
    void moveUp();
public slots:
    void spawn();
};

#endif // MYRECT_H
