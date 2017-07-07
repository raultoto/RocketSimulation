#include "vectores.h"
#include <iostream>
using namespace std;
template <typename T>
vectores<T>::vectores(T xx,T yy,T zz)
    :x(xx),y(yy),z(zz)
{

}
template <typename T>

vectores<T> suma(vectores<T> vector1, vectores<T> vector2)
{

    vectores<T> vector3;
    vector3->x= vector1.x+vector2.x;
    vector3->y= vector1.y+vector2.y;
    vector3->z= vector1.z+vector2.z;
    return vector3;

}

template<typename T>
void  vectores<T>::producto_vectorial(vectores<T> A,vectores<T> & B)
{
 B.x=A.y*z -A.z*y;
 B.y=A.z*x-A.x*z;
 B.z=A.x*y-A.y*x;
}

template <typename T>
T vectores< T >::getX()
{
    return this->x;
}

template <typename T>
T vectores< T >::getY()
{
    return this->y;
}

template<typename T>
T vectores< T >::getZ()
{
    return this->z;
}

template <typename T>
void vectores< T >::setX(T x)
{
    this->x=x;
}
template <typename T>
void vectores<T>::setY(T y)
{
    this->y =y;
}
template<typename T>
void vectores<T>::setZ(T z)
{
    this->z =z;
}

