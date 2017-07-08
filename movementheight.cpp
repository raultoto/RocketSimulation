#include "movementheight.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QImage>
MovementHeight::MovementHeight()
{
    //setPixmap(QPixmap(":/images/Images/earth1.jpg"));
    //setPos(1800,0);
    QGraphicsScene * scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1600,1000);
    QGraphicsView *view = new QGraphicsView(scene);
    view->setBackgroundBrush(QBrush(QImage(":/images/Images/earth1.jpg")));
    view->setFixedSize(350,700);
    view->show();

    //view->setPos(1500,500);

    //QTimer *timer =  new QTimer();
    //connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    //timer->start(60);
}
void MovementHeight::move()
{

}
