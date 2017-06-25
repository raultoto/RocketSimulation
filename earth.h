#ifndef EARTH_H
#define EARTH_H

template<typename T>
class Earth
{
public:
    Earth();
    T getGravity();
    T getRadio();
    T getMasa();
    T getHeight();

private:
    T gravity;
    T radio;
    T masa ;
    T height ;
};

#endif // EARTH_H
