#ifndef ROCKET_H
#define ROCKET_H
template <typename T>
class Rocket
{
public:
    Rocket();
    Rocket(T &,T &);
    T position();
    T velocity();
    T acceleration();
private:
    T dough; // masa
    T height;
    T area;
};
#endif // ROCKET_H
