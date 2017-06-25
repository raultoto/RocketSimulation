#include "rocket.h"
template<typename T>
Rocket<T>::Rocket()
    :masa(0),altura(0)
{

}
template <typename T>
Rocket<T>::Rocket(T &m, T &a)
    :masa(m),altura(a)
{

}

