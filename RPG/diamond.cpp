#include "diamond.h"
#include <stdlib.h>

Diamond::Diamond(int type):type(type)
{
    if(type==1){
        setPixmap(QPixmap(":/image/diamond1.png"));
        int x=rand()%1000;
        int y=rand()%1000;
        setPos(x,y);
    }
    else if(type==2){
        setPixmap(QPixmap(":/image/diamond2.png"));
        int x=rand()%1000;
        int y=rand()%1000;
        setPos(x,y);
    }
    else{
        setPixmap(QPixmap(":/image/diamond.png"));
        setPos(850,540);
    }
}

int Diamond::Type()
{
    return type;
}
