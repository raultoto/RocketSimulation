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

//ecuacion (47)
template<typename T>
T Earth<T>::get_W(T masa_cohete,T distancia_r,T phi)
{
    cout<<"ecuacion"<<(1+pow(r_tierra_ecuador/distancia_r,2)* J2*(1-pow(3*sin(phi),2) ) );
    this->wr=(G*masa*masa_cohete)/pow(distancia_r,2)*(1+pow(r_tierra_ecuador/distancia_r,2)* J2*(1-pow(3*sin(phi),2) ) );
    this->wphi=(3*G*masa*masa_cohete/(pow(distancia_r,2)) )*
            ( pow(r_tierra_ecuador/distancia_r,2) )*
            J2*(sin(phi)*cos(phi))  ;
    T W = wr+wphi;
    cout<<"probando"<<endl;
    cout<<this->wr<<endl;
    cout<<this->wphi<<endl;
    return W;
}

template<typename T>
T Earth<T>::get_radiovector()
{
    this->radio_vector=r_mediotierra+altitude;
    return radio_vector;
}

/////////////ecuacion(7)Incremento de la gravedad
///multiplico por la pow(10,20) para igualar mi  reduccion
template<typename T>
T Earth<T> :: getdGravitybyheight()
{
    this->gravitynow=gravityb*pow( (r_mediotierra*pow(10,20))/(r_mediotierra*pow(10,20)+altitude),2);
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
