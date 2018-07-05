#include "wealth.h"
#include <QFont>

Wealth::Wealth(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the score to 0
    wealth = 1000;

    // draw the text
    setPlainText(QString("Wealth: ") + QString::number(50*wealth));
    setDefaultTextColor(Qt::yellow);
    setFont(QFont("times",16));
}

void Wealth::increase(){
    wealth++;
    setPlainText(QString("Wealth: ") + QString::number(50*wealth));
}

void Wealth::increase(int i)
{
    wealth+=i;
    setPlainText(QString("Wealth: ") + QString::number(50*wealth));
}

int Wealth::getWealth(){
    return wealth;
}

void Wealth::Initial()
{
    wealth=0;

    setPlainText(QString("Wealth: ") + QString::number(50*wealth));
}
