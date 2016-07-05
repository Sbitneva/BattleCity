#include "brickwall.h"
#include "smallbrick.h"
#include <QDebug>
#include <QGraphicsScene>

BrickWall::BrickWall(int x, int y, QGraphicsScene * scene){
    this->scene = scene;
    qDebug() << "Brick wall " << x << " "<< y;
    int xStartCoord = 32*x;
    int yStartCoord = 32*y;

    SmallBrick * smallBrick = new SmallBrick(xStartCoord, yStartCoord);
    //scene->addItem(smallBrick);
    qDebug() << "small brick created";
    //this->scene->addItem(smallBrick);
    //smallBrick = new SmallBrick(xStartCoord + 32, yStartCoord);
    //smallBrick = new SmallBrick(xStartCoord, yStartCoord + 32);
    //smallBrick = new SmallBrick(xStartCoord + 32, yStartCoord + 32);
}
