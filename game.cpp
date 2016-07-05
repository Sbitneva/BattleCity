#include "Game.h"
#include <QWidget>
#include <QTimer>
#include "player.h"
#include <QImage>
#include <QString>
#include <QPixmap>
#include <smallbrick.h>
#include <QDebug>
#include <QTextStream>
#include <armored.h>
#include <enemy.h>


Game::Game(QWidget * parent){

    scene = new QGraphicsScene();
    scene->setSceneRect(0,0, 832, 832);
    scene->setBackgroundBrush(Qt::black);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(832, 832);
    setScene(scene);    

    createObstacles();
    player = new Player();
    scene->addItem(player);
    Enemy * enemy = new Enemy();
    scene->addItem(enemy);

    QTimer * timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(200);

    show();
}

void Game::loadMapFromFile(){

    QFile *  mapFile =  new QFile(":/maps/maps/level1.map");

        if(mapFile->open(QIODevice::ReadOnly | QIODevice::Text)){

            QTextStream * textStream = new QTextStream(mapFile);
            QVector<QString> row(26);
            QVector<QVector<QString>>  mapMatrix(26);
            QString  mychar;

            for(int i = 0; i < 26; i++){

                for(int j = 0; j < 26; j++){

                    mychar = textStream->read(1);
                    if(mychar == "\n"){
                        mychar = textStream->read(1);
                    }
                    row[j] = mychar;

                }
                mapMatrix[i] = row;
            }
            this->mapMatrix = mapMatrix;

        }else{
            //qDebug() << mapFile->errorString();
        }
}

void Game::createObstacles(){
    this->loadMapFromFile();

    QVector<QString> row(26);

    if(mapMatrix.size()>0){

        for(int i = 0; i < this->mapMatrix.size(); i++){
            row = mapMatrix[i];
            for(int j = 0; j < row.size(); j++){
                if(row[j] == "A"){
                    Armored * armored = new Armored(j*32, i * 32);
                    scene->addItem(armored);

                }else if (row[j] == "B"){
                    SmallBrick * smallBrick = new SmallBrick(j*32, i*32);
                    scene->addItem(smallBrick);
                    smallBrick = new SmallBrick(j*32 + 16, i*32);
                    scene->addItem(smallBrick);
                    smallBrick = new SmallBrick(j*32, i*32 + 16);
                    scene->addItem(smallBrick);
                    smallBrick = new SmallBrick(j*32 + 16, i*32 +16);
                    scene->addItem(smallBrick);
                }
            }
        }
    }
}

