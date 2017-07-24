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
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;
class GraphData:public QGraphicsView
{
    Q_OBJECT
public:
    GraphData(QWidget *parent=0);

    void readFiles(string);//lee un archivo
    double stringToInt(string);
    void convertStringToNumber(string);
    //public functions
    //public objects
    QGraphicsScene *scene1;
private:
    vector<double>vec1;
    vector<double>vec2;
public slots:
    void graphHeightWithTime();//altura con el tiempo
    void graphVelocityWithTime();//velocidad conntra el tiempo
    void velocityWithPressure();//velocidad con presion

};

#endif // GRAPHDATA_H
