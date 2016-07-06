#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMediaPlayer>
#include <QWidget>
#include <QFile>

class Game: public QGraphicsView
{
private:
	void loadMapFromFile();
	void createObstacles();

	QFile& mapFile;
	QMediaPlayer sound;
	QVector<QVector<char>> mapMatrix;
	QGraphicsScene scene;
public:
    Game(QFile& map);
	~Game();
};

#endif // GAME_H
