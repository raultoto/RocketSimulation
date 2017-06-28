#include "earth.h"
template<typename T>
Earth<T>::Earth()
{

}

template<typename T>
Earth<T>::Earth(T & altitude)
{
getdGravitybyheight(altitude);
}

template<typename T>
T Earth<T> :: getdGravitybyheight(T altitude)
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

