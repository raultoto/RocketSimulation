#ifndef VECTORES_H
#define VECTORES_H
#include <iostream>
#include <cmath>
using namespace std;
template<typename T>

class vectores
{
public:
    vectores():x(0),y(0),z(0){}
    vectores(T,T,T);
    vectores suma(vectores vector);
    vectores sum(vectores vec1,vectores vec2)
    {
        vectores<T> tem;
        tem.x=vec1.x+vec2.x;
        tem.y=vec1.y+vec2.y;
        tem.z=vec1.z+vec2.z;
        return tem;
    }
    vectores escalar(T a,vectores vec)
    {
        vectores<T> tem;
        tem.x=a*vec.x;
        tem.y=a*vec.y;
        tem.z=a*vec.z;
        return tem;
    }
    double size()
    {
        return  sqrt(x*x+y*y+z*z);
    }
    vectores unitario(vectores vec)
    {
        vectores tem;
        tem.x=vec.getX()/vec.size();
        tem.y=vec.getY()/vec.size();
        tem.z=vec.getZ()/vec.size();
        return tem;
    }

    T getX();
    T getY();
    T getZ();
    vectores operator +(vectores vec)
    {
        vectores tem;
        tem.x=x+vec.x;
        tem.y=y+vec.y;
        tem.z=z+vec.z;
        return tem;
    }
    vectores operator -(vectores vec)
    {
        vectores tem;
        tem.x=x-vec.x;
        tem.y=y-vec.y;
        tem.z=z-vec.z;
        return tem;
    }
    vectores operator *(vectores vec)
    {
        vectores tem;
        tem.x=x-vec.x;
        tem.y=y-vec.y;
        tem.z=z-vec.z;
        return tem;


    }


    friend ostream& operator << (ostream& output,vectores& pt)
    {
        output << "(" << pt.x<< ","<< pt.y << ","<< pt.z<<")" ;
    }

    friend istream& operator >> (istream& input,vectores& pt)
    {
        input >> pt.p>> pt.x >> pt.c>> pt.y>>pt.c >> pt.z >>pt.p;
        input.ignore();
        return input;

    }
    void setX(T x);
    void setY(T x);
    void setZ(T x);
    /*
    void setX(T x){
     this->x=x;
    }
    void setY(T y){
        this->y=y;
    }

    void setZ(T z){
        this->z=z;
    }
*/
    void producto_vectorial(vectores<T> A,vectores<T> & B);
private:
    T x,y,z;
    char c=',';
    char p=')';
};

#endif // VECTORES_H
