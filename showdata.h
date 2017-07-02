#ifndef SHOWDATA_H
#define SHOWDATA_H
//qt includes
#include <QGraphicsTextItem>
#include <QGraphicsScene>
class ShowData:public QGraphicsTextItem
{
public:
    ShowData(QGraphicsItem *parent=0);
    void moveData();
};

#endif // SHOWDATA_H
