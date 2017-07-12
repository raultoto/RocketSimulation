#ifndef ROCKET_H
#define ROCKET_H
//headers
#include "environment.h"
#include "earth.h"


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
    /*dimeter =diametro total
      tip_length es el largo de la punta esta se usa en el coeficiente de arrastre*/
    Rocket(T &altitud,T & vb, T & latitud,T & longitud,T & dt);
    T drag();//arrastre
    T lift();//sustentacion
    T gravity();
    T position();
    void velocity();
    void acceleration();
    void update_var();//variables necesarias para el movimiento
    void setlatitud_longitud(T & latitud ,T & longitud, T & altitud );
    void get_cdycl();
    T get_velocidad_ascenso();
    ///gets
    T getdough();
    T getheight();
    T getareaall();
    T getarea_nozzle();
    T push();//empuje
    vectores<T> vector_velocity;
    vectores<T> posicion;
    T a;
    T height;
    Environment<T> ambiente ;// en vez de fuerza atmosfera
private:
    T latitude;
    T longitude;
    T dt;
    T vb=10;

    vectores<T> difvector_velocity;

    T v=28;
    T D=12; // arrastre
    T w=12;//velocidad angular
    T num_push ;
    T latitudeb;

    Earth<T> mytierra;//T a,T pressureb1,T temperaturab1,T  hb1)
    double dough=121;

    double doughcarga=343;
    T areaall=5454;
    T area_nozzle=223;//area de la tobera
    T diameter=1245;//diametrocohete
    T tip_length=12; //longitu de punta=cono(modelismo)
    T A;//reference_surface

    T q;
    T Cl;//coeficiente de sustentacion
    T Cd;//coeficientes de arrastre

    T pressuergases;
    T velocityout;//es la velocidad que los gases estan saliendo
    T velocitysoun;
    T azimut=45;
    T theta=20;
    T phi=121 ;//angulo delatitud
    T lamnda=121 ;//angulo de longitud
    double anguloataque=0;
    vectores<T> velocidadangulo;
    T r=1;
};



#endif // ROCKET_H
