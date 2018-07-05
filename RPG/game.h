#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "player.h"
#include "score.h"
#include "health.h"
#include"diamond.h"
#include"backpack.h"
#include "wealth.h"
#include "monster.h"
#include "backpack.h"
#include <QPushButton>
#include <QObject>
#include"npc.h"
#include"saying.h"
#include "store.h"
#include"skill.h"
class Game: public QGraphicsView{
    Q_OBJECT
public:
    Game(QWidget * parent=0);

    QGraphicsScene * scene;//start
    QGraphicsScene * scene1;
    QGraphicsScene * scene2;
    QGraphicsScene * scene3;
    QGraphicsScene * scene4;
    QGraphicsScene * scene5;//end
    Backpack *backpack;
    Player * player;
    Monster * monster;
    Score * score;
    Health * health;
    Wealth * wealth;
    Store *store;


    Skill * skill1 ;
    Skill * skill2 ;

    Saying * saying1 ;
    Saying * saying2 ;
    Saying * saying3;
 /*
    Saying * skill_2 ;
    Saying * skill_3 ;
    Saying * skill_1 ;*/

    int upLevel();
    int getLevel();
    bool getSurprise();
    void changeSurprise();
    void changeScene(int i);
    bool IsMonster();
    void changeIsMonster();
    bool Gameover(){return gameover;}
    void reStart();
public slots:
    void handleButton();
    void handle1();
    void handle2();
    void handle3();
    void handle4();
    void closeStore();

private:
    int level;
    bool surprise;
    bool isMonster;
    bool gameover;
    QPushButton *button;
    int plot;
};

#endif // GAME_H
