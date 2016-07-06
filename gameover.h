#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QMediaPlayer>

class GameOver: public QGraphicsPixmapItem
{
private:
	QPixmap pixmap;
	QMediaPlayer sound;
public:
    GameOver();
};

#endif // GAMEOVER_H
