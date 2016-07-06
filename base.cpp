#include "base.h"
#include <QGraphicsPixmapItem>

Base::Base(){
    pixmap = new QPixmap(":/player/images/mybase.png");
    this->setPixmap(*pixmap);
    this->setPos(384, 768);
}
