#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <string>
using namespace std;
class Bullet: public QObject,public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Bullet(int d,string const &owner,float tan=1.0,bool sk=0,QGraphicsItem * parent=0);

public slots:
    void move();
private:
    int direction;
    int speed;
    double tan;
    string owner;
    bool skill;
};

#endif // BULLET_H
