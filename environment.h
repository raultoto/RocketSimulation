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
    Environment(T altitude_now );

    T getAirDensity();
    T getLenght();
    T get_Altitudg();
    //T diferencial_altitud();
    T Lm_pendiente();
    T getdensitybyLm();
    T getpresionbyLm();
    T dif_altitud();
    void  getemperature();
    T getspeedsound() ;
    void setvar(T altitud);
private:
    ///////////inicializar variables
    T pressureb=14.5;
    T temperatureb=282;
    T airDensityb=28.2;// densidad del aire
    T altitudeb=12; //a#include<cmath>ltitud
    T lenghtb; // longitud ;
    Earth<T>tierra;
    T altitudenow;
    T temperaturenow;
    T speedsound;
    T h;//la latitud geopontencial
    T hb=1.5;
    T Lm;
    T t;
    T R = 286.9;//constante de gases ideales
    T r=1.4;//relacion de calores especificos debido proceso isoentropico
    double e=2.718281;
};


#endif // ENVIRONMENT_H
