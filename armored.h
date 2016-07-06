#ifndef ARMORED_H
#define ARMORED_H

#include <QGraphicsPixmapItem>
#include <QPixmap>

class Armored: public QGraphicsPixmapItem
{
private:
	QPixmap pixmap;
public:
    Armored(int x, int y);
};

#endif // ARMORED_H
