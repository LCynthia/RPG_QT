#ifndef SAYING_H
#define SAYING_H

#include<QGraphicsPixmapItem>
#include<QGraphicsItem>
class Saying : public QGraphicsPixmapItem{
public:
    Saying(QGraphicsItem * parent = 0) ;
    int sayTime;
    bool say;
};


#endif // SAYING_H
