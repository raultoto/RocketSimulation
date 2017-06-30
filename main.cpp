#include <QApplication>
#include <iostream>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include "rocket.h"
#include "earth.h"
#include "rocket.cpp"
#include "earth.cpp"
#include "environment.h"
#include "environment.cpp"
#include "menu.h"
#include<stdlib.h>
#include<fstream>

#include <QGraphicsScene>

using namespace std;
void open(string namefile)
{   FILE *Arch;
    Arch=fopen(namefile.c_str(),"w");
    fprintf(Arch,"%c;%c \n",namefile[0],namefile[2]);
    fclose(Arch);
}

void Guardar(float l, float p,string namefile)
{   FILE *Arch;
    Arch=fopen(namefile.c_str(),"a+");
    fprintf(Arch,"%f;%f \n",l,p);
    fclose(Arch);
}

QString text;
Menu *menu;
int main(int argc, char *argv[])
{
    /*Otra manera de hacer
    QFile file("file.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Truncate);
    QTextStream text(& file);
    text<<"eofjeo";
    file.close();*/

    QApplication a(argc,argv);
        menu=new Menu();
        menu->show();
        cout<<"Todo se puede de veras";

    double latitud=40.7127837 ,altitud=2335 ,longitud=-74.00594130000002
            ,dlatitud=2,temperatura=20,densidad=123,presion=2000
            ,dtemperatura=10,daltitud=4,ddensidad=1,dpresion=2;
    string primer_file="DxP.csv";
    string segundo_file="AxP.csv";
    string tercer_file="AxD.csv";
    open(primer_file);
    open(segundo_file);
    open(tercer_file);
    for(int i=0;i<20;i++)
    {
        Environment<double> ambiente(densidad,presion,temperatura,dlatitud);
        double densidadnow=ambiente.getdensitybyLm();
        double presionnow=ambiente.getpresionbyLm();
        cout<<"densidad"<<ambiente.getdensitybyLm();
        cout<<"presion"<<ambiente.getpresionbyLm()<<endl;
        Guardar(densidadnow,presionnow,"DxP.csv");
        Guardar(altitud,presionnow,"AxP.csv");
        Guardar(altitud,densidadnow,"AxD.csv");
        densidad+=ddensidad;
        temperatura+=dtemperatura;
        presion+=dpresion;
        altitud+=daltitud;
    }
return a.exec();


}
