#include "Player.h"
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


Player::Player(){
    QPixmap * pixmap = new QPixmap(":/player/images/mytank.png");
    this->setPixmap(*pixmap);
    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setTransformationMode(Qt::SmoothTransformation);
    this->setPos(256, 768);
    this->setFocus();
}

void Player::keyPressEvent(QKeyEvent * event){

    //QPixmap * pixmap = new QPixmap();

    if(event->key() == Qt::Key_Left){
        moveLeft();
    }
    else if(event->key() == Qt::Key_Right){
        moveRight();
    }
    else if(event->key() == Qt::Key_Up){
        moveUp();
    }
    else if(event->key() == Qt::Key_Down){
        moveDown();
    }

    else if(event->key() == Qt::Key_Space){
        //create a bullet
        //qDebug() << this->timeLastBullet->msec() << "check last bullet msec";

        if((this->timeLastBullet->elapsed() > 200) || (this->timeLastBullet->msec() == -1)){
            this->timeLastBullet->restart();
            //this->timeLastBullet->start();
            //qDebug() << this->timeLastBullet->msec() << "restart msec";
            this->shot();
        }
        //QTimer * timer = new QTimer();
    }
}

void Player::spawn()
{
    //Enemy * enemy = new Enemy();
    //scene()->addItem(enemy);
}

void Player::shot(){

    Bullet * bullet = new Bullet(rotation);
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

void Player::moveLeft(){
    QPixmap * pixmap = new QPixmap();
    pixmap->load(":/player/images/mytank_left.png");
    this->setPixmap(*pixmap);
    rotation = "Left";

    int xTankPos = this->pos().x() - 16;
    int yTankPos = this->pos().y();

    //qDebug() << "tank "<< this->pos().x() << " " << this->pos().y();

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

void Player::moveRight(){

    QPixmap * pixmap = new QPixmap();
    pixmap->load(":/player/images/mytank_right.png");
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

void Player::moveUp(){

    QPixmap * pixmap = new QPixmap();
    pixmap->load(":/player/images/mytank.png");
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

void Player::moveDown(){

    QPixmap * pixmap = new QPixmap();
    pixmap->load(":/player/images/mytank_down.png");
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

