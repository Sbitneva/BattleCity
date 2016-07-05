#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QString>

class Bullet:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:    
    Bullet(QString rotation);
public slots:    
    void move();
private:
    QList<QGraphicsItem *> colliding_items;
    QString rotation = "Up";
    void removeBricks(int i);
};

#endif // BULLET_H
