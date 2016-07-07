#include "player.h"
#include <QKeyEvent>

static Sprites userSprites = {
	{ Up, ":/player/images/mytank.png" },
	{ Down, ":/player/images/mytank_down.png" },
	{ Left, ":/player/images/mytank_left.png" },
	{ Right, ":/player/images/mytank_right.png" }
};

Player::Player(Rotation rotation)
	: Tank(rotation, userSprites, Users) {};

void Player::keyPressEvent(QKeyEvent * event)
{
	switch(event->key())
	{
	case Qt::Key_Left:
		moveLeft();
		break;
	case Qt::Key_Right:
		moveRight();
		break;
	case Qt::Key_Up:
		moveUp();
		break;
	case Qt::Key_Down:
		moveDown();
		break;
	case Qt::Key_Space:
		// create a bullet
		if ((this->timeLastBullet.elapsed() > 200) || (this->timeLastBullet.msec() == -1)) 
		{
			this->timeLastBullet.restart();
			this->shot();
		}
	}
}

