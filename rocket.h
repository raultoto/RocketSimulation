#ifndef ROCKET_H
#define ROCKET_H
<<<<<<< HEAD
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
=======
template <typename T>
class Rocket
{
public:
    Rocket():masa(0),altura(0){}
    Rocket(T &m,T &a):masa(m),altura(a){}
private:
    T masa;
    T altura;
>>>>>>> origin/master
};
template<class T>
float aceleracion()
{

}

#endif // ROCKET_H
