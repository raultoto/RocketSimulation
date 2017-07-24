#ifndef ROCKET_H
#define ROCKET_H
//headers
#include "environment.h"
#include "earth.h"
#include "datos_iniciales.h"

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
    T push();//empuje
    void position();
    void velocity();
    void aceleration();
    T dif_phi();
    T dif_lamnda();
    T dif_theta();
    T dif_azimut();
    T dif_altitud();
    /////internament calcula la velocidad lo descompone
    /// y lo pone en el vector velocidad
    vectores<T> dif_velocity();

    void update_var();//variables necesarias para el movimiento
    void setlatitud_longitud(T & latitud ,T & longitud, T & altitud,T v1);
    void get_cdycl();
    T get_velocidad_ascenso();
    ///gets
    T getdough();
    T getheight();
    T getareaall();
    T getarea_nozzle();
    T get_phi();
    T get_lamnda();
    T get_tall();
    T get_doughtxetapa();
    T dif_dought();
    vectores<T> vector_velocity;
    vectores<T> posicion;
    T a;
    T height;
    Environment<T> ambiente ;// en vez de fuerza atmosfera
    T dv;
    T v;
    double theta;
     double azimut;
private:
    T latitude;
    T longitude;
    //T dt;
    vectores<T> difvector_velocity;
    T D; // arrastre
    T w;//velocidad angular
    T Push ;//empuje
    T L;//fuerza de sustentacion
    T latitudeb;
    T wr;
    T wphi;
    Earth<T> mytierra;//T a,T pressureb1,T temperaturab1,T  hb1)
    T doughtxetapa;
    double q;
    T Cl;//coeficiente de sustentacion
    T Cd;//coeficientes de arrastre

    T pressuergases;
    T velocityout;//es la velocidad que los gases estan saliendo
    T velocitysoun;
    double dt;


    double phi;//angulo delatitud
    double lamnda;//angulo de longitud

////////////////datos iniciales del cohete//////////////////
    double vb;
    double dough_expel=1.67;
    double velocity_expel=1.2;
    double tall;
    double dough;
    double dough_tobera=20;
    double areaall=5454;
    double area_nozzle=223;//area de la tobera
    double diameter=2;//diametrocohete
    double tip_length=4; //longitu de punta=cono(modelismo)

    double anguloataque=0;//definido por el libro como constante

    double A=(diameter*diameter*PI)/4;//reference_surface

    T r;
};



#endif // ROCKET_H
