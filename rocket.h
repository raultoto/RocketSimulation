#ifndef ROCKET_H
#define ROCKET_H

#include<cmath>
#include<iostream>
using namespace std ;
template<class T>
T radio_vector(T antheta,T V)
{
    cout<<"coseno"<<cos(antheta);
    return cos(antheta)*V;
}

template <typename T>
class Rocket
{
public:
    Rocket():masa(0),altura(0){}
    Rocket(T &m,T &a):masa(m),altura(a){}
    T Posicion();
    T Aceleracion();
    T Velocidad();
private:
    T masa;
    T altura;
    T masacarga;
    T densidadaire;
    T latitud;
    T longitud;
    T Areatotal;
};
template<class T>
float aceleracion()
{

}

#endif // ROCKET_H
