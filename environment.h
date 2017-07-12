#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H
//clase ambiente en la que estara el cohete aqui las presion del aire , viento etc
#include "earth.h"


#include<cmath>
template <typename T> class Rocket;
template <typename T>
class Environment
{
   friend class Rocket<T>;//the class rocket is fried->this class
public:
    Environment();
    Environment(T densidadaireb,T presiobase,T temperatureb1,T altitud);

    T getAirDensity();
    T getLatitude();
    T getLenght();

    //T diferencial_altitud();
    T Lm_pendiente();
    T getdensitybyLm();
    T getpresionbyLm();
    T dif_altitud();
    void  getemperature();
    void getspeedsound() ;
    void setvar(T altitud);
private:
    T pressureb=212;
    T temperatureb=180;
    T airDensity=1212;// densidad del aire
    T altitudeb; //a#include<cmath>ltitud

    T latitudeb; // la latidus = como altitude geometrica
    T lenghtb; // longitud ;
    T altitudenow;//altitud geometrica
    Earth<T>tierra;
    T temperaturenow;
    T speedsound;
    T h;//la latitud geopontencial
    T hb;
    T Lm;
    T t;
    T R = 286.9;//constante de gases ideales
    T r=1.4;//relacion de calores especificos debido proceso isoentropico
    double e=2.718281;
};


#endif // ENVIRONMENT_H
