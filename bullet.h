#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QString>
#include <QMediaPlayer>
#include <QTimer>
#include <QPixmap>

class Bullet:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Bullet(QString rotation, QString tank);
public slots:
    void move();
private:
    QTimer timer;
    QPixmap pixmap;
    QList<QGraphicsItem *> colliding_items;
    QString rotation = "Up";
    QString parent;
    void removeBricks(int i);
    void removeBricksUp(int coordX, int coordY);
    void removeBricksLeft(int coordX, int coordY);
};

#endif // BULLET_H
