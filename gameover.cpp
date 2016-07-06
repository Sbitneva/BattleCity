#include "gameover.h"

GameOver::GameOver()
{
    this->pixmap.load(":/ui/images/game_over.png");
    this->setPixmap(this->pixmap);
    this->setPos(292, 292);
    this->sound.setMedia(QUrl("qrc:/ui/Audio/fire.wav"));
	this->sound.play();
}
