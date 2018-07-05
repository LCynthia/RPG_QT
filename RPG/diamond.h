#ifndef DIAMOND_H
#define DIAMOND_H
#include<QGraphicsPixmapItem>
#include<QGraphicsItem>
#include <QObject>
class Diamond:public QGraphicsPixmapItem{
public:
    Diamond(int type);
    int Type();
private:
   int type;

};



#endif // DIAMOND_H
