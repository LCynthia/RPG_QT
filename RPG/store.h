#ifndef STORE_H
#define STORE_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QPushButton>
#include <saying.h>
class Store:public QGraphicsPixmapItem{
public:
    Store(QGraphicsItem * parent=0);
    void change();
    QGraphicsPixmapItem *counter;
    QPushButton *button1;
    QPushButton *button2;
    QPushButton *button3;
    QPushButton *button4;
    QPushButton *close;
    Saying *saying;
    bool say;
    int sayTime;
};


#endif // STORE_H
