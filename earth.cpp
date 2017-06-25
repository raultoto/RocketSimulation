#include "earth.h"
template<typename T>
Earth<T>::Earth()
    :gravity(9.8)
{

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

