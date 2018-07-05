#include "game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "bat.h"
#include <QMediaPlayer>
#include <QBrush>
#include <QImage>
#include <stdlib.h>
#include <QDebug>
#define Length 1920
#define Width 1080
Game::Game(QWidget *parent){

    scene = new QGraphicsScene();
    scene1=new QGraphicsScene();
    scene2 = new QGraphicsScene();
    scene3=new QGraphicsScene();
    scene4=new QGraphicsScene();
    scene5=new QGraphicsScene();
    scene->setSceneRect(0,0,Length,Width);
    scene1->setSceneRect(0,0,Length,Width); // make the scene 800x600 instead of infinity by infinity (default)
    scene2->setSceneRect(0,0,Length,Width);
    scene3->setSceneRect(0,0,Length,Width);
    scene4->setSceneRect(0,0,Length,Width);
    scene5->setSceneRect(0,0,Length,Width);
    setBackgroundBrush(QBrush(QImage(":/image/scene.jpg")));
    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(Length,Width);

    saying1=new Saying();
    saying1->setPixmap(QPixmap(":/image/level01.jpg"));

    saying2=new Saying();
    saying2->setPixmap(QPixmap(":/image/level02.jpg"));

    saying3=new Saying();
    saying3->setPixmap(QPixmap(":/image/level03.jpg"));

    // create the player
    level=0;
    surprise=0;
    isMonster=0;
    gameover=0;
    plot=0;
    player = new Player();
    player->setPos(1000,500); // TODO generalize to always be in the middle bottom of screen
    // make the player focusable and set it to be the current focus
    //player->setFlag(QGraphicsItem::ItemIsFocusable);
   // player->setFocus();
   // scene->addItem(player);
    button=new QPushButton();
    button->setGeometry(QRect(QPoint(1000, 800), QSize(80, 50)));
    button->setText("start");
    button->setStyleSheet("background:yellow");
    //button->setIcon(QIcon("/:button.jpg"));
    button->setParent(this);
    QObject::connect(button, SIGNAL(released()), this, SLOT(handleButton()));
    //startButton->show();
    scene->addWidget(button);


    // create the score/health
    score = new Score();
   // score->setPos(1600,500);
    //scene->addItem(score);
    health = new Health();
    health->setPos(health->x(),health->y()+25);
    //scene->addItem(health);
    wealth =new Wealth();
    wealth->setPos(wealth->x(),wealth->y()+50);
    // spawn enemies
    backpack=new Backpack();
    store=new Store();
    store->setPos(0,500);
    //scene->addItem(store);
    QObject::connect(store->button1, SIGNAL(released()), this, SLOT(handle1()));
    QObject::connect(store->button2, SIGNAL(released()), this, SLOT(handle2()));
    QObject::connect(store->button3, SIGNAL(released()), this, SLOT(handle3()));
    QObject::connect(store->button4, SIGNAL(released()), this, SLOT(handle4()));
    QObject::connect(store->close, SIGNAL(released()), this, SLOT(closeStore()));

    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

    skill1 = new Skill () ;

    skill2 = new Skill() ;

    skill1->setPixmap(QPixmap(":/image/skill1.png")) ;
    skill2->setPixmap(QPixmap(":/image/skill2.png")) ;






   /* npc = new Npc() ;

    npc->setPos(100,100);

    npc2 = new Npc() ;

    npc2->setPixmap(QPixmap(":/image/npc2.png"));

    npc2->setPos(1500,600);

    saying1 = new Saying() ;

    saying1 -> setPos(100,100);

    saying1->setPixmap(QPixmap(":/image/saying2.jpg"));

    saying2 = new Saying() ;

    saying2->setPixmap(QPixmap(":/image/saying4.jpg"));

    saying2->setPos(1500,600);


    skill_2 = new Saying() ;

    skill_3 = new Saying() ;

    skill_2->setPixmap(QPixmap(":/image/skill2.png"));

    skill_3->setPixmap(QPixmap(":/image/skill3.png"));

    skill_2->setPos(600,600);

    skill_3->setPos(600,600);

    skill_1 =  new  Saying () ;

    skill_1->setPixmap(QPixmap(":/image/skill1.png")) ;
    skill_1->setPos(600,600) ;

    //store is added here
    //store=new Store() ;
   // scene->addItem(store);

    //add a gun ;
    //gun=new Gun() ;
   // scene->addItem(gun);
    //monster=new Monster();
  //  scene->addItem(monster);

*/


    // play background music
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/image/bksound.mp3"));
    music->play();

    show();
}

int Game::upLevel()
{
    return ++level;
}

int Game::getLevel()
{
    return level;
}

bool Game::getSurprise()
{
    return surprise;
}

void Game::changeSurprise()
{
    if(surprise)
        surprise=0;
    else
        surprise=1;
}


void Game::changeScene(int i)
{
    if(i==0){//start scene;
        setBackgroundBrush(QBrush(QImage(":/image/scene.jpg")));
       /* scene->addItem(score);
        scene->addItem(player);
        scene->addItem(health);
        scene->addItem(wealth);*/
        setScene(scene);
    }
    else if(i==1){

        setBackgroundBrush(QBrush(QImage(":/image/scene1.jpg")));
        scene1->addItem(score);
        scene1->addItem(player);

        scene1->addItem(saying1);
        saying1->say=1;




        scene1->addItem(health);
        scene1->addItem(wealth);
        setScene(scene1);
       scene1->addItem(backpack);


    }
    else if(i==2){
        setBackgroundBrush(QBrush(QImage(":/image/scene2.jpg")));
        scene2->addItem(score);
        scene2->addItem(player);
        scene2->addItem(health);
        scene2->addItem(wealth);
        setScene(scene2);
        if(surprise){
           Diamond * diamond=new Diamond(3);
           scene2->addItem(diamond);
        }
        scene2->addItem(backpack);
        scene2->addItem(store);
        scene2->addItem(saying2);
        saying2->say=1;

    }
    else if(i==3){
        setBackgroundBrush(QBrush(QImage(":/image/scene3.jpg")));
        scene3->addItem(score);
        scene3->addItem(player);
        scene3->addItem(health);
        scene3->addItem(wealth);
        setScene(scene3);
        if(surprise){
           Diamond * diamond=new Diamond(3);
           scene3->addItem(diamond);
        }
        scene3->addItem(backpack);
        scene3->addItem(saying3);
        saying3->say=1;
    }
    else if(i==4){//suprise scene;
        setBackgroundBrush(QBrush(QImage(":/image/scene4.jpg")));
        monster =new Monster();
        scene4->addItem(monster);
        scene4->addItem(score);
        scene4->addItem(player);
        scene4->addItem(health);
        scene4->addItem(wealth);
        setScene(scene4);
        if(!IsMonster())
            changeIsMonster();
        if(!getSurprise())
            changeSurprise();
        scene4->addItem(backpack);
       // scene4->addItem(backpack);
    }
    else if(i==5){
        gameover=1;
        setBackgroundBrush(QBrush(QImage(":/image/gameover.jpg")));
        scene5->addItem(player);
        setScene(scene5);

    }
    if(i>0){
        player->setFlag(QGraphicsItem::ItemIsFocusable);
        player->setFocus();
    }

}

bool Game::IsMonster()
{
    return isMonster;

}

void Game::changeIsMonster()
{
    if(isMonster)
        isMonster=0;
    else
        isMonster=1;
}

void Game::reStart()
{
    level=1;
    surprise=0;
    isMonster=0;
    gameover=0;
    score->Initial();
    health->Initial();
    wealth->Initial();
    wealth->Initial();
    // spawn enemies
    backpack->Initial();
    qDebug("%d%d%d",score->getScore(),health->getHealth(),wealth->getWealth());
  /*  scene1->clear();
    scene2->clear();
    scene3->clear();
    scene4->clear();
    scene5->clear();*/

}


void Game::handleButton()
{
    if(plot==0)
        button->setText("next");
    plot++;
    if(plot==1)
        setBackgroundBrush(QBrush(QImage(":/image/scenario1.jpg")));
    if(plot==2)
        setBackgroundBrush(QBrush(QImage(":/image/scenario4.jpg")));
    if(plot==3)
        setBackgroundBrush(QBrush(QImage(":/image/scenario2.png")));
    if(plot==4)
        setBackgroundBrush(QBrush(QImage(":/image/secnario3.png")));
    if(plot==5)
        setBackgroundBrush(QBrush(QImage(":/image/scenario5.png")));
    if(plot==6){
        changeScene(upLevel());
        button->setVisible(false);
        qDebug("press button");
    }

}
void Game::handle1()
{
    if(wealth->getWealth()>1999){
        backpack->add(3,1);
        wealth->increase(-1999);
        store->saying->setPixmap(QPixmap(":/image/buydiamond3.jpg"));

    }
    else{
        store->saying->setPixmap(QPixmap(":/image/nomoney.jpg"));;
    }
    scene2->addItem(store->saying);
    store->say=1;
    qDebug("press");

}
void Game::handle2()
{
    if(wealth->getWealth()>999){
        backpack->add(5,1);
        wealth->increase(-999);
        store->saying->setPixmap(QPixmap(":/image/buymagicwater.jpg"));

    }
    else{
        store->saying->setPixmap(QPixmap(":/image/nomoney.jpg"));
    }
    qDebug("press");
    scene2->addItem(store->saying);
    store->say=1;

}

void Game::handle3()
{
    if(wealth->getWealth()>699){
        backpack->add(2,1);
        wealth->increase(-699);
        store->saying->setPixmap(QPixmap(":/image/buydiamond2.jpg"));

    }
    else{
        store->saying->setPixmap(QPixmap(":/image/nomoney.jpg"));
    }
    qDebug("press");
    scene2->addItem(store->saying);
    store->say=1;
}
void Game::handle4()
{
    if(wealth->getWealth()>399){
        backpack->add(1,1);
        wealth->increase(-399);
        store->saying->setPixmap(QPixmap(":/image/buydiamond3.jpg"));

    }
    else{
         store->saying->setPixmap(QPixmap(":/image/nomoney.jpg"));
    }
    qDebug("press");
    scene2->addItem(store->saying);
    store->say=1;

}

void Game::closeStore()
{
    scene2->removeItem(store);
    scene2->removeItem(store->counter);
    //changeScene();
    store->button1->setVisible(false);
    store->button2->setVisible(false);
    store->button3->setVisible(false);
    store->button4->setVisible(false);
    store->close->setVisible(false);
    changeScene(getLevel());

}






