#include "graphdata.h"
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsView>
GraphData::GraphData()
{
    //create a scene;
    scene1 = new QGraphicsScene();
    scene1->setSceneRect(0,0,800,800);
    QGraphicsRectItem *rect = new QGraphicsRectItem();
    QGraphicsRectItem *rect1= new QGraphicsRectItem();
    rect->setRect(0,400,800,0);
    rect1->setRect(400,0,0,800);
    scene1->addItem(rect);
    scene1->addItem(rect1);
    QGraphicsView *view = new QGraphicsView(scene1);
    view->setFixedSize(350,700);
    view->show();
    /*Button* quitButton = new Button(QString("Quit"));
    quitButton->setPos(400,400);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    scene1->addItem(quitButton);
    //Button* graphButtom = new Button(QString("Graph"));
    //graphButtom->setPos(400,450);
    //connect(graphButtom,SIGNAL(clicked()),this,SLOT(callGraphData()));
    //scene->addItem(graphButtom);*/

}

void GraphData::loadFiles()
{

}

void GraphData::readFiles()
{

}

void GraphData::graphHeightWithTime()
{
    int cont=0;
    while (cont<100) {
        RocketTrajectory *trajectory3 = new RocketTrajectory();
        scene1->addItem(trajectory3);
        trajectory3->setPos(400+cont,400-cont);
        cont++;
    }
}

void GraphData::graphVelocityWithTime()
{

}
