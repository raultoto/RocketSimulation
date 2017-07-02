#ifndef EARTH_H
#define EARTH_H
#include <istream>
#include <cmath>
//qt includes
#include <QObject>
#include <QGraphicsPixmapItem>
template <typename T> class Environment;

template<typename T>
class Earth
{
public:
    friend class Environment<T>;
    Earth();
    Earth(T & altitude);
    T getdGravitybyheight(T altitude);
    T getGravity();
    T getRadio();
    T getMasa();
    T getHeight();
private:
    T gravityb =9.8;
    T gravitynow;
    T radio;
    T masa = 5972*pow(10,24);//masa en kilogramos
    T height ;
    double r_mediotierra=6378.14;
};

#endif // EARTH_H
