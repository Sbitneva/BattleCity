#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QGraphicsPixmapItem>
#include <QPixmap>

class GameOver:public QGraphicsPixmapItem{
public:
    GameOver();
private:
    QPixmap * pixmap;
};

#endif // GAMEOVER_H
