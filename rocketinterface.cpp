#include "rocketinterface.h"
#include "menu.h"
#include <QGraphicsScene>
#include <QTimer>
#include <typeinfo>
extern Menu *menu;
RocketInterface::RocketInterface()
{
    setPixmap(QPixmap(":/images/Picture5.png"));

    setPos(1000,1000);
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(60);
}
void RocketInterface::move()
{
    setPos(x()+5,y());
    menu->showData->moveAceleration();
    menu->showData->moveVelocity();
    menu->showData->movePresion();
    menu->showData->moveCoordinates();

}
