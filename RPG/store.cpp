#include "store.h"
#include "game.h"
#include <QObject>
#include <QFont>
#include <QDebug>
extern Game *game;
Store::Store(QGraphicsItem *parent)
{
    setPixmap(QPixmap(":/image/store.png"));
    counter=new QGraphicsPixmapItem();
    counter->setPixmap(QPixmap(":/image/instore.png"));
    counter->setPos(500,400);
    button1=new QPushButton();
    button1->setGeometry(QRect(QPoint(700,720),QSize(40,25)));
  //  button1->setFont(QFont("times",16));
    button1->setText("buy4");
    button1->setStyleSheet("background:yellow");
    button1->setParent(game);


   /* button=new QPushButton();
    button->setGeometry(QRect(QPoint(1000, 800), QSize(80, 50)));
    button->setText("start");
    button->setStyleSheet("background:yellow");
    //button->setIcon(QIcon("/:button.jpg"));
    button->setParent(this);
    QObject::connect(button, SIGNAL(released()), this, SLOT(handleButton()));
    //startButton->show();
    scene->addWidget(button);*/

    button2=new QPushButton();
    button2->setGeometry(QRect(QPoint(700, 500), QSize(40, 25)));
    button2->setText("buy1");
    button2->setStyleSheet("background:yellow");
    button2->setParent(game);

    button3=new QPushButton();
    button3->setGeometry(QRect(QPoint(900, 500), QSize(40, 25)));
    button3->setText("buy2");
    button3->setStyleSheet("background:yellow");
    button3->setParent(game);

    button4=new QPushButton();
    button4->setGeometry(QRect(QPoint(1100, 500), QSize(40, 25)));
    button4->setText("buy3");
    button4->setStyleSheet("background:yellow");
    button4->setParent(game);

    close=new QPushButton();
    close->setGeometry(QRect(QPoint(1240, 460), QSize(40, 40)));
    close->setText("X");
    close->setStyleSheet("background:yellow");
    close->setParent(game);

   /* text1=new QGraphicsTextItem();
    text1->setPlainText(QString("sorry,money is not enough "));
    text1->setDefaultTextColor(Qt::red);
    text1->setFont(QFont("times",16));
    text1->setPos(200,100);

    text2=new QGraphicsTextItem();
    text2->setPlainText(QString("you've bought"));
    text2->setDefaultTextColor(Qt::red);
    text2->setFont(QFont("times",16));
    text2->setPos(200,100);*/

    saying=new Saying();
    say=0;
    saying->setPos(200,100);
    sayTime=0;

}

void Store::change()
{
    scene()->addItem(counter);
    scene()->addWidget(button1);
    scene()->addWidget(button2);
    scene()->addWidget(button3);
    scene()->addWidget(button4);
    scene()->addWidget(close);
}


