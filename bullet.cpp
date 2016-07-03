#include "bullet.h"
#include <QDebug>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
//#include <Enemy.h>
#include <QGraphicsItem>
#include <QString>

Bullet::Bullet(QString rotation){

    QPixmap * pixmap = new QPixmap();

    this->rotation = rotation;

    if(this->rotation == "Up"){
        pixmap->load(":/player/images/bullet.png");
    }
    else if(this->rotation == "Down"){
        pixmap->load(":/player/images/bullet_down.png");
    }
    else if(this->rotation == "Right"){
        pixmap->load(":/player/images/bullet_right.png");
    }
    else if(this->rotation == "Left"){
        pixmap->load(":/player/images/bullet_left.png");
    }
    this->setPixmap(*pixmap);

    this->rotation = rotation;

    qDebug() << "bullet created: " << rotation;

    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(20);
}

void Bullet::move(){
    //destroy enemy
    /*QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i< n; i++){
        if(typeid(*(colliding_items[i])) == typeid(Enemy)){
            //remove both: an enemy and bullet
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            //delete both objects
            delete colliding_items[i];
            delete this;
            return;
        }
    }
    */
    //move bullet
    if(this->rotation == "Up"){
        setPos(x(), y() - 10);
        if(pos().y() < 0){
            scene()->removeItem(this);
            delete this;
            qDebug() << "bullet deleted";
        }
    }
    else if(this->rotation == "Down"){
        setPos(x(), y() + 10);
        if(pos().y() > 832){
            scene()->removeItem(this);
            delete this;
            qDebug() << "bullet deleted";
        }
    }
    else if(this->rotation == "Right"){
        setPos(x() + 10, y());
        if(pos().x() > 832){
            scene()->removeItem(this);
            delete this;
            qDebug() << "bullet deleted";
        }
    }
    else if(this->rotation == "Left"){
        setPos(x() - 10, y());
        if(pos().x() < 0){
            scene()->removeItem(this);
            delete this;
            qDebug() << "bullet deleted";
        }
    }
}
