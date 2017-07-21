#include "graphdata.h"
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsView>
GraphData::GraphData(QWidget *parent)
{
    //create a scene;
    scene1 = new QGraphicsScene();
    scene1->setSceneRect(0,0,800,800);
    QGraphicsRectItem *rect = new QGraphicsRectItem();
    QGraphicsRectItem *rect1= new QGraphicsRectItem();
    QWidget *wi= new QWidget();
    rect->setRect(0,400,800,0);
    rect1->setRect(400,0,0,800);
    scene1->addItem(rect);
    scene1->addItem(rect1);

    //creacion de cordenadas
    int cont=0;
    while(cont<1300)
    {
        //vertical
        RocketTrajectory *trajectory3 = new RocketTrajectory("__");
        scene1->addItem(trajectory3);
        trajectory3->setPos(390,1200-cont);
        //horizontal
        RocketTrajectory *trajectory = new RocketTrajectory("|");
        scene1->addItem(trajectory);
        trajectory->setPos(800-cont,386);
        cont=cont+5;


    }
    QGraphicsView *view = new QGraphicsView(scene1);
    view->setFixedSize(350,700);

    Button* graphButtom = new Button(QString("Time-Height"),120,30);
    graphButtom->setPos(250,50);
    connect(graphButtom,SIGNAL(clicked()),this,SLOT(graphHeightWithTime()));
    scene1->addItem(graphButtom);

    Button* graphButtom1 = new Button(QString("Velocity-Time"),120,30);
    graphButtom1->setPos(250,80);
    connect(graphButtom1,SIGNAL(clicked()),this,SLOT(graphVelocityWithTime()));
    scene1->addItem(graphButtom1);


    Button* graphButtom2 = new Button(QString("Velocity-Pressure"),120,30);
    graphButtom2->setPos(250,110);
    connect(graphButtom2,SIGNAL(clicked()),this,SLOT(velocityWithPressure()));
    scene1->addItem(graphButtom2);




    view->show();

    //graphHeightWithTime();


}

void GraphData::readFiles()
{

}

void GraphData::graphHeightWithTime()
{
    int cont=0;
    while (cont<100) {
        RocketTrajectory *trajectory3 = new RocketTrajectory("*");
        scene1->addItem(trajectory3);
        trajectory3->setPos(400+cont,400-cont);
        cont++;
    }
}

void GraphData::graphVelocityWithTime()
{
    int cont=0;
    while (cont<100) {
        RocketTrajectory *trajectory3 = new RocketTrajectory("*");
        scene1->addItem(trajectory3);
        trajectory3->setPos(400+cont,400+cont);
        cont++;
    }

}

void GraphData::velocityWithPressure()
{
    int cont=0;
    while (cont<100) {
        RocketTrajectory *trajectory3 = new RocketTrajectory("*");
        scene1->addItem(trajectory3);
        trajectory3->setPos(400,400-cont);
        cont++;
    }

}
