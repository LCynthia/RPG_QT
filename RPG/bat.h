#ifndef BAT_H
#define BAT_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Bat: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Bat(QGraphicsItem * parent=0);
public slots:
    void move();
};

#endif // ENEMY_H

