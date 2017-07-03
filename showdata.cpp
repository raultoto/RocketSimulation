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
    setDefaultTextColor(Qt::green);
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
    setPlainText(QString("(x\n")+QString(",y)"));

}

void ShowData::moveData()
{
    setPos(menu->rocketInterface->x(),menu->rocketInterface->y()-200);
    setPlainText(QString("Presion:\n")+QString("Velocity:\n")+QString("Aceleration:\n")+QString("(")+QString::number(menu->rocketInterface->x())+QString(",")+QString::number(menu->rocketInterface->y())+QString(")"));

}

