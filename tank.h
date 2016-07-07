#ifndef TANK_H
#define TANK_H

#include <QObject>
#include <QString>
#include <QTime>
#include <QMediaPlayer>
#include <QGraphicsPixmapItem>
#include <QMap>
#include "object.h"

typedef QMap<Rotation, QString> Sprites;

enum Group 
{
	Users,
	Bots
};

class Tank : public QGraphicsPixmapItem
{
public:
	Tank(Rotation rotation, Sprites& sprites, Group group);
protected:
	Rotation rotation;
	Group group;
	Sprites& sprites;
	QPixmap pixmap;
	QTime timeLastBullet;
	void shot();
	void moveLeft();
	void moveRight();
	void moveDown();
	void moveUp();
	QMediaPlayer sound;
};

#endif // TANK_H