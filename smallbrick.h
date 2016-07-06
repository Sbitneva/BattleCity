#ifndef SMALLBRICK_H
#define SMALLBRICK_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QPixmap>

class SmallBrick: public QObject, public QGraphicsPixmapItem
{
private:
	QPixmap pixmap;
public:
    SmallBrick(int x, int y);
};

#endif // SMALLBRICK_H
