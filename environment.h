#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H
//clase ambiente en la que estara el cohete aqui las presion del aire , viento etc
#include "earth.h"
#define e 2.718281

#include<cmath>
template <typename T> class Rocket;
template <typename T>
class Environment
{
   friend class Rocket<T>;//the class rocket is fried->this class
public:
    //Environment();
    Environment(T densidadaireb,T presiobase,T temperatureb1,T altitud);

    T getAirDensity();
    T getLatitude();
    T getLenght();

    T Lm_pendiente();
    T getdensitybyLm();
    T getpresionbyLm();
    void  getemperature();
    void getspeedsound() ;
private:
    T pressureb ;
    T airDensity;// densidad del aire
    T latitudeb; // la latidus = como altitude geometrica
    T lenghtb; // longitud ;
    T altitudeb; //a#include<cmath>ltitud
    T altitudenow;//altitud geometrica
    Earth<T>tierra;
    T temperatureb;
    T temperaturenow;
    T speedsound;
    T h;//la latitud geopontencial
    T hb;
    T Lm;
    T t;
    T R = 286.9;//constante de gases ideales
    T r=1.4;//relacion de calores especificos debido proceso isoentropico
};


#endif // ENVIRONMENT_H
