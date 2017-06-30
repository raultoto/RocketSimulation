#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <cmath>
using namespace std;
template<typename T>

class vector
{
public:
    vector():x(0),y(0),z(0){}
    vector(T,T,T);
    vector suma(vector,vector);
    vector sum(vector vec1,vector vec2)
    {
        vector tem;
        tem.x=vec1.x+vec2.x;
        tem.y=vec1.y+vec2.y;
        tem.z=vec1.z+vec2.z;
        return tem;
    }
    vector escalar(T a,vector vec)
    {
        vector tem;
        tem.x=a*vec.x;
        tem.y=a*vec.y;
        tem.z=a*vec.z;
    }
    double size()

    {
        return  sqrt(x*x+y*y+z*z);
    }
    vector unitario(vector vec)
    {
        vector tem;
        tem.x=vec.getX()/vec.size();
        tem.y=vec.getY()/vec.size();
        tem.z=vec.getZ()/vec.size();
        return tem;
    }

    T getX();
    T getY();
    T getZ();
    vector operator +(vector vec)
    {
        vector tem;
        tem.x=x+vec.x;
        tem.y=y+vec.y;
        tem.z=z+vec.z;
        return tem;
    }
    vector operator -(vector vec)
    {
        vector tem;
        tem.x=x-vec.x;
        tem.y=y-vec.y;
        tem.z=z-vec.z;
        return tem;
    }
    vector operator *(vector vec)
    {
        vector tem;
        tem.x=x-vec.x;
        tem.y=y-vec.y;
        tem.z=z-vec.z;
        return tem;


    }


    friend ostream& operator << (ostream& output,vector& pt)
    {
        output << "(" << pt.x<< ","<< pt.y << ","<< pt.z<<")" ;

    }
    friend istream& operator >> (istream& input,vector& pt)
    {
        input >> pt.p>> pt.x >> pt.c>> pt.y>>pt.c >> pt.z >>pt.p;
        input.ignore();
        return input;

    }
    void setX(T x);
    void setY(T y);
    void setZ(T z);
private:
    T x,y,z;
    char c=',';
    char p=')';
};

#endif // VECTOR_H
