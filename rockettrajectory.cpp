#include "rockettrajectory.h"
#include "menu.h"
#include <QGraphicsScene>
extern Menu *menu;
RocketTrajectory::RocketTrajectory(QString name,int x,QGraphicsItem *parent)
    :QGraphicsTextItem(parent)
{
    setPlainText(QString(name));
    if(x==1)
        setDefaultTextColor(Qt::red);
    else if(x==2)
        setDefaultTextColor(Qt::blue);
    else if(x==3)
        setDefaultTextColor(Qt::green);
    else
        setDefaultTextColor(Qt::black);

    setFont(QFont("times",10));
    setPos(menu->rocketInterface->x()-5,menu->rocketInterface->y()+8);
}
