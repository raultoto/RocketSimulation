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

    T getAirDensity();
    T getLatitude();
    T getLenght();

private:
    T airDensity;// densidad del aire
    T latitude; // la latidus
    T lenght; // longitud ;
};


#endif // ENVIRONMENT_H
