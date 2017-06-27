#ifndef ROCKET_H
#define ROCKET_H

#include<cmath>
#include<iostream>
#include "environment.h"
#include "earth.h"

#define PI 3.1416
#define G 6.67*pow(10,-11)

#define vson 343
//velocidad del sonido a 343 m/s

using namespace std;

template<class T>
T radio_vector(T antheta,T V)
{
    cout<<"coseno"<<cos(antheta);
    return cos(antheta)*V;
}

template<class T>
bool mach(T v)
{
    if(v/vson>1)
        return true;
    return false;
}

template <typename T>
class Rocket
{
public:
    Rocket();
    Rocket(T &,T &,T &,T &,T&);
    T drag();//arrastre
    T lift();//sustentacion
    T gravity();
    T position();
    T velocity();
    T acceleration();

    ///gets
    T getdough();
    T getheight();
    T getareaall();
    T getarea_nozzle();
private:
    //parametros enfrente de la plaza de armas de arequipa
    //la primer parametro es la densidad de arequipa
    //Environment<T> fuerza ;
    Environment<float> num;
    Environment<T> fuerza ;
    Earth<T> gravitacional ;
    T dough;
    T height;
    T doughcarga;
    T areaall;
    T area_nozzle;//area de la tobera
    T diameter;//diametrocohete
    T tip_length ; //longitu de punta=cono(modelismo)
    T A ;//reference_surface
    T v ;
    T q;
    T Cl;//coeficiente de sustentacion
    T Cd;//coeficientes de resitencia
    T radio_vector;// distancia entre la tierra y el cohete

};



#endif // ROCKET_H
