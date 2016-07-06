#include "base.h"

#include <QGraphicsPixmapItem>

Base::Base()
{
    this->pixmap.load(":/player/images/mybase.png");
    this->setPixmap(this->pixmap);
}
