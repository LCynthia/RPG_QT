#include "score.h"
#include <QFont>
#include "game.h"
extern Game *game;
Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the score to 0
    score = 49;

    // draw the text
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 0
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

void Score::increase(int i){
    score+=i;
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 1
}

int Score::getScore(){
    return score;
}

void Score::Initial()
{
    score=49;
    setPlainText(QString("Score: ") + QString::number(score));
}
