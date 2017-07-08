#include "graphdata.h"
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsView>
GraphData::GraphData()
{
    //create a scene;
    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,800);
    QGraphicsRectItem *rect = new QGraphicsRectItem();
    QGraphicsRectItem *rect1= new QGraphicsRectItem();
    rect->setRect(0,400,800,0);
    rect1->setRect(400,0,0,800);
    scene->addItem(rect);
    scene->addItem(rect1);
    QGraphicsView *view = new QGraphicsView(scene);
    view->setFixedSize(350,700);
    view->show();
}

void GraphData::loadFiles()
{

}

void GraphData::readFiles()
{

}

void GraphData::graphHeightWithTime()
{

}

void GraphData::graphVelocityWithTime()
{

}
