#ifndef EARTH_H
#define EARTH_H
#include <istream>
#include<cmath>
using namespace std;
template<typename T>
class Earth
{
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
