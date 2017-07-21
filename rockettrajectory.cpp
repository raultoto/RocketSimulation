#include "rockettrajectory.h"
#include "menu.h"
#include <QGraphicsScene>
extern Menu *menu;
RocketTrajectory::RocketTrajectory(QString name,QGraphicsItem *parent)
    :QGraphicsTextItem(parent)
{
    setPlainText(QString(name));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",10));
    setPos(menu->rocketInterface->x()-5,menu->rocketInterface->y()+8);
}
