#include "environment.h"

template<typename T>
Environment<T>::Environment()
{

}

template <typename T>
Environment<T>::Environment(T a,T pressureb1,T temperaturab1,T  hb1)
    :airDensity(a),pressureb(pressureb1),temperatureb(temperaturab1),hb(hb1)
{
    this->h=tierra.r_mediotierra/(tierra.r_mediotierra+altitudenow)*altitudenow;
    this->Lm=Lm_pendiente();
    getemperature();
    getspeedsound();
}

template<typename T>
void Environment<T>::getspeedsound()
{
     this->speedsound=pow(r*R*temperaturenow,0.5) ;
}

//segun la tabla de ARDC1959
template<typename T>
T Environment<T>::Lm_pendiente()
{
    if(altitudenow>=0 && altitudenow<11)
        return -6.5;
    if(altitudenow>=11 && altitudenow<20)
        return 0;
    if(altitudenow>=20 && altitudenow<32)
        return 1;
    if(altitudenow>=32 && altitudenow<47)
        return 2.8;
    if(altitudenow>=47 && altitudenow<51)
        return 0;
    if(altitudenow>=51 && altitudenow<71)
        return -2.8;
    if(altitudenow>=71 && altitudenow<86)
        return -2;
    if(altitudenow>=86 && altitudenow<91)
        return 0;
    if(altitudenow>=91 && altitudenow<1000)
        return 12;
}
//h=altitud geopontecial,altura repecto a la gravedad
template<typename T>
void Environment<T>:: getemperature()
{
    this->temperaturenow=temperatureb+Lm*(h-hb);
}

//densidad de cambios de temperaturas->densidad del aire
//lm no conosco ,gb=gravedad base,tb=temperatura base
template<typename T>
T Environment<T>::getdensitybyLm()
{
    //altura geopontecial,saca la altura respecto a la gravedad
    if(Lm)
        return airDensity*pow(temperatureb/temperaturenow,1+(tierra.gravityb/R*Lm));
    else
        return airDensity*pow(e,-tierra.gravityb*(h-hb)/R*temperatureb);
}

template<typename T>
T Environment<T>::getpresionbyLm()
{
    if (Lm)
        return pressureb*pow(temperatureb/temperaturenow,-tierra.gravityb/(R*Lm));
    else
        return pressureb*pow(e,-tierra.gravityb*(h-hb)/R*temperatureb );
}

template <typename T>
T Environment<T>::getAirDensity()
{
    return airDensity;
}

template <typename T>
T Environment<T>::getLatitude()
{
    return latitudeb;
}

template <typename T>
T Environment<T>::getLenght()
{
    return lenghtb;
}
