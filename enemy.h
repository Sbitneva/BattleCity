#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QString>
#include <QTime>
#include <QMediaPlayer>
#include <QGraphicsPixmapItem>

class Enemy: public QObject, public QGraphicsPixmapItem 
{
    Q_OBJECT
public:
    Enemy();
private:
    QString rotation = "Up";
    QPixmap pixmap;
	QTime timeLastBullet;
    void shot();
    void moveLeft();
    void moveRight();
    void moveDown();
    void moveUp();
    QMediaPlayer sound;
};

#endif // ENEMY_H