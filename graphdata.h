#ifndef GRAPHDATA_H
#define GRAPHDATA_H
#include <QObject>
#include <QGraphicsPixmapItem>
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
public slots:
    void graphHeightWithTime();
    void graphVelocityWithTime();
};

#endif // GRAPHDATA_H
