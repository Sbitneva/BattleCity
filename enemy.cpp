#include "enemy.h"

static Sprites enemySprites = {
	{ Up, ":/tank/images/enemytank.png" },
	{ Down, ":/tank/images/enemytank_down.png" },
	{ Left, ":/tank/images/enemytank_left.png" },
	{ Right, ":/tank/images/enemytank_right.png" }
};

Enemy::Enemy(Rotation rotation)
	: Tank(rotation, enemySprites, Bots) {};
