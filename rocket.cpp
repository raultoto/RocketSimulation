#include "rocket.h"
template<typename T>
Rocket<T>::Rocket()
    :dough(0),height(0)
{

}
template <typename T>

Rocket<T>::Rocket(T &m, T &a,T &diameter1,T &areatobera1,T & tip_length1)
    :dough(m),height(a),area_nozzle(areatobera1),diameter(diameter1),tip_length(tip_length1)
{
    v =0;
    A=diameter*diameter/4 * PI;
    q=1/2*v*v*fuerza.airDensity;
    T divide =tip_length/diameter;
    T cf=0.53*(divide)*pow(dough/ q *tip_length,0.2);//coeficiente de friccion por la forma del cuerpo
    T co=(1586+1834/pow(dough,2))*pow(1/(tan(0.5/divide)) ,1.69);
    T cb=0.12+0.13*pow(dough,2);
    if(mach(v))
        Cd=cf+co+cb;
    else
        Cd=cf+cb;
}


template<class T>
T Rocket<T>::drag()
{
    return 1/2*fuerza.airDensity*pow(v,2)*A*Cd;
}

template<class T>
T Rocket<T>::lift()
{

}

template<class T>
T Rocket<T>::getdough()
{
    return this->dough;
}

template<class T>
T Rocket<T>:: getheight()
{
    return this->height;
}

template<class T>
T Rocket<T>:: getareaall()
{
    return this->area_all;
}

template<class T>
T Rocket<T>:: getarea_nozzle()
{
    return this->area_nozzle;
}

