#include "environment.h"
template<typename T>
Environment::Environment()
    :airDensity(0),latitude(0),lenght(0)
{

}

template <typename T>
Environment::Environment(T &a, T &l, T &ll)
    :airDensity(a),latitude(l),lenght(ll)
{

}
