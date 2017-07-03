#include "showdata.h"
#include "menu.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QFont>
#include <typeinfo>
extern Menu *menu;
ShowData::ShowData(QGraphicsItem *parent)
    :QGraphicsTextItem(parent)
{

    setPlainText(QString("Velocity"));
    setPlainText(QString("Aceleration"));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",20));
    setPos(x()+5,1000);
    //setPos(menu->rocketInterface->x(),menu->rocketInterface->y());
    QTimer *timer= new QTimer();
    //connect(timer,SIGNAL(timeout()),this,SLOT(moveData()));
    timer->start(60);

}

void ShowData::moveVelocity()
{
    setPos(menu->rocketInterface->x(),menu->rocketInterface->y()-50);
    setPlainText(QString("Velocity:"));

}

void ShowData::moveAceleration()
{
    setPos(menu->rocketInterface->x(),menu->rocketInterface->y()-70);
    setPlainText(QString("Aceleration:"));

}

void ShowData::movePresion()
{
    setPos(menu->rocketInterface->x(),menu->rocketInterface->y()-90);
    setPlainText(QString("Presion:"));

}

void ShowData::moveCoordinates()
{
    setPos(menu->rocketInterface->x(),menu->rocketInterface->y()-110);
    setPlainText(QString("(x")+QString(",y)"));

}

