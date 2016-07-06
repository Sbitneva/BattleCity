#include "gameover.h"
#include <QPixmap>
#include <QMediaPlayer>

GameOver::GameOver(){
    pixmap = new QPixmap(":/ui/images/game_over.png");
    this->setPixmap(*pixmap);
    this->setPos(292, 292);
    sound = new QMediaPlayer();
    sound->setMedia(QUrl("qrc:/ui/Audio/fire.wav"));
    sound->play();
}
