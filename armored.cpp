#include <armored.h>

Armored::Armored(int x, int y)
{
    this->pixmap.load(":/images/board/images/board/armoredwall.png");
    this->setPixmap(this->pixmap);
    this->setPos(x, y);
}
