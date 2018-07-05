#include "monster.h"
#include <QTimer>
#include <QGraphicsScene>
#include <typeinfo>
#include <stdlib.h> // rand() -> really large int
#include "game.h"
#include <cmath>
#include <bullet.h>
extern Game * game;
Monster::Monster(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    wound=50;
    switch(game->getLevel()){
        case 2 :   setPixmap(QPixmap(":/image/wicked.png"));break;
        case 3 :   setPixmap(QPixmap(":/image/wicked2.png"));break;
    }

    setPos(500,400);
    //run();
}

void Monster::run()
{
    int i=rand()%3;
    int x,y;
    if(i==0){
       x=(game->player->x()+600);
       y=(game->player->y()-500);
     }
    else if(i==1){
        x=(game->player->x()+600);
        y=(game->player->y()+500);
    }
    else if(i==2){
        x=(game->player->x()-600);
        y=(game->player->y()+500);
    }
    else if(i==3){
        x=(game->player->x()-600);
        y=(game->player->y()-500);
    }
    x%=1900;
    y%=800;
    if(x<0)
        x+=1900;
    if(x<500)
        x+=500;

    if(y<0)
        y+=800;
    setPos(x,y);
}

int Monster::getWound()
{
    return wound;
}

int Monster::getX()
{
    return x() ;
}

int Monster::getY()
{
    return y() ;
}

void Monster::injure()
{
    if(wound<50)
        wound=wound+game->player->getHurtAbility();
}

void Monster::increase()
{
    wound++ ;
    return ;

}




void Monster::attack(){
    int distx=game->player->x()-x();
    int disty=game->player->y()-y();
    float tan=fabs(disty/distx);
    Bullet * bullet;
    if(distx>0){
       if(disty==0)
         bullet=new Bullet(4,"monster");
       else if(disty>0)
         bullet=new Bullet(8,"monster",tan);
       else if(disty<0)
         bullet=new Bullet(6,"monster",tan);
    }
    else if(distx<0){
        if(disty==0)
           bullet=new Bullet(3,"monster");
        else if(disty>0)
           bullet=new Bullet(7,"monster",tan);
        else if(disty<0)
           bullet=new Bullet(5,"monster",tan);
    }
    else if(distx==0){
        if(disty>0)
          bullet=new Bullet(1,"monster");
        else if(disty<0)
          bullet=new Bullet(2,"monster");
    }
    bullet->setPos(x()+30,y()+30);
    scene()->addItem(bullet);
}
