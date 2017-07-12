#ifndef EARTH_H
#define EARTH_H
#include <istream>
#include <cmath>
//qt includes
#include <QObject>
#include <QGraphicsPixmapItem>
template <typename T> class Environment;
template <typename T> class Rocket;

template<typename T>
T funcion_bessel(T x)
{
    T j2= (3/x*x-1)*sin(x)/x - 3*cos(x)/x*x;
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
    //void get_wr();
    //void get_wr();
     T radio_vector;// distancia entre la tierra y el cohete
private:

    T altitude ;
    T gravityb =9.8;
    T gravitynow;
    T radio;
    T masa = 5972*pow(10,24);//masa en kilogramos
    T height ;
    T r_tierra_ecuador=6378136.6 ;// esto es en metros
    T G=6.13*pow(10,-11);//esto esta en Nm^2/kg^2
    T Wr;//Fuerza de atraccion gravitacional con respecto a r
    T Wphi;
    T J2=0.00108263;
    double r_mediotierra=6378.14;
};

#endif // EARTH_H
