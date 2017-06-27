#include "earth.h"
template<typename T>
Earth<T>::Earth()
{

}

template<typename T>
T Earth<T> :: getdGravitybyheight(T heightb,T altitude)
{
    return gravity*pow(r_mediotierra/(r_mediotierra+altitude),2);
}

template<typename T>
T Earth<T>::getGravity()
{
return gravity;
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

