#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H
//clase ambiente en la que estara el cohete aqui las presion del aire , viento etc
#include "earth.h"

template <typename T> class Rocket;
template <typename T>
class Environment
{
   friend class Rocket<T>;//the class rocket is fried->this class
public:
    Environment();
    Environment(T &,T&, T&,T&);

    T getAirDensity();
    T getLatitude();
    T getLenght();

    T Lm_pendiente();
    T getdensitybyLm(T gb, T tb,T heightb);
    T getpresionbyLm(T gb, T tb,T heightb);
    T getemperature(T heightb ,T h);

private:
    Earth<T>tierra;
    T pressureb ;
    T airDensity;// densidad del aire
    T latitude; // la latidus = como altitude geometrica
    T lenght; // longitud ;
    T altitude ; //altitud
    T temperatureb;
    T t;
    T R = 286.9;//constante de gases ideales
    float  e= 2.718281;
};


#endif // ENVIRONMENT_H
