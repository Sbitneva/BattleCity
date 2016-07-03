#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QString>

class Bullet:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    QString rotation = "Up";
    Bullet(QString rotation);
public slots:
    void move();
};

#endif // BULLET_H
