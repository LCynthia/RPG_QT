#include "bat.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand() -> really large int
#include "game.h"

extern Game * game;

Bat::Bat(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    //set random x position
    int random_number = rand() % 1000;
    int random_number2=rand()%1000 ;
    setPos(random_number2,random_number);

    // drew the rect
    setPixmap(QPixmap(":/image/bat.png"));
    //setTransformOriginPoint(50,50);
   // setRotation(180);

    // make/connect a timer to move() the enemy every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(200);
}

void Bat::move(){
    if(!game->getSurprise()){

        int xx=rand()%10 ;
        int yy=rand()%20;
        // move enemy down


        setPos(x()+xx,y()+yy);

        // destroy enemy when it goes out of the screen
        if (pos().y() > 1080){
            scene()->removeItem(this);
            delete this;
        }
     }

}
