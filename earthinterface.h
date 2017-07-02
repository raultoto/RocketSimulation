#ifndef EARTHINTERFACE_H
#define EARTHINTERFACE_H


//qt includes
#include <QGraphicsPixmapItem>
#include <QObject>
//template<typename T>
class EarthInterface:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    EarthInterface();
public slots:
    //void move();
};

#endif // EARTHINTERFACE_H
