#ifndef MONSTER_H
#define MONSTER_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>


class Monster: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Monster(QGraphicsItem * parent=0);
    void run();
    int getWound();
    int getX() ;
    int getY() ;
    void injure();
    void increase() ;

public slots:
    void attack();
private:
    int wound;

};
#endif // MONSTER_H
