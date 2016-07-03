#ifndef BOARD_H
#define BOARD_H

#include "board.h"
#include <QObject>
#include <QGraphicsRectItem>
#include <QKeyEvent>

class Board: public QObject, public QGraphicsRectItem{
   /* Q_OBJECT
public:
    void keyPressEvent(QKeyEvent * event);
public slots:
    void spawn();*/
};
#endif // BOARD_H
