#include "vector.h"
#include <iostream>
using namespace std;
template <typename T>
vector<T>::vector(T xx,T yy,T zz)
    :x(xx),y(yy),z(zz)
{

}
template <typename T>

vector<T> suma(vector<T> vector1, vector<T> vector2)

{

    vector<T> vector3;
    vector3->x= vector1.x+vector2.x;
    vector3->y= vector1.y+vector2.y;
    vector3->z= vector1.z+vector2.z;
    return vector3;

}


template <typename T>
T vector<T>::getX()
{
    return this->x;
}
template <typename T>
T vector<T>::getY()
{
    return this->y;
}
template<typename T>
T vector<T>::getZ()
{
    return this->z;
}
