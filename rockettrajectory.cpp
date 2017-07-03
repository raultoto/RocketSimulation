#include "rockettrajectory.h"
#include "menu.h"
#include <QGraphicsScene>
extern Menu *menu;
RocketTrajectory::RocketTrajectory(QGraphicsItem *parent)
    :QGraphicsTextItem(parent)
{
    setPlainText(QString("*"));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",8));
    setPos(menu->rocketInterface->x()-5,menu->rocketInterface->y());
}
