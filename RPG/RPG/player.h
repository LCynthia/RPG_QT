#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>

class Player:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);
    int getHurtAbility(){return hurt_ability;}
    void upHurtAbility(int i){hurt_ability+=i;}
    int getSkill();

    static int i1 ;
    static int i2 ;
    static int i3 ;
    int aa1 ;
    int aa2 ;
    static int i4 ;
    static bool judge_skil ;

    int getX(void) ;
    int getY(void) ;

public slots:
    void spawn();
private:
    QMediaPlayer * bulletsound;
    int hurt_ability ;
    int skill;
    int coolTime;
};

#endif // PLAYER_H
