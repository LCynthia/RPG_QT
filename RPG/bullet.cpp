#include "bullet.h"
#include "monster.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "bat.h"
#include "game.h"
#include<typeinfo>
#include <QDebug>
#include <stdlib.h>
#define Length 1900
#define Width 1100
extern Game * game; // there is an external global object called game

Bullet::Bullet(int d,string const &owner,float tan, bool sk,QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent),owner(owner),tan(tan){
    // draw graphics
    direction=d;
    skill=sk;
    QTimer * timer = new QTimer(this);
    if(owner=="player"){
       if(!skill){
             switch(game->getLevel()){
                case 1 :  setPixmap(QPixmap(":/image/bullet.png"));break;
                case 2 :  setPixmap(QPixmap(":/image/bullet3.png"));break;
                case 3 :  setPixmap(QPixmap(":/image/bullet2.png"));
              }
        }
       else{//special skill
           if(direction==1||direction==2)
              setPixmap(QPixmap(":/image/light1.png"));
           else
              setPixmap(QPixmap(":/image/light.png"));
        }
   }
    if(owner=="monster")
       setPixmap(QPixmap(":/image/light2.png"));//image/light2.png

     connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // make/connect a timer to move() the bullet every so often
     speed=20;
    // start the timer
    timer->start(50);
}


void Bullet::move(){
   QList<QGraphicsItem *> colliding_items = collidingItems();// get a list of all the items currently colliding with this bullet
   if(owner=="player"){// if one of the colliding items is an Enemy, destroy both the bullet and the enemy
        for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Bat)){
            game->score->increase(game->getLevel());// increase the score
            scene()->removeItem(colliding_items[i]); // remove them from the scene (still on the heap)
            scene()->removeItem(this);
            delete colliding_items[i];// delete them from the heap to save memory
            delete this;
            return;           // return (all code below refers to a non existint bullet)
        }
         if(typeid(*(colliding_items[i])) == typeid(Monster)){

            if(!game->getSurprise()){
               scene()->removeItem(colliding_items[i]);
               scene()->removeItem(this);
               delete this;
               delete colliding_items[i];
               game->changeScene(4);//change to surprse scene

             }
            else{
              game->monster->run();
              game->monster->injure();
              int m=(game->monster->getWound())+(game->health->getHealth())+rand()%40;
              if(skill)
                  m+=30;
               qDebug("%d\t%d\t%d ",game->monster->getWound(),game->health->getHealth(),m);
              if(m>=100){
                  scene()->removeItem(colliding_items[i]);
                  scene()->removeItem(this);
                  delete this;
                  delete colliding_items[i];
                  game->changeIsMonster();
                  game->score->increase(50);
                  game->changeScene(game->getLevel());
              }

             }
                return ;

        }
       }

    }
   else if(owner=="monster"){
       for (int i = 0, n = colliding_items.size(); i < n; ++i){
           if(typeid(*(colliding_items[i])) == typeid(Player)){
               game->health->decrease(3);
               delete this;
               return;
             }
        }

       if(direction==5)//左上
           setPos(x()-(game->getLevel()*40),y()-tan*(game->getLevel()*40));
       else if(direction==6)//右上
            setPos(x()+(game->getLevel()*40),y()-tan*(game->getLevel()*40));
       else if(direction==7)//左下
           setPos(x()-(game->getLevel()*40),y()+tan*(game->getLevel()*40));
       else if(direction==8)//右下
            setPos(x()+(game->getLevel()*40),y()+tan*(game->getLevel()*40));

   }
    // if there was no collision with an Enemy, move the bullet forward

    if(direction==1)
        setPos(x(),y()-(speed+game->getLevel()*10));
    else if(direction==2)
         setPos(x(),y()+(speed+game->getLevel()*10));
    else if(direction==3)
         setPos(x()-(speed+game->getLevel()*10),y());
    else if(direction==4)
         setPos(x()+(speed+game->getLevel()*10),y());
    // if the bullet is off the screen, destroy it
    if (pos().y() < 0||pos().y()>Width||pos().x()<0||pos().x()>Length){
        scene()->removeItem(this);
        delete this;
    }
}


