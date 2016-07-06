#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QString>
#include <QTime>
#include <QMediaPlayer>
#include <QGraphicsPixmapItem>

class Player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player();
private:
    QString rotation = "Up";
	QPixmap pixmap;
    QTime timeLastBullet;
    void keyPressEvent(QKeyEvent * event);
    void shot();
    void moveLeft();
    void moveRight();
    void moveDown();
    void moveUp();
    QMediaPlayer sound;
};

#endif // PLAYER_H
