#include "bullet.h"
#include <QDebug>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
//#include <Enemy.h>
#include <QGraphicsItem>
#include <QString>
#include "smallbrick.h"
#include "armored.h"
#include <QPointF>

Bullet::Bullet(QString rotation){

    sound.setMedia(QUrl("qrc:/gamesounds/Audio/shoot.wav"));
    qDebug() <<  sound.duration();
    sound.play();

    this->rotation = rotation;

    if(this->rotation == "Up"){
        pixmap.load(":/player/images/bullet.png");
    }
    else if(this->rotation == "Down"){
        pixmap.load(":/player/images/bullet_down.png");
    }
    else if(this->rotation == "Right"){
        pixmap.load(":/player/images/bullet_right.png");
    }
    else if(this->rotation == "Left"){
        pixmap.load(":/player/images/bullet_left.png");
    }
    this->setPixmap(pixmap);

    this->rotation = rotation;

    connect(&timer, SIGNAL(timeout()), this, SLOT(move()));

    timer.start(15);
}

void Bullet::move(){

    colliding_items = collidingItems();

    //qDebug() << "size = " << this->colliding_items.size();

    for(int i = 0, n = colliding_items.size(); i< n; i++){
        if(typeid(*(colliding_items[i])) == typeid(SmallBrick)){
            //delete both objects
            removeBricks(i);
            return;
        }else if(typeid(*(colliding_items[i])) == typeid(Armored)){
            scene()->removeItem(this);
            delete this;
            return;
        }else if(typeid(*(colliding_items[i])) == typeid(Bullet)){
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    //move bullet
    if(this->rotation == "Up"){
        setPos(x(), y() - 10);
        if(pos().y() < 0){
            scene()->removeItem(this);
            delete this;
        }
    }
    else if(this->rotation == "Down"){
        setPos(x(), y() + 10);
        if(pos().y() > 832){
            scene()->removeItem(this);
            delete this;
        }
    }
    else if(this->rotation == "Right"){
        setPos(x() + 10, y());
        if(pos().x() > 832){
            scene()->removeItem(this);
            delete this;
        }
    }
    else if(this->rotation == "Left"){
        setPos(x() - 10, y());
        if(pos().x() < 0){
            scene()->removeItem(this);
            delete this;
        }
    }
}
void Bullet::removeBricks(int i){
    int coordX = this->colliding_items[i]->pos().x();
    int coordY = this->colliding_items[i]->pos().y();

    scene()->removeItem(this->colliding_items[i]);

    if(this->rotation == "Up"){

        for(int j = 0; j < this->colliding_items.size(); j++){

            if((colliding_items[j]->pos().y() == coordY) && (typeid(*(colliding_items[j])) == typeid(SmallBrick))){

                if(colliding_items[j]->pos().x() == (coordX - 16)){

                    //qDebug() << "right " << this->colliding_items[j]->pos().x();

                    QGraphicsItem * right = scene()->itemAt(QPointF((coordX + 16), coordY), QTransform());
                    QGraphicsItem * left = scene()->itemAt(QPointF((coordX - 32), coordY), QTransform());
                    //QGraphicsItem * under;

                    if(right && (typeid(*right) ) == typeid(SmallBrick)){
                        //under = scene()->itemAt(QPointF(right->pos().x(), right->pos().y()+16), QTransform());
                        //if(!under){
                            //if(typeid(*(under)) == typeid(SmallBrick)){
                                qDebug() << "right is ";
                                scene()->removeItem(right);
                                delete right;
                            //}
                        //}
                    }
                    if(left && (typeid(*left) ) == typeid(SmallBrick)){
                        //under = scene()->itemAt(QPointF(left->pos().x(), left->pos().y()+16), QTransform());
                        //if(!under){
                            qDebug() << "left is ";
                            scene()->removeItem(left);
                            delete left;
                        //}
                    }
                    scene()->removeItem(colliding_items[j]);
                    delete colliding_items[j];
                }
            }
        }
    } else if(this->rotation == "Down"){

    } else if(this->rotation == "Left"){

    } else if(this->rotation == "Right"){

    }

    scene()->removeItem(this);
    delete colliding_items[i];
    delete this;
}
