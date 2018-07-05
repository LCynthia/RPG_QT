#include "player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "bullet.h"
#include "bat.h"
#include"box.h"
#include "diamond.h"
#include"backpack.h"
#include<QList>
#include<typeinfo>
#include"game.h"
#include "monster.h"
#include <QGraphicsScene>
#include <monster.h>
#include <wealth.h>
#include <QDebug>
#include<cmath>
#include<npc.h>
extern Game *game ;



int Player::i1 = 0 ;
int Player::i2 = 0 ;
int Player :: i3 = 0 ;
int Player ::i4 = 0 ;

bool Player::judge_skil = false;

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){

    aa1 = 0 ;
    aa2 = 0 ;
    //set the former hurt ;
    coolTime=0;
    hurt_ability=1 ;
    skill=0;
    // set bullet sound
    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/image/bulletsound.mp3"));

    // set graphic
    setPixmap(QPixmap(":/image/D1.png"));
}

void Player::keyPressEvent(QKeyEvent *event){
    // move the player left and right

    if (event->key()==Qt::Key_1)
    {
        int a,b ;
        a = game->monster ->getX();
        b= game->monster->getY() ;

        game->skill1->setPos(a,b) ;
        aa1 = 1 ;

        scene()->addItem(game->skill1);

        game->monster->increase();

        game->health->decrease(1);

    }

    if(event->key()==Qt::Key_2)
    {
        int a ,b ;
        b = game->player->getX() ;
        a= game->player->getY() ;
        game->skill2->setPos(b,a) ;
        if(game->wealth->getWealth()>0)
        {
           scene()->addItem(game->skill2);
           game->wealth->increase(-1);
           aa2 = 1 ;
           game->health->decrease(-1);
        }


    }

    if((judge_skil==true)&&event->key()==Qt::Key_3)
    {

    }


    if (game->getLevel()==0&&event->key() == Qt::Key_Space){
        game->changeScene(game->upLevel());
    }
    else if (game->getLevel()>0&&event->key() == Qt::Key_Left){

        if(aa1==1)
        {
            scene()->removeItem(game->skill1);
            aa1= 0;
        }
        if(aa2 == 1)
        {
            scene()->removeItem(game->skill2);
            aa2 = 0 ;
        }

        //scene()->removeItem(game->skill1);
        //scene()->removeItem(game->skill2);
        if (pos().x() > 0)
        {
        setPos(x()-10,y());
        }

        i1++ ;
        int i ;
        i= i1%10 ;
        if(i==0)

        {
            setPixmap(QPixmap(":/image/L1.png"));
        }
        if(i==1)
        {
            setPixmap(QPixmap(":/image/L2.png"));
        }
        if(i==2)
        {
            setPixmap(QPixmap(":/image/L2.png"));
        }
        if(i==3)
        {
            setPixmap(QPixmap(":/image/L4.png"));;
        }
        if(i==4)
        {
            setPixmap(QPixmap(":/image/L5.png"));
        }
        if(i==5)
        {
            setPixmap(QPixmap(":/image/L5.png"));;
        }
        if(i==6)
        {
            setPixmap(QPixmap(":/image/L5.png"));
        }
        if(i==7)
        {
            setPixmap(QPixmap(":/image/L5.png"));
        }
        if(i==8)
        {
            setPixmap(QPixmap(":/image/L6.png"));;
        }
        if(i==9)
        {
           setPixmap(QPixmap(":/image/L6.png"));
        }
    }
    else if (game->getLevel()>0&&event->key() == Qt::Key_Right){
     //   scene()->removeItem(game->skill1);
       // scene()->removeItem(game->skill2);


        if(aa1==1)
        {
            scene()->removeItem(game->skill1);
            aa1= 0;
        }
        if(aa2 == 1)
        {
            scene()->removeItem(game->skill2);
            aa2 = 0 ;
        }

        if (pos().x() + 100 < 1920)
        {
        setPos(x()+10,y());
        }
        i2++ ;
        int i ;
        i= i2%10 ;
        if(i==0)
        {
            setPixmap(QPixmap(":/image/R1.png"));
        }
        if(i==1)
        {
            setPixmap(QPixmap(":/image/R2.png"));
        }
        if(i==2)
        {
            setPixmap(QPixmap(":/image/R3.png"));
        }
        if(i==3)
        {
            setPixmap(QPixmap(":/image/R4.png"));;
        }
        if(i==4)
        {
            setPixmap(QPixmap(":/image/R5.png"));
        }
        if(i==5)
        {
            setPixmap(QPixmap(":/image/R5.png"));;
        }
        if(i==6)
        {
            setPixmap(QPixmap(":/image/R6.png"));
        }
        if(i==7)
        {
            setPixmap(QPixmap(":/image/R6.png"));
        }
        if(i==8)
        {
            setPixmap(QPixmap(":/image/R7.png"));;
        }
        if(i==9)
        {
           setPixmap(QPixmap(":/image/R7.png"));
        }
    }
    else if(game->getLevel()>0&&event->key()==Qt::Key_Up){





        if(aa1==1)
        {
            scene()->removeItem(game->skill1);
            aa1= 0;
        }
        if(aa2 ==1)
        {
            scene()->removeItem(game->skill2);
            aa2 = 0 ;
        }

        //s/cene()->removeItem(game->skill1);
        //scene()->removeItem(game->skill2);
        if(pos().y()>10){
            setPos(x(),y()-10);
        }

        setPixmap(QPixmap(":/image/U1.png"));
    }
    else if(game->getLevel()>0&&event->key()==Qt::Key_Down){
        //scene()->removeItem(game->skill1);
       // scene()->removeItem(game->skill2);


        if(aa1==1)
        {
            scene()->removeItem(game->skill1);
            aa1= 0;
        }
        if(aa2 == 1)
        {
            scene()->removeItem(game->skill2);
            aa2 = 0 ;
        }

        if(pos().y()+70<1080)
        {
            setPos(x(),y()+10) ;
        }

        i3++ ;
        int i ;
        i= i3%10 ;
        if(i==0)
        {
            setPixmap(QPixmap(":/image/D1.png"));
        }
        if(i==1)
        {
            setPixmap(QPixmap(":/image/D1.png"));
        }
        if(i==2)
        {
            setPixmap(QPixmap(":/image/D1.png"));
        }
        if(i==3)
        {
            setPixmap(QPixmap(":/image/D2.png"));;
        }
        if(i==4)
        {
            setPixmap(QPixmap(":/image/D2.png"));
        }
        if(i==5)
        {
            setPixmap(QPixmap(":/image/D3.png"));;
        }
        if(i==6)
        {
            setPixmap(QPixmap(":/image/D3.png"));
        }
        if(i==7)
        {
            setPixmap(QPixmap(":/image/D4.png"));
        }
        if(i==8)
        {
            setPixmap(QPixmap(":/image/D4.png"));;
        }
        if(i==9)
        {
           setPixmap(QPixmap(":/image/D4.png"));
        }
    }
    // shoot with the spacebar

        // create a bullet
      /*  Bullet * bullet = new Bullet();
        bullet->setPos(x()+45,y());
        scene()->addItem(bullet);

        // play bulletsound
        if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
    }*/
    //
    else if (event->key() == Qt::Key_W){
        Bullet * bullet= new Bullet(1,"player");
        bullet->setPos(x()+30,y()+30);
        scene()->addItem(bullet);
            // play bulletsound
        if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
           }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
           }
        }
    else if (game->getLevel()>0&&event->key() == Qt::Key_S){
                    // create a bullet
         Bullet * bullet= new Bullet(2,"player");
         bullet->setPos(x()+30,y()+30);
         scene()->addItem(bullet);
                    // play bulletsoun
         if (bulletsound->state() == QMediaPlayer::PlayingState){
              bulletsound->setPosition(0);
             }
         else if (bulletsound->state() == QMediaPlayer::StoppedState){
              bulletsound->play();

           }
        }
    else if (game->getLevel()>0&&event->key() == Qt::Key_A){
                // create a bullet
          Bullet * bullet = new Bullet(3,"player");
          bullet->setPos(x()+30,y()+30);
          scene()->addItem(bullet);

                // play bulletsound
          if (bulletsound->state() == QMediaPlayer::PlayingState){
                bulletsound->setPosition(0);
                }
          else if (bulletsound->state() == QMediaPlayer::StoppedState){
                bulletsound->play();
                }
        }
    else if (game->getLevel()>0&&event->key() == Qt::Key_D){
            // create a bullet
        Bullet * bullet = new Bullet(4,"player");
        bullet->setPos(x()+30,y()+30);
        scene()->addItem(bullet);

            // play bulletsound
         if (bulletsound->state() == QMediaPlayer::PlayingState){
                bulletsound->setPosition(0);
            }
         else if (bulletsound->state() == QMediaPlayer::StoppedState){
                bulletsound->play();
            }
    }
    else if(game->Gameover()&&event->key() == Qt::Key_Y){
        qDebug("gameover");
        game->reStart();
        game->changeScene(1);


        }
    else if(game->Gameover()&&event->key() == Qt::Key_N)
        exit(0);



    else if (game->getLevel()>0&&event->key() == Qt::Key_N){
        game->backpack->Open();
    }
    else if (game->getLevel()>0&&event->key() == Qt::Key_C){
        game->backpack->Close();
    }


    else if(game->getLevel()==2&&event->key()==Qt::Key_Y){
        game->store->change();
        game->store->button1->setVisible(true);
        game->store->button1->setVisible(true);
        game->store->button1->setVisible(true);
        game->store->button1->setVisible(true);
    }


    if(game->getSurprise()&&game->IsMonster()&&skill&&!coolTime){
        if(event->key() == Qt::Key_I){
            Bullet * bullet = new Bullet(1,"player",1.0,1);
            bullet->setPos(x()-50,y()-250);
            scene()->addItem(bullet);
            skill--;
            coolTime++;

        }
        if(event->key() == Qt::Key_K){
            Bullet * bullet = new Bullet(2,"player",1.0,1);
            bullet->setPos(x()-50,y()-250);
            scene()->addItem(bullet);
            skill--;
            coolTime++;
        }

        if(event->key() == Qt::Key_J){
            Bullet * bullet = new Bullet(3,"player",1.0,1);
            bullet->setPos(x()-250,y());
            scene()->addItem(bullet);
            skill--;
            coolTime++;
        }
        if(event->key() == Qt::Key_L){
            Bullet * bullet = new Bullet(4,"player",1.0,1);
            bullet->setPos(x()-250,y());
            scene()->addItem(bullet);
            skill--;
            coolTime++;
        }

    }
     QList<QGraphicsItem *> colliding_items = collidingItems();

    // if one of the colliding items is an Enemy, destroy both the bullet and the enemy
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Store)){
            game->store->saying->setPixmap(QPixmap(":/image/say1.jpg"));
            game->store->say=1;
            scene()->addItem(game->store->saying);


       }
       if(typeid(*(colliding_items[i])) == typeid(Monster)){


          if(!game->getSurprise()){//change to surprse scene;
               scene()->removeItem(colliding_items[i]);
               delete colliding_items[i];
               game->changeScene(4);
               game->changeSurprise();

           }
          else{
               game->health->decrease(1);
               game->monster->run();
          }

       }
       if(typeid(*(colliding_items[i])) == typeid(Box)){
           scene()->removeItem(colliding_items[i]);
           delete colliding_items[i];
           game->backpack->add(4,1);
           game->wealth->increase();
         }

    /*   if(typeid(*(colliding_items[i])) == typeid(Npc))
       {
               if(x()<1200)
               {
                   game->scene1->addItem(game->saying1);
               }
               else
               {
                   game->scene1->addItem(game->saying2);
               }
        }
        else
       {
          game->scene1->removeItem(game->saying1);
          game->scene1->removeItem(game->saying2);
    }*/

       if(typeid(*(colliding_items[i])) == typeid(Diamond)){
           Diamond *diamond=static_cast<Diamond *>(colliding_items[i]);
           int type=diamond->Type();
           game->backpack->add(type,1);
           if(!game->getSurprise()){
                skill+=type;
               // qDebug("%d",diamond->Type());

           }
           else{
                game->health->decrease(-5-rand()%5);
                skill+=3;
                game->changeSurprise();
             }
           scene()->removeItem(colliding_items[i]);
           delete colliding_items[i];
    }
    }
    if(game->getLevel()==1&&game->score->getScore()>=50){
        if(abs(x()-1600)<50&&abs(y()-500)<30){
            game->changeScene(game->upLevel());
        }
    }

    if(game->getLevel()==2&&game->score->getScore()>=100&&!game->getSurprise())
        if(abs(x()-100)<80&&abs(y()-50)<50){
            game->changeScene(game->upLevel());
        }
}


int Player::getSkill()
{
    return skill;
}

int Player::getX()
{
    return x() ;
}

int Player::getY()
{
    return y() ;
}



void Player::spawn(){
    // create an enemy
    if(game->saying1->say){
        game->saying1->sayTime=(game->saying1->sayTime+1)%2;
        if(game->saying1->sayTime==0)
            scene()->removeItem(game->saying1);
    }
    if(game->saying2->say){
        game->saying2->sayTime=(game->saying2->sayTime+1)%2;
        if(game->saying2->sayTime==0)
            scene()->removeItem(game->saying2);
    }
    if(game->saying3->say){
        game->saying3->sayTime=(game->saying3->sayTime+1)%2;
        if(game->saying3->sayTime==0)
            scene()->removeItem(game->saying3);
    }


    if(game->store->say){
        game->store->saying->sayTime=(game->store->sayTime+1)%2;
        if(game->store->sayTime==0)
            scene()->removeItem(game->store->saying);
    }


    if(coolTime)
        coolTime=(coolTime+1)%10;
    if(game->health->getHealth()<=0)
        game->changeScene(5);

    if(game->getLevel()>0&&!game->getSurprise()){
        int i=rand()%60;
        if(i==1){
            Box * box=new Box();
            scene()->addItem(box);
             }
        if(i==2){
            Diamond * diamond=new Diamond(1);
            scene()->addItem(diamond);
            qDebug("diamond1");
        }
        if(i==3)
        {
            Diamond * diamond=new Diamond(2);
            scene()->addItem(diamond);
            qDebug("diamond2");
         }
    }
    if(game->getLevel()==1){
            Bat * bat = new Bat();
            scene()->addItem(bat);
      }
    if(game->getLevel()>1&&!game->getSurprise()&&!game->IsMonster()&&rand()%30==8){

            Monster * monster=new Monster();
            scene()->addItem(monster);
            game->changeIsMonster();
            qDebug("monster");
        }

    if(game->getSurprise()&&game->IsMonster()){
       game->monster->attack();
    }
}


