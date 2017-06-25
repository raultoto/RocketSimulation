#ifndef ROCKET_H
#define ROCKET_H
template <typename T>
class Rocket
{
public:
    Rocket():masa(0),altura(0){}
    Rocket(T &m,T &a):masa(m),altura(a){}
private:
    T masa;
    T altura;
};

#endif // ROCKET_H
