#ifndef EARTH_H
#define EARTH_H
//qt includes
#include <QObject>
#include <QGraphicsPixmapItem>
//----
#include <iostream>
#include<cmath>
using namespace std;
template<typename T>
class Earth:public QObject,public QGraphicsPixmapItem
{
    //Q_OBJECT
public:
    Earth();
    T getdGravitybyheight(T heightb,T altitude);
    T getGravity();
    T getRadio();
    T getMasa();
    T getHeight();
private:
    T gravity=9.8;
    T radio;
    T masa = 5972*pow(10,24);//masa en kilogramos
    T height ;
    T r_mediotierra=6378.14;
};

#endif // EARTH_H
