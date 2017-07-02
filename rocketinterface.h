#ifndef ROCKETINTERFACE_H
#define ROCKETINTERFACE_H

#include <QGraphicsPixmapItem>
#include <QObject>
class RocketInterface:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    RocketInterface();
public slots:
    void move();
};


#endif // ROCKETINTERFACE_H
