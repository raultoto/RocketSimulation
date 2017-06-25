#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H
//clase ambiente en la que estara el cohete aqui las presion del aire , viento etc
#include "rocket.h"
template <typename T> class Rocket;
template <typename T>
class Environment
{
    friend class Rocket<T>;//the class rocket is fried->this class
public:
    Environment();
    Environment(T &,T&, T&);
    T get_Cl();
    T get_Cd();
private:
    T airDensity;// densidad del aire
    T latitude; // la latidus
    T lenght; // longitud ;
};

template<typename T>
T Environment<T>::get_Cl()
{
    return this->Cl;
}

template<typename T>
T Environment<T>:: get_Cd()
{
    return this->Cd;
}

#endif // ENVIRONMENT_H
