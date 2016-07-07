#ifndef PLAYER_H
#define PLAYER_H

#include "object.h"
#include "tank.h"

class Player: public Tank
{
public:
    Player(Rotation rotation);
private:
    void keyPressEvent(QKeyEvent * event);
};

#endif // PLAYER_H
