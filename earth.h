#ifndef EARTH_H
#define EARTH_H
#include <istream>
#include <cmath>
//qt includes
#include <QObject>
#include <QGraphicsPixmapItem>
template <typename T> class Environment;
template <typename T> class Rocket;

#include<iostream>
using namespace std;
template<typename T>
T funcion_bessel(T x)
{
    cout<<"bessel"<<x;
    T j2= (3/x*x-1)*sin(x)/x - 3*cos(x)/x*x;
    cout<<"bessel"<<x;
    return j2;
}

template<typename T>
class Earth
{
public:
    friend class Environment<T>;
    friend class Rocket<T>;
    Earth();
    void set_var (T & altitude);
    void set_altitude();
    T getdGravitybyheight();
    T getGravity();
    T getRadio();
    T getMasa();
    T getHeight();
    T get_radiovector();
   // void set_altitude(T altitude1);
    T get_W(T masa_cohete,T velocidad_ascenso,T phi);//W fuerza de atraccion gravitacional
    T get_wr();
    T get_wphi();
     T radio_vector;// distancia entre la tierra y el cohete
private:

    T altitude ;
    T gravityb =9.8;
    T gravitynow;
    T radio;
    T height ;
    T r_tierra_ecuador=6378136.6/pow(10,20) ;// esto es en metros
    /////reducir los datos de la tierra
    T masa = 5972*pow(10,24)/pow(10,20);//masa en kilogramos
    T G=6.13*pow(1/10,11)/pow(10,20);//esto esta en Nm^2/kg^2
    T wr;//Fuerza de atraccion gravitacional con respecto a r
    T wphi;
    T J2=0.00108263;
    double r_mediotierra=6378.14/pow(10,20);
};

#endif // EARTH_H
