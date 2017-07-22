#include "environment.h"

template<typename T>
Environment<T>::Environment()
{

}

template <typename T>
Environment<T>::Environment(T altitude_now )
{
    ///condiciones inciales
    tierra.set_var(altitude_now);
    this->hb=0;
    this->h=tierra.r_mediotierra/(tierra.r_mediotierra+altitude_now)*altitude_now;
    this->altitudenow=altitude_now;
    this->Lm=Lm_pendiente();//referido a los gradientes termicos

    getemperature();
    getspeedsound();
    getdensitybyLm();
}

//////esto muy principal
template<typename T>
T Environment<T>::dif_altitud( ){
    cout<<"gravedad"<< (tierra.getdGravitybyheight()/tierra.gravityb)*altitudenow;
    return (tierra.getdGravitybyheight()/tierra.gravityb )*altitudenow;
}
template<typename T>
T Environment<T>:: get_Altitudg()
{
    return h;
}

template<typename T>
void Environment<T>::setvar(T altitud2 )
{
    tierra.set_var(altitud2);
    this->h=(tierra.r_mediotierra/(tierra.r_mediotierra+altitud2))*altitud2;
    this->altitudenow=altitud2;
    this->Lm=Lm_pendiente();
    cout<<"Lm"<<Lm;
    tierra.set_var(altitud2);
    getemperature();
    getspeedsound();
    getdensitybyLm();
    cout<<"altitud"<<altitud2<<endl;
}


template<typename T>
T Environment<T>::getspeedsound()
{

     this->speedsound=pow(r*R*temperaturenow,0.5) ;
    return speedsound;
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
    return -1000;
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
   if(Lm != 0)
        return airDensityb*pow(temperatureb/temperaturenow,1+(tierra.gravityb/R*Lm)) ;
    if(Lm==0)
        return airDensityb*pow(1/e,tierra.gravityb*(h-hb)/R*temperatureb);
    return -1000;
}

template<typename T>
T Environment<T>::getpresionbyLm()
{
    if (Lm)
        return pressureb*pow(temperaturenow/temperatureb ,tierra.gravityb/(R*Lm));
    else
        return pressureb*pow(1/e,tierra.gravityb*(h-hb)/R*temperatureb );
    return -1000;
}

template <typename T>
T Environment<T>::getAirDensity()
{
    return airDensityb;
}



template <typename T>
T Environment<T>::getLenght()
{
    return lenghtb;
}
