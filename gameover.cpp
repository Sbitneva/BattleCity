#include "gameover.h"
#include <QPixmap>

GameOver::GameOver(){
    pixmap = new QPixmap(":/ui/images/game_over.png");
    this->setPixmap(*pixmap);
    this->setPos(292, 292);
}
