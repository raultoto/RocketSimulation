#include "rocket.h"

template<typename T>
Rocket<T>::Rocket()
{

}

template <typename T>
Rocket<T>::Rocket(T &m, T &a,T &diameter1,T &areatobera1,T & tip_length1)
    :dough(m),height(a),area_nozzle(areatobera1),diameter(diameter1),tip_length(tip_length1)
{
    //radio_vector=Re+altitude
    T vay=(-v*sin(theta)*cos(azimut))/radio_vector ;
    T vaz=(v*sin(theta)*sin(azimut))/radio_vector ;
    //velocidadangu.setY(vay);
    //velocidadangu.setZ(vaz);

    A=diameter*diameter/4 * PI;
    anguloataque=acos(v/push());
    q=1/2*v*v*ambiente.airDensity;
    T divide =tip_length/diameter;
    T cf=0.53*(divide)*pow(dough/ q *tip_length,0.2);//coeficiente de friccion por la forma del cuerpo
    T co=(1586+1834/pow(dough,2))*pow(1/(tan(0.5/divide)) ,1.69);
    T cb=0.12+0.13*pow(dough,2);
    if(mach(v,ambiente.speedsound()) )
        Cd=cf+co+cb;
    else
        Cd=cf+cb;
    Cl=0.53*(sin(2*anguloataque)*cos(anguloataque/2))+(tip_length/diameter)* pow(sin(anguloataque),2);
    phi=v*sen(theta)*cos(azimut)/radio_vector ;
    lamnda=v*sen(theta)*sen(azimut)/radio_vector*cos(phi);
}

template<class T>
T Rocket<T> :: push()
{
    return dough*velocityout + A*(pressuergases-ambiente.getpresionbyLm() );
}

template<class T>
T Rocket<T> :: lift()
{
    return 1/2*ambiente.airDensity*pow(v,2)*A*Cl;
}

template<class T>
T Rocket<T>::gravity()
{
    return (G*dough*gravitacional.masa)/pow(radio_vector,2);
}

template<class T>
T Rocket<T>::drag()
{
    return 1/2*ambiente.airDensity*pow(v,2)*A*Cd;
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

