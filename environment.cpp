#include "environment.h"
template<typename T>
Environment<T>::Environment()
    :airDensity(0),latitude(0),lenght(0)
{

}

template <typename T>
Environment<T>::Environment(T &a, T &l, T &ll)
    :airDensity(a),latitude(l),lenght(ll)
{

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
