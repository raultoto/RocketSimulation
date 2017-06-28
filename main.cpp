//native includes
#include <QApplication>

//------------------------
#include <iostream>
//.h incldes
#include "rocket.h"
#include "earth.h"
#include "environment.h"
#include "vector.h"
#include "menu.h"
//.cpp  includes
#include "rocket.cpp"
#include "earth.cpp"
#include "environment.cpp"
//#include "vector.cpp"
using namespace std;
Menu *menu;
int main(int argc, char *argv[])
{
    QApplication a(argc,argv);
    menu=new Menu();
    menu->show();
    //menu->displayMainMenu();
    //cout<<"Todo se puede de veras";
    //cout << "jajaja pero no un dia antes de la presentacion" << endl;
    //cout<<"test";
    return a.exec();

}
