#ifndef GRAPHDATA_H
#define GRAPHDATA_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include "rockettrajectory.h"
#include "button.h"
//---
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsWidget>
#include <QGraphicsTextItem>
#include <fstream>
#include <iostream>
using namespace std;
class GraphData:public QGraphicsView
{
    Q_OBJECT
public:
    GraphData(QWidget *parent=0);

    void readFiles();//lee un archivo
    //public functions
    //public objects
    QGraphicsScene *scene1;
public slots:
    void graphHeightWithTime();//altura con el tiempo
    void graphVelocityWithTime();//velocidad conntra el tiempo
    void velocityWithPressure();//velocidad con presion

};

#endif // GRAPHDATA_H
