#include "Player.h"
#include "bullet.h"

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

Player::Player(){
    QPixmap * pixmap = new QPixmap(":/player/images/mytank.png");
    this->setPixmap(*pixmap);
    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setTransformationMode(Qt::SmoothTransformation);
    this->setPos(384, 768);
    this->setFocus();
}

void Player::keyPressEvent(QKeyEvent * event){

    QPixmap * pixmap = new QPixmap();

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
        qDebug() << this->timeLastBullet->msec() << "check last bullet msec";

        if((this->timeLastBullet->elapsed() > 800) || (this->timeLastBullet->msec() == -1)){
            this->timeLastBullet->restart();
            //this->timeLastBullet->start();
            qDebug() << this->timeLastBullet->msec() << "restart msec";
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

    if(pos().x() > 0)
        this->setPos(x() - 8, y());
        pixmap->load(":/player/images/mytank_left.png");
        this->setPixmap(*pixmap);
        rotation = "Left";
        //qDebug()<< rotation;
}

void Player::moveRight(){
    QPixmap * pixmap = new QPixmap();

    if(pos().x() < 768)
            setPos(x() + 8, y());
        pixmap->load(":/player/images/mytank_right.png");
        this->setPixmap(*pixmap);
        rotation = "Right";
        //qDebug()<< rotation;
}

void Player::moveUp(){
    QPixmap * pixmap = new QPixmap();

    if(pos().y() > 0)
    setPos(x(), y() - 8);
    pixmap->load(":/player/images/mytank.png");
    this->setPixmap(*pixmap);
    rotation = "Up";
    //qDebug()<< rotation;
}

void Player::moveDown(){
    QPixmap * pixmap = new QPixmap();

    if(pos().y() < 768)
        setPos(x(), y() + 8);
    pixmap->load(":/player/images/mytank_down.png");
    this->setPixmap(*pixmap);
    rotation = "Down";
    //qDebug()<< rotation;
}

