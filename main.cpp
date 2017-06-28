#include <iostream>
#include "rocket.h"
#include "earth.h"
#include "rocket.cpp"
#include "earth.cpp"
#include "environment.h"
#include "environment.cpp"
using namespace std;
int main()
{

cout<<"Todo se puede de veras";
Environment<double> ambiente(2000,123,13,2335);
cout<<"la densidad es "<<ambiente.getdensitybyLm();
cout<<"La presion es "<<ambiente.getpresionbyLm();
//Earth<int> numero(2335);
//los dos ultimos son la temperatura de aqui
// el utlimo es la altiud de arequipa
    cout<<"test";
return 0;

}
