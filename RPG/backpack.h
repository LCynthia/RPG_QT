#ifndef BACKPACK_H
#define BACKPACK_H
#include<QGraphicsPixmapItem>
#include<QGraphicsItem>
#include <QGraphicsTextItem>
#include <string>
class Backpack: public QGraphicsPixmapItem{
public:
    Backpack(QGraphicsPixmapItem *parent=0) ;
    void add(int type,int i);
    QGraphicsTextItem *text;
    void Close();
    void Initial();
    void Open();
private:
    int diamond1;
    int diamond2;
    int diamond3;
    int wealth;
    int medicine;
};


#endif // BACKPACK_H
