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
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
    setPos(x()+5,1000);
    //setPos(menu->rocketInterface->x(),menu->rocketInterface->y());
    QTimer *timer= new QTimer();
    //connect(timer,SIGNAL(timeout()),this,SLOT(moveData()));
    timer->start(60);

}

void ShowData::moveData()
{
    setPos(menu->rocketInterface->x(),menu->rocketInterface->y());
    setPlainText(QString("Aceleration"));
}
