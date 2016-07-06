#include "smallbrick.h"
#include <QGraphicsScene>

SmallBrick::SmallBrick(int x, int y)
{
    this->pixmap.load(":/images/board/images/board/brick.png");
    this->setPixmap(this->pixmap);
    this->setPos(x, y);
}
