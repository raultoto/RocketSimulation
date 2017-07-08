#ifndef GRAPHDATA_H
#define GRAPHDATA_H
#include <QObject>
#include <QGraphicsPixmapItem>

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
