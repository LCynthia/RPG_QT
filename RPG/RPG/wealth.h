#ifndef WEALTH
#define WEALTH



#include <QGraphicsTextItem>

class Wealth: public QGraphicsTextItem{
public:
    Wealth(QGraphicsItem * parent=0);
    void increase();
    void increase(int i);
    int getWealth();
    void Initial();
private:
    int wealth;
};
#endif // WEALTH_H
