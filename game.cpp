#include "armored.h"
#include "enemy.h"
#include "base.h"
#include "gameover.h"
#include "game.h"
#include "player.h"
#include "smallbrick.h"

#include <QFile>
#include <QTimer>
#include <QTextStream>

Game::Game(QFile& map) 
	: mapFile(map)
{
    this->sound.setMedia(QUrl("qrc:/gamesounds/Audio/gameStart.mp3"));
    this->sound.play();
    this->scene.setSceneRect(0, 0, 832, 832);
    this->scene.setBackgroundBrush(Qt::black);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(832, 832);
    setScene(&scene);    

    createObstacles();

    Player * player = new Player(Up);
    this->scene.addItem(player);
	player->setPos(256, 768);
	player->setFocus();

    Enemy * enemy = new Enemy(Down);
    this->scene.addItem(enemy);
    enemy->setPos(0, 0);

    Enemy * enemy2 = new Enemy(Down);
    this->scene.addItem(enemy2);
    enemy2->setPos(384, 0);

    Enemy * enemy3 = new Enemy(Down);
    this->scene.addItem(enemy3);
    enemy3->setPos(768, 0);

    Base * base = new Base();
    this->scene.addItem(base);
	base->setPos(384, 768);

    this->show();
}

Game::~Game()
{
	for(auto& item: this->scene.items())
		delete item;
}

void Game::loadMapFromFile()
{
    if(mapFile.open(QIODevice::ReadOnly | QIODevice::Text))
	{
        QTextStream textStream(&mapFile);
        QVector<char> row(26);
        QVector<QVector<char>> mapMatrix(26);

        for(int i = 0; i < 26; i++)
		{
            for(int j = 0; j < 26; j++)
			{
				char nChar; 
				textStream >> nChar;
                if(nChar == '\n')
				{
					textStream >> nChar;
                }
                row[j] = nChar;
            }
            mapMatrix[i] = row;
        }
        this->mapMatrix = mapMatrix;
    }
}

void Game::createObstacles()
{
    this->loadMapFromFile();

    QVector<char> row;

    if(mapMatrix.size())
	{
        for(int i = 0; i < this->mapMatrix.size(); i++)
		{
            row = mapMatrix[i];
            for(int j = 0; j < row.size(); j++)
			{
                if(row[j] == 'A')
				{
                    Armored * armored = new Armored(j*32, i * 32);
                    this->scene.addItem(armored);
                }
				else if (row[j] == 'B')
				{
                    SmallBrick * smallBrick = new SmallBrick(j*32, i*32);
					this->scene.addItem(smallBrick);
                    smallBrick = new SmallBrick(j*32 + 16, i*32);
					this->scene.addItem(smallBrick);
                    smallBrick = new SmallBrick(j*32, i*32 + 16);
					this->scene.addItem(smallBrick);
                    smallBrick = new SmallBrick(j*32 + 16, i*32 +16);
					this->scene.addItem(smallBrick);
                }
            }
        }
    }
}

