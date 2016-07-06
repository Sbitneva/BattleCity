#ifndef BASE_H
#define BASE_H

#include <QGraphicsPixmapItem>
#include <QPixmap>

class Base : public QGraphicsPixmapItem
{
public:
    Base();
private:
    QPixmap pixmap;
};

#endif // BASE_H
