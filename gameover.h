#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QMediaPlayer>

class GameOver:public QGraphicsPixmapItem{
public:
    GameOver();
private:
    QPixmap * pixmap;
    QMediaPlayer * sound;
};

#endif // GAMEOVER_H
