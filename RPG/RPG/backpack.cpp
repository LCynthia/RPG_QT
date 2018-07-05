#include "backpack.h"
#include <string>
#include<QFont>
#include "game.h"
extern Game *game;
Backpack::Backpack(QGraphicsPixmapItem *paren)
{
    text=new  QGraphicsTextItem();
    setPixmap(QPixmap(":/image/back.png"));
    setPos(1700,0);
    diamond1=1;
    diamond2=2;
    diamond3=3;
    wealth=4;
    medicine=5;
    //setPlainText(QString("Health: ") + QString::number(health));
   // text=new QGraphicsTextItem();
   text->setPlainText(QString("X")+QString::number(diamond1)+QString("\tX")+QString::number(medicine)+QString("\nX")+
                 QString::number(diamond2)+QString("\nX")+QString::number(diamond3)+QString("\tX")+QString::number(wealth));
    text->setDefaultTextColor(Qt::yellow);
    text->setFont(QFont("times",16));
    text->setPos(1750,30);
}

void Backpack::add(int type,int i)
{
    switch(type){
    case 1 :    diamond1+=i; break;
    case 2 :    diamond2+=i; break;
    case 3 :    diamond3+=i; break;
    case 4 :    wealth+=i; break;
    case 5 :    medicine+=i;break;
    }
    text->setPlainText(QString("X")+QString::number(diamond1)+QString("\tX")+QString::number(medicine)+QString("\nX")+
                  QString::number(diamond2)+QString("\nX")+QString::number(diamond3)+QString("\tX")+QString::number(wealth));
    qDebug("%d",wealth);
}

void Backpack::Close()
{
     setPixmap(QPixmap(":/image/back.png"));
     scene()->removeItem(text);
}

void Backpack::Open()
{
    setPixmap(QPixmap(":/image/backpack.png"));
    scene()->addItem(text);

}

void Backpack::Initial()
{
    diamond1=1;
    diamond2=2;
    diamond3=3;
    wealth=4;
    medicine=5;
    text->setPlainText(QString("X")+QString::number(diamond1)+QString("\tX")+QString::number(medicine)+QString("\nX")+
                  QString::number(diamond2)+QString("\nX")+QString::number(diamond3)+QString("\tX")+QString::number(wealth));

}
