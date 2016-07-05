#include <armored.h>

Armored::Armored(int x, int y){
    QPixmap * pixmap = new QPixmap(":/images/board/images/board/armoredwall.png");
    this->setPixmap(*pixmap);
    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setPos(x, y);
    this->setFocus();
}
