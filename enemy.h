#ifndef ENEMY_H
#define ENEMY_H

#include "object.h"
#include "tank.h"

class Enemy: public Tank 
{
public:
	Enemy(Rotation rotation);
};

#endif // ENEMY_H