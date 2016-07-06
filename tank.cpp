#include "tank.h"
#include "bullet.h"

#include <QKeyEvent>
#include <QGraphicsScene>

Tank::Tank(Rotation rotation, Sprites& sprites, Group group)
	: rotation(rotation), sprites(sprites), group(group)
{
	this->pixmap.load(sprites[rotation]);
	this->setPixmap(this->pixmap);
	this->setFlag(QGraphicsItem::ItemIsFocusable);
	this->setTransformationMode(Qt::SmoothTransformation);
}

void Tank::shot()
{
	Bullet * bullet = new Bullet(rotation, this->group);

	sound.setMedia(QUrl("qrc:/gamesounds/Audio/explode.wav"));
	sound.play();
	this->timeLastBullet.start();

	if (rotation == Up)
	{
		bullet->setPos(x() + 26, y());
	}
	else if (rotation == Down)
	{
		bullet->setPos(x() + 26, y() + 64);
	}
	else if (rotation == Right)
	{
		bullet->setPos(x() + 64, y() + 26);
	}
	else if (rotation == Left)
	{
		bullet->setPos(x(), y() + 26);
	}

	scene()->addItem(bullet);
}

void Tank::moveLeft()
{
	rotation = Left;
	this->pixmap.load(sprites[rotation]);
	this->setPixmap(this->pixmap);

	int xTankPos = this->pos().x() - 16;
	int yTankPos = this->pos().y();

	if (pos().x() > 0)
	{
		QGraphicsItem * leftItem;
		for (int i = 0; i < 4; i++)
		{
			leftItem = scene()->itemAt(QPointF((xTankPos), yTankPos + 16 * i), QTransform());
			if (leftItem)
			{
				return;
			}
		}
		this->setPos(x() - 16, y());
	}
}

void Tank::moveRight()
{
	rotation = Right;
	this->pixmap.load(sprites[rotation]);
	this->setPixmap(this->pixmap);

	int xTankPos = this->pos().x() + 64;
	int yTankPos = this->pos().y();

	if (pos().x() < 768)
	{
		QGraphicsItem * rightItem;
		for (int i = 0; i < 4; i++) {
			rightItem = scene()->itemAt(QPointF((xTankPos), yTankPos + 16 * i), QTransform());
			if (rightItem)
			{
				return;
			}
		}
		setPos(x() + 16, y());
	}
}

void Tank::moveUp()
{
	rotation = Up;
	this->pixmap.load(sprites[rotation]);
	this->setPixmap(this->pixmap);

	int xTankPos = this->pos().x();
	int yTankPos = this->pos().y() - 16;

	if (pos().y() > 0)
	{
		QGraphicsItem * upItem;
		for (int i = 0; i < 4; i++) {
			upItem = scene()->itemAt(QPointF((xTankPos + i * 16), yTankPos), QTransform());
			if (upItem)
			{
				return;
			}
		}
		setPos(x(), y() - 16);
	}
}

void Tank::moveDown()
{
	rotation = Down;
	this->pixmap.load(sprites[rotation]);
	this->setPixmap(this->pixmap);

	int xTankPos = this->pos().x();
	int yTankPos = this->pos().y() + 64;

	if (pos().y() < 768)
	{
		QGraphicsItem * downItem;
		for (int i = 0; i < 4; i++) {
			downItem = scene()->itemAt(QPointF((xTankPos + i * 16), yTankPos), QTransform());
			if (downItem)
			{
				return;
			}
		}
		setPos(x(), y() + 16);
	}
}

