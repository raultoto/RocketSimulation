#include "earth.h"
template<typename T>
Earth<T>::Earth()
{

}


template<typename T>
Earth<T>::Earth(T & altitude)
{
    getdGravitybyheight(altitude);
    this->altitude=altitude;
}
/*
 * Esta j2 es para coordenadas esfericas
d*/
template<typename T>
T funcionbessel(T x)
{
    T j2=(3/x*x -1)*sin(x)/x-3*cos(x)/x*x;
    return j2;
}

template<typename T>
T Earth<T>::get_W(T masa_cohete,T velocidad_ascenso,T phi)
{
    this->Wr=(G*masa*masa_cohete)/pow(velocidad_ascenso,2)*(1+pow(r_tierra_ecuador/velocidad_ascenso,2)* funcion_bessel(1-pow(3*sin(phi),2) ) );
    this->Wphi=3*G*masa*masa_cohete/pow(velocidad_ascenso,2)*pow(r_tierra_ecuador/velocidad_ascenso,2)*
            J2*(sin(phi)*cos(phi))  ;
    T W = Wr+Wphi;
    qDebug()<<"probando";
    qDebug()<<Wr;
    qDebug()<<Wphi;
    return W;
}

template<typename T>
T Earth<T>::get_radiovector()
{
    this->radio_vector=r_mediotierra+altitude;
    return radio_vector;
}
template<typename T>
void Earth<T>::set_altitude(T altitude1)
{
    this->altitude=altitude1;
}
/*template<typename T>
Earth<T>::get_wr(){
    T G=6.67*pow(10,11);//constante de cavendish
}*/



template<typename T>
T Earth<T> :: getdGravitybyheight()
{
    this->gravitynow=gravityb*pow(r_mediotierra/(r_mediotierra+altitude),2);
}

template<typename T>
T Earth<T>::getGravity()
{
return gravitynow;
}

template<typename T>
T Earth<T>::getRadio()
{
return radio;
}
template<typename T>
T Earth<T>::getMasa()
{
return masa;
}

template<typename T>
T Earth<T>::getHeight()
{
return height;
}

