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

template<class T>
class Rocket
{
public:
    Rocket();
    float Posicion();
    float Aceleracion();
    float Velocidad();
private:
    float g;
    float masacarga;
    float densidadaire;
    float latitud;
    float longitud;
    float Areatotal;
};
template<class T>
float aceleracion()
{

}

#endif // ROCKET_H
