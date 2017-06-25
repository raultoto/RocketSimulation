#ifndef ROCKET_H
#define ROCKET_H
template <typename T>
class Rocket
{
public:
    Rocket();
    Rocket(T &,T &);

private:
    T masa;
    T altura;
};

#endif // ROCKET_H
