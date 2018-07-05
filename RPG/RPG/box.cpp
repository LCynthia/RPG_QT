#include "box.h"
#include <stdlib.h>

Box::Box(QGraphicsItem *parent)
{
        setPixmap(QPixmap(":/image/treasure.png"));
        int x=rand()%1000;
        int y=rand()%1000;
        setPos(x,y);
}
