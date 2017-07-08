#ifndef MOVEMENTHEIGHT_H
#define MOVEMENTHEIGHT_H
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <rocketinterface.h>
class MovementHeight:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    MovementHeight();
public slots:
    void move();
};
#endif // MOVEMENTHEIGHT_H
