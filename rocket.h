#ifndef ROCKET_H
#define ROCKET_H
//headers
#include "environment.h"
#include "earth.h"
//#include "datos_iniciales.h"

#include<cmath>
#include<iostream>
#include<vectores.h>
#include<vectores.cpp>
//qt includes
#include <QObject>
#include <QGraphicsPixmapItem>
//defines
#define vson 343
#define G 6.67*pow(10,-11)
#define PI 3.1416

//velocidad del sonido a 343 m/s
/*
 * falta hacer los requerimientos para lograr la posicion de y,z*/
using namespace std;

template <typename T>
class Rocket
{
public:
    Rocket();
    /*tip_length es el largo de la punta esta se usa en el coeficiente de arrastre*/
    Rocket(T &altitud,T & vb, T & latitud,T & longitud,T & dt);
    T drag();//arrastre
    T lift();//sustentacion
    T gravity();
    void position();
    void velocity();
    void acceleration();
    void update_var();//variables necesarias para el movimiento
    void setlatitud_longitud(T & latitud ,T & longitud, T & altitud);
    void get_cdycl();
    T get_velocidad_ascenso();
    ///gets
    T getdough();
    T getheight();
    T getareaall();
    T getarea_nozzle();
    T push();//empuje
    T dif_velocity();
    void movimiento();
    vectores<T> vector_velocity;
    vectores<T> posicion;
    T a;
    T height;
    Environment<T> ambiente ;// en vez de fuerza atmosfera
    T dv;
    T v;
private:
    T latitude;
    T longitude;
    //T dt;
    vectores<T> difvector_velocity;
    T D; // arrastre
    T w;//velocidad angular
    T num_push ;
    T latitudeb;

    Earth<T> mytierra;//T a,T pressureb1,T temperaturab1,T  hb1)

    double q;
    T Cl;//coeficiente de sustentacion
    T Cd;//coeficientes de arrastre

    T pressuergases;
    T velocityout;//es la velocidad que los gases estan saliendo
    T velocitysoun;
    double dt;
    double azimut=53;
    double theta=20;
    double phi;//angulo delatitud
    double lamnda=121 ;//angulo de longitud

////////////////datos iniciales del cohete//////////////////
    double vb;
    double dough=121;
    double doughcarga=343;
    double areaall=5454;
    double area_nozzle=223;//area de la tobera
    double diameter=245;//diametrocohete
    double tip_length=12; //longitu de punta=cono(modelismo)

    double anguloataque=0;

    double A=(diameter*diameter*PI)/4;//reference_surface

    vectores<T> velocidadangulo;
    T r=1;
};



#endif // ROCKET_H
