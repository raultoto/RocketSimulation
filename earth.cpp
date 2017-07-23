#include "earth.h"
template<typename T>
Earth<T>::Earth()
{

}

template<class T>
void Earth<T>::set_var (T & altitude)
{
    this->altitude=altitude;
    getdGravitybyheight();
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
    cout<<"velocidad de ascenso"<<velocidad_ascenso<<endl;
    cout<<"ecuacion"<<(1-pow(3*sin(phi),2) );
    this->wr=(G*masa*masa_cohete)/pow(velocidad_ascenso,2)*(1+pow(r_tierra_ecuador/velocidad_ascenso,2)* J2*(1-pow(3*sin(phi),2) ) );
    this->wphi=(3*G*masa*masa_cohete/(pow(velocidad_ascenso,2)) )*
            ( pow(r_tierra_ecuador/velocidad_ascenso,2) )*
            J2*(sin(phi)*cos(phi))  ;
    T W = wr+wphi;
    /*^qDebug()<<"probando";
    qDebug()<<wr;
    qDebug()<<wphi;*/
    return W;
}

template<typename T>
T Earth<T>::get_radiovector()
{
    this->radio_vector=r_mediotierra+altitude;
    return radio_vector;
}

/////////////ecuacion(7)Incremento de la gravedad
template<typename T>
T Earth<T> :: getdGravitybyheight()
{
    this->gravitynow=gravityb*pow(r_mediotierra/(r_mediotierra+altitude),2);
    return gravitynow;
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

template<typename T>
T Earth<T>::get_wr()
{
return wr;
}

template<typename T>
T Earth<T>::get_wphi()
{
    return wphi;
}
