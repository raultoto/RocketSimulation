#include "environment.h"

template<typename T>
Environment<T>::Environment()
    :airDensity(0),latitude(0),lenght(0)
{

}

template <typename T>
Environment<T>::Environment(T &a, T &l, T &ll,T&pressureb1)
    :airDensity(a),latitude(l),lenght(ll),pressureb(pressureb1)
{

}
template<typename T>
T Environment<T>::Lm_pendiente()
{
    if(altitude>=0 && altitude<11)
        return -6.5;
    if(altitude>=11 && altitude<20)
        return 0;
    if(altitude>=20 && altitude<32)
        return 1;
    if(altitude>=32 && altitude<47)
        return 2.8;
    if(altitude>=47 && altitude<51)
        return 0;
    if(altitude>=51 && altitude<71)
        return -2.8;
    if(altitude>=71 && altitude<86)
        return -2;
    if(altitude>=86 && altitude<91)
        return 0;
    if(altitude>=91 && altitude<1000)
        return 12;
}
//h=altitud geopontecial,altura repecto a la gravedad
template<typename T>
T Environment<T>:: getemperature(T heightb,T h)
{
    this->t=temperatureb+Lm_pendiente()*(h-heightb);
    return t;
}

//densidad de cambios de temperaturas->densidad del aire
//lm no conosco ,gb=gravedad base,tb=temperatura base
template<typename T>
T Environment<T>::getdensitybyLm(T gb, T tb,T heightb )
{
    //altura geopontecial,saca la altura respecto a la gravedad
    T h=tierra.r_mediotierra/(tierra.r_mediotierra+altitude)*altitude;
    T Lm=getemperature(heightb);
    if(Lm)
        return airDensity*pow(tb/getemperature(heightb),1+(gb/R*Lm));
    else
        return airDensity*pow(e,-gb(h-heightb)/R*tb);
}

template<typename T>
T Environment<T>::getpresionbyLm(T gb, T tb,T heightb)
{
    T Lm=getemperature(heightb);
    if (Lm)
        return pressureb*pow(tb/Lm,-gb/(R*Lm));
}

template <typename T>
T Environment<T>::getAirDensity()
{
    return airDensity;
}

template <typename T>
T Environment<T>::getLatitude()
{
    return latitude;
}

template <typename T>
T Environment<T>::getLenght()
{
    return lenght;
}

