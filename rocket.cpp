#include "rocket.h"
template<typename T>
Rocket<T>::Rocket()
    :dough(0),height(0)
{

}
template <typename T>
Rocket<T>::Rocket(T &m, T &a)
    :dough(m),height(a)
{

}

