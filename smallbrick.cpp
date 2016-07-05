#include "smallbrick.h"
#include "QDebug"
#include <QGraphicsScene>

SmallBrick::SmallBrick(int x, int y){
    //qDebug()<<"small brick";
    QPixmap * pixmap = new QPixmap(":/images/board/images/board/brick.png");
    this->setPixmap(*pixmap);
    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setPos(x, y);
    this->setFocus();

}
