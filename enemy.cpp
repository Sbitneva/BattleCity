#include "enemy.h"
#include "bullet.h"

#include <QKeyEvent>
#include <QGraphicsScene>

Enemy::Enemy(Rotation rotation)
	: rotation(rotation)
{
	this->pixmap.load(":/tank/images/enemytank_down.png");
	this->setPixmap(this->pixmap);
	this->setFlag(QGraphicsItem::ItemIsFocusable);
	this->setTransformationMode(Qt::SmoothTransformation);
}

void Enemy::shot()
{
	Bullet * bullet = new Bullet(rotation, "Enemy");

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

void Enemy::moveLeft()
{
	this->pixmap.load(":/tank/images/enemytank_left.png");
	this->setPixmap(this->pixmap);
	rotation = Left;

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

void Enemy::moveRight()
{
	this->pixmap.load(":/tank/images/enemytank_right.png");
	this->setPixmap(this->pixmap);
	rotation = Right;

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

void Enemy::moveUp()
{
	this->pixmap.load(":/tank/images/enemytank.png");
	this->setPixmap(this->pixmap);
	rotation = Up;

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

void Enemy::moveDown()
{
	this->pixmap.load(":/tank/images/enemytank_down.png");
	this->setPixmap(this->pixmap);
	rotation = Down;

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

