#include "enemy.h"
#include "bullet.h"
#include "armored.h"
#include "smallbrick.h"

#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QImage>
#include <QPixmap>
#include <QString>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QWidget>
#include <QTimer>
#include <QList>
#include <QGraphicsItem>


Enemy::Enemy(){
    QPixmap * pixmap = new QPixmap(":/tank/images/enemytank_down.png");
    this->setPixmap(*pixmap);
    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setTransformationMode(Qt::SmoothTransformation);

    //this->setFocus();
}

void Enemy::spawn()
{
    //Enemy * enemy = new Enemy();
    //scene()->addItem(enemy);
}

void Enemy::shot(){

    Bullet * bullet = new Bullet(rotation, "Enemy");

    sound.setMedia(QUrl("qrc:/gamesounds/Audio/explode.wav"));
    qDebug() <<  sound.duration();
    sound.play();
    this->timeLastBullet->start();

    if(rotation == "Up"){
        bullet->setPos(x() + 26, y());
    }
    else if(rotation == "Down"){
        bullet->setPos(x() + 26, y()+64);
    }
    else if(rotation == "Right"){
        bullet->setPos(x() + 64, y() + 26);
    }
    else if(rotation == "Left"){
        bullet->setPos(x(), y() + 26);
    }

    bullet->setFlags(QGraphicsItem::ItemIsFocusable);
    bullet->setFocus();

    scene()->addItem(bullet);
}

void Enemy::moveLeft(){
    QPixmap * pixmap = new QPixmap();
    pixmap->load(":/tank/images/enemytank_left.png");
    this->setPixmap(*pixmap);
    rotation = "Left";

    int xTankPos = this->pos().x() - 16;
    int yTankPos = this->pos().y();

    QGraphicsItem * leftItem;

    if(pos().x() > 0){

        for(int i = 0; i < 4; i++){
            leftItem = scene()->itemAt(QPointF((xTankPos), yTankPos + 16 * i), QTransform());
            if(leftItem){
                return;
            }
        }
        this->setPos(x() - 16, y());
    }

    qDebug()<< rotation;

}

void Enemy::moveRight(){

    QPixmap * pixmap = new QPixmap();
    pixmap->load(":/tank/images/enemytank_right.png");
    this->setPixmap(*pixmap);
    rotation = "Right";

    int xTankPos = this->pos().x() + 64;
    int yTankPos = this->pos().y();

    QGraphicsItem * rightItem;

    if(pos().x() < 768){
        for(int i = 0; i < 4; i++){
            rightItem = scene()->itemAt(QPointF((xTankPos), yTankPos + 16 * i), QTransform());
            if(rightItem){
                return;
            }
        }
        setPos(x() + 16, y());
    }
}

void Enemy::moveUp(){

    QPixmap * pixmap = new QPixmap();
    pixmap->load(":/tank/images/enemytank.png");
    this->setPixmap(*pixmap);
    rotation = "Up";

    int xTankPos = this->pos().x();
    int yTankPos = this->pos().y() - 16;

    QGraphicsItem * upItem;


    if(pos().y() > 0){
        for(int i = 0; i < 4; i++){
            upItem = scene()->itemAt(QPointF((xTankPos + i * 16), yTankPos), QTransform());
            if(upItem){
                return;
            }
        }
        setPos(x(), y() - 16);
    }
}

void Enemy::moveDown(){

    QPixmap * pixmap = new QPixmap();
    pixmap->load(":/tank/images/enemytank_down.png");
    this->setPixmap(*pixmap);
    rotation = "Down";

    QGraphicsItem * downItem;

    int xTankPos = this->pos().x();
    int yTankPos = this->pos().y() + 64 ;

    if(pos().y() < 768){
        for(int i = 0; i < 4; i++){
            downItem = scene()->itemAt(QPointF((xTankPos + i * 16), yTankPos), QTransform());
            if(downItem){
                return;
            }
        }
        setPos(x(), y() + 16);
    }
}

