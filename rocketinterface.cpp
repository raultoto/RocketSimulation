#include "rocketinterface.h"
#include "menu.h"
#include "rockettrajectory.h"
#include <QGraphicsScene>
#include <QTimer>
#include <typeinfo>
extern Menu *menu;
RocketInterface::RocketInterface()
{
    setPixmap(QPixmap(":/images/Images/Picture5.png"));

    setPos(1000,1000);
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(60);
}
void RocketInterface::move()
{
    RocketTrajectory *rocketTrayectory = new RocketTrajectory("*");
    scene()->addItem(rocketTrayectory);
    setPos(x()+5,y()-4);
    menu->showData->moveData();
}
