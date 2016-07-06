#include <QGraphicsRectItem>
#include <QObject>
#include <QString>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QWidget>
#include <bullet.h>
#include <QTime>
#include <QList>
#include <QGraphicsItem>
#include <QMediaPlayer>
#include <tank.h>

class Enemy: public Tank{
    Q_OBJECT
public:
    Enemy();
private:
    QString rotation = "Up";
    QTime * timeLastBullet = new QTime();
    void shot();
    void moveLeft();
    void moveRight();
    void moveDown();
    void moveUp();
    QList<QGraphicsItem *> colliding_items;
    QMediaPlayer sound;
public slots:
    void spawn();
};


