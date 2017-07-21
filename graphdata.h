#ifndef GRAPHDATA_H
#define GRAPHDATA_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include "rockettrajectory.h"
#include <fstream>
#include <iostream>
using namespace std;
class GraphData:public QObject
{
    Q_OBJECT
public:
    GraphData();
    void loadFiles();
    void readFiles();
    QGraphicsScene *scene1;
    void graphHeightWithTime();
public slots:
    void graphVelocityWithTime();
};

#endif // GRAPHDATA_H
